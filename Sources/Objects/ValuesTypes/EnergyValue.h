#pragma once

enum class EnergyType : unsigned short
{
    Base = 0
    , Chemical
};

class EnergyValue
{
public:
    EnergyValue();
    EnergyValue(int val, EnergyType type = EnergyType::Base);
    EnergyValue(EnergyValue& src);
    ~EnergyValue() = default;

    EnergyValue& operator=(const EnergyValue& src);
    EnergyValue& operator+(const EnergyValue& src);
    EnergyValue& operator-(const EnergyValue& src);

    EnergyValue& operator=(int val);
    EnergyValue& operator+(int val);
    EnergyValue& operator+=(int val);
    EnergyValue& operator-(int val);
    EnergyValue& operator-=(int val);
    EnergyValue& operator/(int val);
    EnergyValue& operator*(int val);

    operator int() const;
    operator float() const;
    operator double() const;

private:
    int Value = 0;
    EnergyType Type = EnergyType::Base;
    
public:


};

/* double EnergyToTemperature(const EnergyValue& energy);
EnergyValue TemperatureToEner(double temp); */

