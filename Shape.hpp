//
//  Shape.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <cstdio>
#include <cstdint>


struct Color {
    uint8_t  red;
    uint8_t  green;
    uint8_t  blue;
    uint8_t  __stuff;
};


struct Shape {
    struct Color color;
    uint32_t size_x;
    uint32_t size_y;
    uint32_t scale;
    const char *shape;
    uint32_t tile_count;

    uint32_t tile_indx;
    int16_t  ofst_x, ofst_y;

    void check(void);
    inline uint32_t get_tile_count(void) {
        return tile_count;
    }
    inline void fetch_tile_ofst_init(void) {
        tile_indx = ofst_x = ofst_y = 0;
    }
    int32_t fetch_tile_ofst(int32_t *x, int32_t *y);
    void dump(const char *prfx);
};


void Shape_Test();


#endif /* Shape_hpp */
