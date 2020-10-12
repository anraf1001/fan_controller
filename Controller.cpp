#include "Controller.hpp"

Controller::Controller(IThermometer& t,
                       Fan& f,
                       double,
                       double,
                       std::shared_ptr<LcdDisplay>)
    : thermometer_(t), fan(f) {}

void Controller::updateRpm() {
    if (thermometer_.getTemperature() < 0) {
        fan.setSpeed(disabledSpeed);
    } else {
        fan.setSpeed(maxSpeed);
    }
}

void Controller::displayInfo() {}
