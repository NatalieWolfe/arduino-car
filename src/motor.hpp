
#pragma once

#include "./output.hpp"

class Motor {
public:
    Motor(){}

    void attach(const int speed_pin, const int control_pin1, const int control_pin2){
        m_control1.attach(control_pin1);
        m_control2.attach(control_pin2);
        m_speed.attach(speed_pin);
    }

    void run(const int speed){
        int constrained_speed = constrain(speed, -255, 255);

        // Kill the circuit before adjusting.
        m_speed.off();

        // What direction are things going?
        if (constrained_speed > 0) {
            m_control1.on();
            m_control2.off();
        }
        else {
            m_control1.off();
            m_control2.on();
            constrained_speed = -constrained_speed; // Make speed positive.
        }

        // Open it up again.
        m_speed.write(constrained_speed);
    }

    void brake(){
        m_speed.off();
        m_control1.off();
        m_control2.off();
        m_speed.on();
    }

private:
    OutputPin m_control1;
    OutputPin m_control2;
    AnalogOutput m_speed;
};
