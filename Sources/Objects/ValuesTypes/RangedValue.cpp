#include "RangedValue.h"

RangedValue::RangedValue()
    : Value(0), MaxValue(0)
{
}

RangedValue::RangedValue(int value)
    : Value(value), MaxValue(value)
{
}

RangedValue::RangedValue(int value, int max_value)
    : Value(value), MaxValue(max_value) 
{
}

RangedValue::RangedValue(int max_value, bool is_full)
    : MaxValue(max_value)
{
    if (is_full) Value = MaxValue;
}

RangedValue::RangedValue(const RangedValue& src) noexcept {
    Value = src.Value;
    MaxValue = src.MaxValue;
}

#pragma region Operators RangedValue
RangedValue& RangedValue::operator=(const RangedValue& src)
{
    if (&src != this) {
        Value = src.Value;
        MaxValue = src.MaxValue;
    }
    return *this;
}

RangedValue& RangedValue::operator+(const RangedValue& delta) {
    if (&delta != this) {
        addValue(delta.Value);
    }
    return *this;
}

RangedValue& RangedValue::operator-(const RangedValue& delta) {
    if (&delta != this) {
        remValue(delta.Value);
    }
    return *this;
}
#pragma endregion // Операторы TyPoints

#pragma region Operators int
RangedValue& RangedValue::operator=(int value) {
    if (value > 0) {
        Value = value;
        if (MaxValue == 0) MaxValue = value;
        else if (Value > MaxValue) Value = MaxValue;
    }
    return *this;
}

RangedValue& RangedValue::operator+(int delta) {
    addValue(delta);
    return *this;
}

RangedValue& RangedValue::operator+=(int delta) {
    addValue(delta);
    return *this;
}

RangedValue& RangedValue::operator-(int delta) {
    remValue(delta);
    return *this;
}

RangedValue& RangedValue::operator-=(int delta) {
    remValue(delta);
    return *this;
}
#pragma endregion // Операторы int

#pragma region Operators cast
RangedValue::operator int() const { 
    return Value; 
}
#pragma endregion // Операторы приведения

void RangedValue::setMaxValue(int m_value) {
    if (m_value <= 0) return;
    MaxValue = m_value;
    if (Value > MaxValue) Value = MaxValue;
}

int RangedValue::getMaxValue() const noexcept { 
    return MaxValue; 
}

void RangedValue::increaceMax(int delta)
{
    if (MaxValue + delta <= 0) return;
    MaxValue += delta;
    if (Value > MaxValue) Value = MaxValue;
}

void RangedValue::addValue(int val) {
    Value = Value + val;
    if (Value > MaxValue) Value = MaxValue;
    else if (Value < 0) Value = 0;
}

int RangedValue::getValue() const { 
    return Value;
}

void RangedValue::setEmpty()
{
    Value = 0;
}

bool RangedValue::isFull() const noexcept
{
    return Value >= MaxValue;
}

