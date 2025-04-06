#include <iostream>
#include <memory>
#include <unordered_map>
#include <string>

class Resource {
public:
    Resource(const std::string& name) : name(name) {
        std::cout << "Resource '" << name << "' created\n";
    }

    ~Resource() {
        std::cout << "Resource '" << name << "' destroyed\n";
    }

    void use() const {
        std::cout << "Using resource '" << name << "'\n";
    }

    std::string getName() const { return name; }

private:
    std::string name;
};

class ResourceCache {
public:
    void addResource(std::shared_ptr<Resource> res) {
        cache[res->getName()] = res;
    }

    std::shared_ptr<Resource> getResource(const std::string& name) {
        auto it = cache.find(name);
        if (it != cache.end()) {
            if (auto res = it->second.lock()) {
                std::cout << "Resource '" << name << "' found in cache\n";
                return res;
            }
            cache.erase(it);
        }
        return nullptr;
    }

    void printCacheStatus() const {
        std::cout << "Cache contents:\n";
        for (const auto& pair : cache) {
            std::cout << " - " << pair.first << ": ";
            if (pair.second.expired()) {
                std::cout << "EXPIRED\n";
            }
            else {
                std::cout << "ALIVE\n";
            }
        }
    }

private:
    std::unordered_map<std::string, std::weak_ptr<Resource>> cache;
};

int main() {
    ResourceCache cache;

    // Создаем ресурс и добавляем в кэш
    {
        std::cout << "--- Creating resource ---\n";
        auto res = std::make_shared<Resource>("texture1");
        cache.addResource(res);
        cache.printCacheStatus();

        // Получаем ресурс из кэша
        std::cout << "\n--- Accessing resource ---\n";
        if (auto cached = cache.getResource("texture1")) {
            cached->use();
        }
    }

    // Проверяем кэш после удаления ресурса
    std::cout << "\n--- After resource destruction ---\n";
    cache.printCacheStatus();

    // Попытка получить удаленный ресурс
    std::cout << "\n--- Trying to access expired resource ---\n";
    if (auto cached = cache.getResource("texture1")) {
        cached->use();
    }
    else {
        std::cout << "Resource 'texture1' no longer exists\n";
    }

    return 0;
}