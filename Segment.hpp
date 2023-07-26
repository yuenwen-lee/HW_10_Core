//
//  Segment.hpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/31/20.
//

#ifndef Segment_hpp
#define Segment_hpp

#include <cstdint>
#include <cassert>


class Segment {

public:
    int32_t p0;   // point n within the segment,
    int32_t p1;   // {n: p0 <= n && n <= p1}

    Segment() {
        p0 = 0;
        p1 = 1;
    }
    Segment(int32_t p0, int32_t p1) {
        this->p0 = p0;
        this->p1 = p1;
        valid();
    }
    Segment(Segment &src) {
        this->p0 = src.p0;
        this->p1 = src.p1;
    }

    void set(int32_t p0, int32_t p1);
    void set(Segment &seg);
    bool equal_to(Segment &sb);
    void shift(int32_t offset);
    void reset(void);
    uint32_t len(void);
    void dump(void);

    void valid(void) {
        assert(p0 <= p1);
    }
};

bool seg_overlap_check(Segment &sa, Segment &sb);
bool seg_overlap(Segment &sa, Segment &sb, Segment &ov);
bool seg_collide(Segment &sa, int32_t speed_a, Segment &sb, int32_t speed_b, Segment &time);

static inline int32_t floor_div(int32_t val, int32_t div)
{
    assert(div);
    if (div < 0) {
        val = -val;
        div = -div;
    }

    if (val >= 0) {
        return val / div;
    } else {
        return (val - div + 1) / div;
    }
}

static inline int32_t ceil_div(int32_t val, int32_t div)
{
    assert(div);
    if (div < 0) {
        val = -val;
        div = -div;
    }

    if (val >= 0) {
        return (val + div - 1)/ div;
    } else {
        return val / div;
    }
}

void Segment_test(void);


#endif /* Segment_hpp */
