#pragma once
#include <memory>
#include "Fan.hpp"
#include "IThermometer.hpp"

constexpr int maxSpeed = 3000;
constexpr int disabledSpeed = 0;

class LcdDisplay;

class Controller {
    IThermometer& thermometer_;
    Fan& fan;

public:
    Controller(IThermometer& t, Fan& f, double, double, std::shared_ptr<LcdDisplay>);
    void updateRpm();
    void displayInfo();
};
