// 动力系统.h
#ifndef  SPECIFIC_ADAPTER_H_
#define  SPECIFIC_ADAPTER_H_
#include "system.hpp"
#include <iostream>
//动力系统
class PowerSystem : public ISystem {
public:
    void executeCommand(const std::string& command) override {
        // 实际实现用输出代替
        std::cout << "动力系统执行命令: " << command << std::endl;
    }

    void diagnostics() const override {
        std::cout << "动力系统诊断: 正常" << std::endl;
    }
};

// 转向系统
class SteeringSystem : public ISystem {
public:
    void executeCommand(const std::string& command) override {
        std::cout << "转向系统执行命令: " << command << std::endl;
    }

    void diagnostics() const override {
        std::cout << "转向系统诊断: 正常" << std::endl;
    }
};

// 安全系统

class SafetySystem : public ISystem {
public:
    void executeCommand(const std::string& command) override {
        std::cout << "安全系统执行命令: " << command << std::endl;
    }

    void diagnostics() const override {
        std::cout << "安全系统诊断: 正常" << std::endl;
    }
};
#endif