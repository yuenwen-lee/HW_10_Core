//
//  Segment.cpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/31/20.
//

#include <cstdio>
#include "Segment.hpp"


void Segment::set(Segment &seg)
{
    p0 = seg.p0;
    p1 = seg.p1;
    valid();
}

void Segment::set(int32_t p0, int32_t p1)
{
    this->p0 = p0;
    this->p1 = p1;
    valid();
}

bool Segment::equal_to(Segment &sb)
{
    if (p0 == sb.p0 && p1 == sb.p1) {
        return true;
    } else {
        return false;
    }
}

void Segment::shift(int32_t offset)
{
    p0 += offset;
    p1 += offset;
    valid();
}

void Segment::reset(void)
{
    p1 -= p0;
    p0 = 0;
    valid();
}

uint32_t Segment::len(void)
{
    return p1 - p0;
}

void Segment::dump(void)
{
    printf("[%d, %d]", p0, p1);
}


bool seg_overlap_check(Segment &sa, Segment &sb)
{
    if (sa.p1 <= sb.p0 || sb.p1 <= sa.p0) {
        return false;
    } else {
        return true;
    }
}

bool seg_overlap(Segment &sa, Segment &sb, Segment &ov)
{
    if (seg_overlap_check(sa, sb) == false) {
        return false;

    } else {
        int32_t p0 = (sa.p0 < sb.p0) ? sb.p0 : sa.p0;
        int32_t p1 = (sa.p1 < sb.p1) ? sa.p1 : sb.p1;
        ov.set(p0, p1);
        return true;
    }
}

bool seg_collide(Segment &sa, int32_t speed_a,
                 Segment &sb, int32_t speed_b, Segment &time)
{
    if (speed_a == speed_b) {
        // both segments are relative stationary
        if (seg_overlap_check(sa, sb)) {
            time.set(INT32_MIN, INT32_MAX);
            return true;
        } else {
            time.set(INT32_MAX - 1, INT32_MAX);
            return false;
        }
    }

    int32_t d0, d1;
    int32_t speed;
    if (speed_a > speed_b) {
        speed = speed_a - speed_b;
        d0 = sb.p0 - sa.p1;
        d1 = sb.p1 - sa.p0;
    } else {
        speed = speed_b - speed_a;
        d0 = sa.p0 - sb.p1;
        d1 = sa.p1 - sb.p0;
    }

    if (d0 > d1) {
        int32_t tmp = d1;
        d1 = d0;
        d0 = tmp;
    }

    int32_t t0 = floor_div(d0, speed);
    int32_t t1 = ceil_div(d1, speed);
    time.set(t0, t1);
    return true;;
}
