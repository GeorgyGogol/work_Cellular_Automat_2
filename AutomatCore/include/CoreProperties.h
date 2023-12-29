#pragma once

#include <vector>
#include <QString>

namespace automat {
    class Automat;
    class AbstractField;
}

struct FieldInformation
{
    int Height = 0;
    int Width = 0;
    int Type = -1;

    int ID = -1;
    QString Name = QString();
};

//QString TypeMapToString(int type)
//{
//    QString out = "Not defined";
//    switch (type) {
//    case 0:
//        out = "TestField";
//        break;
//
//    }
//    return out;
//}

typedef std::vector<FieldInformation> FieldList;
