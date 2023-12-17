#pragma once

#include <vector>

namespace automat {
    class Automat;
    class AbstractField;
    //class SimpleSquareTestField;
}

struct FieldInformation
{
    int Height = 0;
    int Width = 0;
    int Type = -1;

    int ID = -1;
};

typedef std::vector<FieldInformation> FieldList;
