// JSON输入适配器.h
#include "adapter.hpp"
#include <string>
#include <iostream>
#include <memory>

class JsonInputAdapter : public IInputAdapter {
public:
    std::string adaptInput(const std::string& rawInput) override {
        // 实际实现应解析JSON，并转换为内部命令格式
        // 这里用输出代替
        std::cout << "正在适配JSON输入: " << rawInput << std::endl;
        // 返回适配后的命令字符串
        return "JSON输入值";
    }
};
