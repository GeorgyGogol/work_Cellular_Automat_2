#pragma once

class IExistancePoints
{
public:
    virtual ~IExistancePoints() = default;

public:
    virtual int getExistancePointsMax() const = 0;
    virtual int getExistancePoints() const = 0;
    virtual void addExistancePoints(int delta) = 0;
    inline void removeExistancePoints(int delta) { addExistancePoints(-delta); }
    virtual bool isExists() const = 0;

};

