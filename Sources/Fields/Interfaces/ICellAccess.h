#pragma once

template<class TyCell>
class ICellAccess
{
public:
    virtual ~ICellAccess() = default;

    virtual TyCell getCellAt(int x, int y) const = 0;
    inline TyCell getCellAt(Point p) const { return getCellAt(p.X, p.Y); }

    virtual void setCellAt(int x, int y, const SurfaceCell& cell) = 0;
    inline void setCellAt(int x, int y, const SurfaceCell& cell) { setCellAt(p.X, p.Y, cell); }

};

