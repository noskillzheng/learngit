#include <vehicle.hpp>
#include <system_factory.hpp>
#include <specific_adapter.hpp>

int main() {
    // 创建工厂
    DefaultSystemFactory factory;

    // 创建各个系统
    auto power = factory.createPowerSystem();
    auto steering = factory.createSteeringSystem();
    auto safety = factory.createSafetySystem();

    // 创建车辆
    Vehicle car(std::move(power), std::move(steering), std::move(safety));

    // 创建输入适配器
    JsonInputAdapter adapter;

    // 模拟外部输入
    std::string rawInput = R"({"command": "accelerate", "value: 50"})";
    std::string adaptedCommand = adapter.adaptInput(rawInput);

    // 车辆执行命令
    car.runCommand(adaptedCommand);

    // 运行诊断
    car.runDiagnostics();

    return 0;
}
