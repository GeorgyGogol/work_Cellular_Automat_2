#pragma once

#include <ostream>

class RangedValue;
class EnergyValue;
class Object;
class LiveObject;

std::ostream& operator<<(std::ostream& stream, const RangedValue& src);
std::ostream& operator<<(std::ostream& stream, const EnergyValue& src);
std::ostream& operator<<(std::ostream& stream, const Object& src);
std::ostream& operator<<(std::ostream& stream, const LiveObject& src);

