#ifndef  INPUT_H_
#define  INPUT_H_
#include<iostream>

struct Command {
    std::string action;
    float value;
};

// 输入处理器接口
class IInputHandler {
public:
    virtual ~IInputHandler() = default;
    virtual Command parse(const std::string& input) = 0;
};

// 键盘输入处理器
class KeyboardInputHandler : public IInputHandler {
public:
    Command parse(const std::string& input) override {
        // 解析键盘输入，例如："power 75" 或 "turn -30"
        Command cmd{"", 0.0f};
        size_t pos = input.find(' ');
        if (pos != std::string::npos) {
            cmd.action = input.substr(0, pos);
            cmd.value = std::stof(input.substr(pos + 1));
        } else {
            cmd.action = input;
        }
        std::cout << "[键盘] 解析命令: " << cmd.action 
                  << "(" << cmd.value << ")\n";
        return cmd;
    }
};

// 网络输入处理器
class NetworkInputHandler : public IInputHandler {
public:
    Command parse(const std::string& input) override {
        // 解析JSON格式网络输入，例如：{"command":"brake", "value":0.8}
        Command cmd{"", 0.0f};
        // 简化的JSON解析逻辑
        if (input.find("power") != std::string::npos) {
            cmd.action = "set_power";
            size_t pos = input.find("value");
            if (pos != std::string::npos) 
                cmd.value = std::stof(input.substr(pos + 7));
        }
        std::cout << "[网络] 解析命令: " << cmd.action 
                  << "(" << cmd.value << ")\n";
        return cmd;
    }
};


#endif