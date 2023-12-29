#pragma once

#include <vector>

namespace automat {
    class Automat;
    class AbstractField;
}

typedef int FieldID;

struct FieldInformation
{
    int Height = 0;
    int Width = 0;
    int Type = -1;

    FieldID ID = -1;
};

typedef std::vector<FieldInformation> FieldList;
