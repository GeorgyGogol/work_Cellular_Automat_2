#pragma once

class SceneSettings
{
public:
    SceneSettings();
    ~SceneSettings() = default;

public:
    int TypeField;
    bool PrintBorder = true;

    inline void resetTypeField() { TypeField = -1; }
};

