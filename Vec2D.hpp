//
//  Vec2D.hpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/29/20.
//

#ifndef Vec2D_hpp
#define Vec2D_hpp

#include <cstdint>


class Vec2D {
public:
    int32_t x, y;
    Vec2D(void) {
        x = y = 0;
    }
    Vec2D(int32_t x, int32_t y) {
        this->x = x;
        this->y = y;
    }
    
    void operator = (const Vec2D &other) {
        this->x = other.x;
        this->y = other.y;
    }

    Vec2D operator + (const Vec2D &other) {
        Vec2D rst;
        rst.x = this->x + other.x;
        rst.y = this->y + other.y;
        return rst;
    }
    void operator += (const Vec2D &other) {
        this->x += other.x;
        this->y += other.y;
    }

    Vec2D operator - (const Vec2D &other) {
        Vec2D rst;
        rst.x = this->x - other.x;
        rst.y = this->y - other.y;
        return rst;
    }
    void operator -= (const Vec2D &other) {
        x -= other.x;
        y -= other.y;
    }

    Vec2D operator * (const int32_t scale) {
        Vec2D rst;
        rst.x = x * scale;
        rst.y = y * scale;
        return rst;
    }
    void operator *= (const int32_t scale) {
        x *= scale;
        y *= scale;
    }

    Vec2D operator / (const int32_t scale) {
        Vec2D rst;
        rst.x = x / scale;
        rst.y = y / scale;
        return rst;
    }
    void operator /= (const int32_t scale) {
        x /= scale;
        y /= scale;
    }

    Vec2D operator % (const int32_t scale) {
        Vec2D rst;
        rst.x = x % scale;
        rst.y = y % scale;
        return rst;
    }

    void set(int32_t x, int32_t y) {
        this->x = x;
        this->y = y;
    }
    void dump(void);
};


void Vec2D_test(void);


#endif /* Vec2D_hpp */
