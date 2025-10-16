// 车辆.h
#include "specific_system.hpp"
#include <vector>
#include <memory>

class Vehicle {
public:
    Vehicle(std::unique_ptr<ISystem> power, 
            std::unique_ptr<ISystem> steering, 
            std::unique_ptr<ISystem> safety)
        : powerSystem(std::move(power)), 
          steeringSystem(std::move(steering)), 
          safetySystem(std::move(safety)) {}

    void runCommand(const std::string& adaptedCommand) {

        powerSystem->executeCommand(adaptedCommand);
        steeringSystem->executeCommand(adaptedCommand);
        safetySystem->executeCommand(adaptedCommand);
    }

    void runDiagnostics() const {
        powerSystem->diagnostics();
        steeringSystem->diagnostics();
        safetySystem->diagnostics();
    }

private:
    std::unique_ptr<ISystem> powerSystem;
    std::unique_ptr<ISystem> steeringSystem;
    std::unique_ptr<ISystem> safetySystem;
};
