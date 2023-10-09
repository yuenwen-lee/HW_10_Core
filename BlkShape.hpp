//
//  BlkShape.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#ifndef BlkShape_hpp
#define BlkShape_hpp

#include <cstdio>
#include <cstdint>
#include <cassert>
#include "Geo2D.hpp"


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


class BlkShape {
private:
    uint32_t      scale;       // tile size in pixel (tile is square)
    Geo2D         shape_dimn;  // shape dimension in tile count <x, y>
    const char   *shape;       // 0 or 1, points to the array
    uint32_t      tiles_count; // total number of tiles
    Color         color;

public:
    BlkShape() {
        shape_dimn.set(0, 0);
        shape = NULL;
        tiles_count = 0;
    }
    BlkShape(uint32_t scale,
            uint32_t shape_x, uint32_t shape_y, const char *shape,
            uint8_t red, uint8_t green, uint8_t blue) {
        this->scale = scale;
        this->shape = shape;
        color.set(red, green, blue);
        assert(shape_x != 0 && shape_y != 0);
        shape_dimn.set(shape_x, shape_y);
        tiles_count = shape_x * shape_y;
    };

    inline void set_scale(uint32_t scale) {
        this->scale = scale;
    }

    inline void set_shape_dimn(uint32_t shape_x, uint32_t shape_y) {
        assert(shape_x != 0 && shape_y != 0);
        shape_dimn.set(shape_x, shape_y);
        tiles_count = shape_x * shape_y;
    }

    inline void set_shape(const char *shape) {
        this->shape = shape;
    }

    inline void set_color(uint8_t red, uint8_t green, uint8_t blue) {
        color.set(red, green, blue);
    }

    inline uint32_t get_scale(void) {
        return scale;
    }

    inline uint32_t get_block_count(void) {
        return tiles_count;
    }

    inline void get_shape_dimn(uint32_t *x_size, uint32_t *y_size) {
        *x_size = shape_dimn.x;
        *y_size = shape_dimn.y;
    }

    inline void get_shape_color(uint8_t *red, uint8_t *green, uint8_t *blue) {
        *red = color.red;
        *green = color.green;
        *blue = color.blue;
    }

    bool get_tile_loc(uint32_t indx, uint32_t *x, uint32_t *y);

    void dump_info(const char *prfx);
    void dump_shape(const char *prfx);
    void dump(const char *prfx);

};


void BlkShape_Test_1(void);


#endif /* BlkShape_hpp */
