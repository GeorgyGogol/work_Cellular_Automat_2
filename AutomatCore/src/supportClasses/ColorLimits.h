#pragma once

class ColorLimits
{
public:
    ColorLimits() = default;
    ColorLimits(int min, int max);
    ~ColorLimits() = default;

private:
    int Lower = 0;
    int Higher = 255;

public:
    inline int min() const { return Lower; }
    inline int max() const { return Higher; }
    inline int getLength() const { return Higher - Lower; }

    static const int MaximumHigh = 255;

};

