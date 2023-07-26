//
//  Rectangle.cpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/31/20.
//

#include <cstdio>
#include "Vec2D.hpp"
#include "Rectangle.hpp"


void Rectangle::set(int32_t x0, int32_t x1, int32_t y0, int32_t y1)
{
    seg_x.set(x0, x1);
    seg_y.set(y0, y1);
}

void Rectangle::set(Segment &x, Segment &y)
{
    seg_x.set(x);
    seg_y.set(y);
}

void Rectangle::set(Rectangle &src)
{
    seg_x.set(src.seg_x);
    seg_y.set(src.seg_y);
}

void Rectangle::shift(Vec2D &dist)
{
    seg_x.shift(dist.x);
    seg_y.shift(dist.y);
}

void Rectangle::reset(void)
{
    seg_x.reset();
    seg_y.reset();
}

void Rectangle::dump(void)
{
    printf("x "); seg_x.dump(); printf(", "); printf("y "); seg_y.dump();
}

bool rec_overlap_check(Rectangle &rec0, Rectangle &rec1)
{
    return (seg_overlap_check(rec0.seg_x, rec1.seg_x) &&
            seg_overlap_check(rec0.seg_y, rec1.seg_y));
}

bool rec_overlap(Rectangle &rec0, Rectangle &rec1, Rectangle &rec_ov)
{
    bool ov_x = seg_overlap(rec0.seg_x, rec1.seg_x, rec_ov.seg_x);
    bool ov_y = seg_overlap(rec0.seg_y, rec1.seg_y, rec_ov.seg_y);
    return (ov_x && ov_y);
}

bool rec_collide(Rectangle &rec0, Vec2D &vec0, Rectangle &rec1, Vec2D &vec1,
                 Segment &time)
{
    Segment tm_x, tm_y;
    bool cld_x, cld_y;

    cld_x = seg_collide(rec0.seg_x, vec0.x, rec1.seg_x, vec1.x, tm_x);
    cld_y = seg_collide(rec0.seg_y, vec0.y, rec1.seg_y, vec1.y, tm_y);
    if (cld_x == false || cld_y == false) {
        return false;
    } else {
        return seg_overlap(tm_x, tm_y, time);
    }
}
