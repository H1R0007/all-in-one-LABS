#include <iostream>
#include <memory>
#include <vector>
#include <string>

// �����, �������������� ����� ������ (������ ������������)
class ConfigData {
public:
    ConfigData(const std::string& appName, int version)
        : appName(appName), version(version) {
        std::cout << "ConfigData created (" << appName << ", v" << version << ")\n";
    }

    ~ConfigData() {
        std::cout << "ConfigData destroyed (" << appName << ", v" << version << ")\n";
    }

    void print() const {
        std::cout << "Config: " << appName << " (v" << version << ")\n";
    }

    void updateVersion(int newVersion) {
        version = newVersion;
        std::cout << "Version updated to " << newVersion << "\n";
    }

private:
    std::string appName;
    int version;
};

// �����, ������������ ����� ������
class Service {
public:
    Service(std::shared_ptr<ConfigData> config, const std::string& name)
        : config(config), name(name) {
        std::cout << "Service '" << name << "' created\n";
    }

    ~Service() {
        std::cout << "Service '" << name << "' destroyed\n";
    }

    void useConfig() {
        std::cout << "Service '" << name << "' using config: ";
        config->print();
    }

    void updateConfig(int newVersion) {
        std::cout << "Service '" << name << "' updating config\n";
        config->updateVersion(newVersion);
    }

private:
    std::shared_ptr<ConfigData> config;
    std::string name;
};

int main() {
    // ������� ����� ������ (������ ������������)
    auto sharedConfig = std::make_shared<ConfigData>("MyApp", 1);

    std::cout << "\nInitial use count: " << sharedConfig.use_count() << "\n\n";

    // ������� ��������� ��������, ������������ ���� ������
    Service service1(sharedConfig, "AutoService");
    Service service2(sharedConfig, "DataService");
    Service service3(sharedConfig, "LogService");

    std::cout << "\nUse count after creating services: " << sharedConfig.use_count() << "\n\n";

    // ���������� ������ �� ������ ��������
    service1.useConfig();
    service2.useConfig();
    service3.useConfig();

    // ���� �� �������� ��������� ������
    service2.updateConfig(2);

    // ���������, ��� ��������� ����� ����
    std::cout << "\nAfter update:\n";
    service1.useConfig();
    service3.useConfig();

    std::cout << "\nUse count before scope end: " << sharedConfig.use_count() << "\n\n";

};