#include "Controller.hpp"
#include "StubThermometer.hpp"
#include "external/catch.hpp"
#include "external/hippomocks.h"

SCENARIO("Controller can control Fan") {
    GIVEN("Controller, Thermometer, Fan, target temperature = 36.6, tolerance = 0.5") {
        StubThermometer thermometer;
        Fan fan;
        double targetTemperature = 36.6;
        double tolerance = .5;
        Controller cut{thermometer, fan, targetTemperature, tolerance, nullptr};

        WHEN("Temperature drops below 0 and updateRpm is called") {
            thermometer.temperature = -1.0;
            cut.updateRpm();

            THEN("Fan should be disabled") {
                REQUIRE(fan.getSpeed() == disabledSpeed);
            }
        }

        WHEN("Temperature raise above 100 and updateRpm is called") {
            thermometer.temperature = 101.0;
            cut.updateRpm();

            THEN("Fan should be set to max speed = 3000") {
                REQUIRE(fan.getSpeed() == maxSpeed);
            }
        }
    }
}
