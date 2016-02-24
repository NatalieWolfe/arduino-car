
#pragma once

class OutputPin {
public:
    void attach(const int pin){
        m_pin = pin;
        pinMode(pin, OUTPUT);
    }

    int pin() const {
        return m_pin;
    }

    void on(){
        digitalWrite(pin(), HIGH);
    }

    void off(){
        digitalWrite(pin(), LOW);
    }

private:
    int m_pin;
};

class AnalogOutput : public OutputPin {
public:
    AnalogOutput(const int min, const int max):
        m_min{min},
        m_max{max}
    {}

    AnalogOutput():
        AnalogOutput{0, 255}
    {}

    void write(const int value){
        analogWrite(pin(), constrain(map(value, m_min, m_max, 0, 255), 0, 255));
    }

private:
    int m_min;
    int m_max;
};
