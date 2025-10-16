// 输入适配器.h
#ifndef ADAPTER_H_
#define ADAPTER_H_
#include <iostream>
class IInputAdapter {
public:
    virtual ~IInputAdapter() = default;
    virtual std::string adaptInput(const std::string& rawInput) = 0;
};

#endif