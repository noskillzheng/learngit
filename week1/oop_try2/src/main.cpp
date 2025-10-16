#include<iostream>
#include<input.hpp>
#include<system.hpp>
int main() {
    // 创建车辆实例（不使用工厂模式）
    Vehicle car;
    
    // 添加系统组件
    car.addSystem(new MotorSystem());
    car.addSystem(new SteeringSystem());
    car.addSystem(new SafetySystem());
    
    // 设置初始输入处理器
    car.setInputHandler(new KeyboardInputHandler());
    
    // 处理输入
    car.processInput("set_power 75");
    car.processInput("turn -15");
    
    // 更换输入方案（演示动态切换）
    car.setInputHandler(new NetworkInputHandler());
    car.processInput(R"({"command":"emergency", "value":1})");
    
    // 系统更新循环
    car.updateSystems();
    
    return 0;
}