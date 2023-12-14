#pragma once

struct CoreFieldProperties
{
    int Height;
    int Width;

    enum FieldTypes
    {
        TestField = 0,
        Default = TestField
    } Type = FieldTypes::Default;
};

