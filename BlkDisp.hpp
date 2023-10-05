//
//  BlkDisp.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#ifndef BlkDisp_hpp
#define BlkDisp_hpp

#include "Segment.hpp"
#include "Geo2D.hpp"
#include "Vec2D.hpp"


using namespace::std;


class Color {
private:
    /* data */

public:
    uint8_t  red;
    uint8_t  green;
    uint8_t  blue;

    Color() {
        red = green = blue = 0;
    };
    ~Color() {
    };

    inline void set(uint8_t red, uint8_t green, uint8_t blue)
    {
        this->red = red;
        this->green = green;
        this->blue = blue;
    }
};


class BlkDisp {
public:
    Geo2D           geo_size;   // geo_size of the block (calculated)
    Geo2D           pixel;      // <x, y> dimension in pixel number
    const uint8_t  *shape;      // 0 or 1, points to the array
    Color           color;
    uint32_t        scale;      // each pixe size (pixel is square)

    BlkDisp() {
        geo_size.set(0, 0);
        pixel.set(0, 0);
        shape = (uint8_t *) NULL;
    }
    BlkDisp(uint32_t scale, uint32_t x, uint32_t y, const uint8_t *shape,
            uint8_t red, uint8_t green, uint8_t blue) {
        this->scale = scale;
        this->shape = shape;
        color.set(red, green, blue);
        pixel.set(x, y);
        geo_size.set(x * scale, y * scale);
    };

    inline void set_scale(uint32_t scale) {
        this->scale = scale;
    }

    inline void set_pixel(uint32_t x, uint32_t y) {
        pixel.set(x, y);
    }

    inline void set_shape(const uint8_t *shape) {
        this->shape = shape;
    }

    inline void set_color(uint8_t red, uint8_t green, uint8_t blue) {
        color.set(red, green, blue);
    }
};


#endif /* BlkDisp_hpp */
