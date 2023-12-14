#include "stdafx.h"
#include "ObjectsStreams.h"

#include "RangedValue.h"
#include "EnergyValue.h"
#include "Object.h"
#include "LiveObject.h"

std::ostream& operator<<(std::ostream& stream, const RangedValue& src) {
    stream << src.getValue() << ":" << src.getMaxValue();
    return stream;
}

