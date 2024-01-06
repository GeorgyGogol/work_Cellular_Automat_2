#pragma once

#include <vector>
#include <QString>

struct FieldInformation
{
    int Height = 0;
    int Width = 0;
    int Type = -1;

    int ID = -1;
    QString Name = QString();
};

typedef std::vector<FieldInformation> FieldList;

