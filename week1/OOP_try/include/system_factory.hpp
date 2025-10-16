// 系统工厂.h
#include "specific_system.hpp"
#include <memory>


class ISystemFactory {
public:
    virtual ~ISystemFactory() = default;
    virtual std::unique_ptr<ISystem> createPowerSystem() = 0;
    virtual std::unique_ptr<ISystem> createSteeringSystem() = 0;
    virtual std::unique_ptr<ISystem> createSafetySystem() = 0;
};

// 具体工厂实现
class DefaultSystemFactory : public ISystemFactory {
public:
    std::unique_ptr<ISystem> createPowerSystem() override {
        return std::make_unique<PowerSystem>();
    }

    std::unique_ptr<ISystem> createSteeringSystem() override {
        return std::make_unique<SteeringSystem>();
    }

    std::unique_ptr<ISystem> createSafetySystem() override {
        return std::make_unique<SafetySystem>();
    }
};
