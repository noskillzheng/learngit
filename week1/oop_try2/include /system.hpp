#ifndef  SYSTEM_H_
#define  SYSTEM_H_

#include <iostream>

extern struct Command;

class IVehicleSystem {
public:
    virtual ~IVehicleSystem() = default;
    virtual void initialize() = 0;
    virtual void update() = 0;
    virtual void executeCommand(const Command& cmd) = 0;
};

class MotorSystem : public IVehicleSystem {
    float powerLevel = 0.0f;
public:
    void initialize() override {
        std::cout << "动力系统初始化完成\n";
    }
    
    void update() override {
        // 每帧更新逻辑
        std::cout << "动力系统更新，当前功率: " 
                  << powerLevel << "%\n";
    }
    
    void executeCommand(const Command& cmd) override {
        if (cmd.action == "set_power") {
            powerLevel = cmd.value;
            std::cout << "设置功率: " << powerLevel << "%\n";
        }
    }
};

// 转向系统实现
class SteeringSystem : public IVehicleSystem {
    float steeringAngle = 0.0f;
public:
    void initialize() override {
        std::cout << "转向系统初始化完成\n";
    }
    
    void update() override {
        // 每帧更新逻辑
        std::cout << "转向系统更新，当前角度: " 
                  << steeringAngle << "度\n";
    }
    
    void executeCommand(const Command& cmd) override {
        if (cmd.action == "turn") {
            steeringAngle = cmd.value;
            std::cout << "转向角度: " << steeringAngle << "度\n";
        }
    }
};

// 安全系统实现
class SafetySystem : public IVehicleSystem {
public:
    void initialize() override {
        std::cout << "安全系统初始化完成\n";
    }
    
    void update() override {
        // 每帧安全检测
        std::cout << "安全系统自检... OK\n";
    }
    
    void executeCommand(const Command& cmd) override {
        if (cmd.action == "emergency") {
            std::cout << "! 紧急刹车激活 !\n";
        }
    }
};
#endif