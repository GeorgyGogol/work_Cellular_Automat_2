#pragma once

class RangedValue
{
public:
    RangedValue();
    RangedValue(int value);
    RangedValue(int value, int max_value);
    RangedValue(int max_value, bool is_full);

    RangedValue(const RangedValue& src) noexcept;

    RangedValue& operator=(const RangedValue& src);
    RangedValue& operator+(const RangedValue& delta);
    RangedValue& operator-(const RangedValue& delta);

    RangedValue& operator=(int value);
    RangedValue& operator+(int delta);
    RangedValue& operator+=(int delta);
    RangedValue& operator-(int delta);
    RangedValue& operator-=(int delta);

    operator int() const;

private:
    int Value = 0;
    int MaxValue = 0;

protected:

public:
    void setMaxValue(int m_value);
    int getMaxValue() const noexcept;
    void increaceMax(int delta);
    inline void decraceMax(int delta) { increaceMax(-delta); }

    void addValue(int val);
    inline void remValue(int val) { addValue(-val); }
    int getValue() const;
    void setEmpty();

    bool isFull() const noexcept;
    inline bool isEmpty() const noexcept { return !isFull(); }

};


