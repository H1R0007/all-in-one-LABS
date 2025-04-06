#include <iostream>
#include <fstream>
#include <stdexcept>
#include <crtdbg.h>

class FileHandler {
public:
    explicit FileHandler(const std::string& filename) : file(std::make_unique<std::ofstream>(filename)) { 
        if (!file->is_open()) {
            throw std::runtime_error("Failed to open the file");
        }
        std::cout << "File opened successfully." << std::endl;
    }

    ~FileHandler() {
        file->close();
        std::cout << "File closed." << std::endl;
    }

    void writeData(const std::string& data) {
        *file << data;
    }

private:
    std::unique_ptr<std::ofstream> file;
};

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    try {
        // Тест 1: Корректное открытие и запись в файл
        {
            FileHandler fh("test.txt");
            fh.writeData("Hello!\n");
            fh.writeData("This is a test file\n");
        }

        // Тест 2: Попытка открыть несуществующий/закрытый файл (должно выбросить исключение)
        try {
            FileHandler invalid_fh("nonexistent_folder/test.txt");
        }
        catch (const std::exception& e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }

        // Тест 3: Проверка, что файл действительно записался
        std::ifstream check_file("test.txt");
        if (check_file.is_open()) {
            std::cout << "\nFile content:\n";
            std::cout << check_file.rdbuf();  // Выводим содержимое файла
            check_file.close();
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}