#include "EnergyValue.h"

EnergyValue::EnergyValue()
{
}

EnergyValue::EnergyValue(int val, EnergyType type)
    : Value(val)
    , Type(type)
{
}

EnergyValue::EnergyValue(EnergyValue &src)
{
    Value = src.Value;
    Type = src.Type;
}

EnergyValue& EnergyValue::operator=(const EnergyValue& src)
{
    if (this != &src)
    {
        Value = src.Value;
        Type = src.Type;
    }
    return *this;
}

EnergyValue& EnergyValue::operator+(const EnergyValue& src)
{
    if (src.Type == Type){
        Value += src.Value;
    }
    return *this;
}

EnergyValue& EnergyValue::operator-(const EnergyValue& src)
{
    if (src.Type == Type){
        Value -= src.Value;
    }
    return *this;
}

EnergyValue& EnergyValue::operator=(int val)
{
    Value = val;
    return *this;
}

EnergyValue& EnergyValue::operator+(int val)
{
    Value += val;
    return *this;
}

EnergyValue& EnergyValue::operator+=(int val)
{
    Value += val;
    return *this;
}

EnergyValue& EnergyValue::operator-(int val)
{
    Value -= val;
    return *this;
}

EnergyValue& EnergyValue::operator-=(int val)
{
    Value -= val;
    return *this;
}

EnergyValue& EnergyValue::operator/(int val)
{
    Value = int(1.0 * Value / val);
    return *this;
}

EnergyValue& EnergyValue::operator*(int val)
{
    Value *= val;
    return *this;
}

EnergyValue::operator int() const
{
    return int(Value);
}

EnergyValue::operator float() const
{
    return float(Value);
}

EnergyValue::operator double() const
{
    return double(Value);
}

