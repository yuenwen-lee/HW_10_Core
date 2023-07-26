//
//  Rectangle.hpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/31/20.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <cstdint>
#include "Segment.hpp"
#include "Vec2D.hpp"


class Rectangle {
public:
    Segment seg_x;
    Segment seg_y;

    Rectangle() {
    };
    Rectangle(int32_t x0, int32_t x1, int32_t y0, int32_t y1) {
        seg_x.set(x0, x1);
        seg_y.set(y0, y1);
    }
    Rectangle(Segment &x, Segment &y) {
        seg_x.set(x);
        seg_y.set(y);
    };
    Rectangle(Rectangle &src) {
        this->set(src);
    }

    void dump(void);
    void set(int32_t x0, int32_t x1, int32_t y0, int32_t y1);
    void set(Segment &x, Segment &y);
    void set(Rectangle &src);
    void shift(Vec2D &dist);
    void reset(void);
};

bool rec_overlap_check(Rectangle &rec0, Rectangle &rec1);
bool rec_overlap(Rectangle &rec0, Rectangle &rec1, Rectangle &ov);
bool rec_collide(Rectangle &rec0, Vec2D &sp0, Rectangle &rec1, Vec2D &sp1, Segment &time);


void Rectangle_Test(void);
void Rectangle_Test_2(void);


#endif /* Rectangle_hpp */
