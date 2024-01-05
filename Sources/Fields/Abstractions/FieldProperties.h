#pragma once

#include <string>

namespace automat {

    class FieldProperties
    {
    public:
        int Height;
        int Width;

        enum FieldTypes
        {
            TestField = 0,
            Default = TestField
        } Type = FieldTypes::Default;

        int ID = -1;
        std::string MapName;
    };

}

