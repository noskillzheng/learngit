#include<iostream>
#include"input.hpp"
#include"system.hpp"
#include <vector>
#include <string>
#include <unordered_map>

extern struct Command;

class Vehicle {
    std::vector<IVehicleSystem*> systems;
    IInputHandler* inputHandler = nullptr;
    
public:
    ~Vehicle() {
        for (auto system : systems) delete system;
        delete inputHandler;
    }
    
    // 添加系统组件
    void addSystem(IVehicleSystem* system) {
        systems.push_back(system);
    }
    
    // 设置输入处理器
    void setInputHandler(IInputHandler* handler) {
        if (inputHandler) delete inputHandler;
        inputHandler = handler;
    }
    
    // 处理外部输入
    void processInput(const std::string& rawInput) {
        if (!inputHandler) {
            std::cerr << "错误：未设置输入处理器\n";
            return;
        }
        
        Command cmd = inputHandler->parse(rawInput);
        
        // 分发命令到所有系统
        for (auto system : systems) {
            system->executeCommand(cmd);
        }
    }
    
    // 更新所有系统
    void updateSystems() {
        for (auto system : systems) {
            system->update();
        }
    }
};