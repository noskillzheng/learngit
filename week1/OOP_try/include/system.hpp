// 系统接口.h
#ifndef  SYSTEM_H_
#define  SYSTEM_H_

#include<iostream>

class ISystem {
public:
    virtual ~ISystem() = default;
    virtual void executeCommand(const std::string& command) = 0;
    virtual void diagnostics() const = 0;
};
#endif