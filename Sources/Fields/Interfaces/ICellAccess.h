#pragma once

template<class TyCell>
class ICellAccess
{
public:
    virtual ~ICellAccess() = default;

    virtual TyCell* getCellAt(int x, int y) const = 0;
    inline TyCell* getCellAt(Point p) const { return getCellAt(p.X, p.Y); }

    virtual void setCellAt(int x, int y, const TyCell& cell) = 0;
    inline void setCellAt(Point p, const TyCell& cell) { setCellAt(p.X, p.Y, cell); }

};

