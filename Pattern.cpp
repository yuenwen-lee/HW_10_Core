//
//  Shape.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#include <cassert>
#include <cstring>
#include "Pattern.hpp"


static uint32_t  tile_indx;
static int32_t   ofst_x, ofst_y;


void Pattern::init()
{
    tile_count = (uint32_t) strlen(pattern);
    assert(size_x * size_y == tile_count);
}


void Pattern::fetch_tile_ofst_init(void)
{
    assert(size_x * size_y == tile_count);
    tile_indx = ofst_x = ofst_y = 0;
}

// x : tile location offset (in number of pixels) in x axis
// y : tile location offset (in number of pixels) in y axis
//
// Return:
//   Positive  - solid tile, scale value
//    0        - empty tile, scale is 0
//   -1        - invalid, all tiles are already read out
int32_t Pattern::fetch_tile_ofst(int32_t *x, int32_t *y)
{
    if (tile_indx == tile_count) {
        return -1;
    } // already beyond the end of the shape

    *x = ofst_x * scale;
    *y = ofst_y * scale;
    if (++ofst_x == size_x) {
        ofst_x = 0;
        ++ofst_y;
    }

    if (pattern[tile_indx++] != ' ') {
        return scale;
    } else {
        return 0;
    }
}


uint32_t Pattern::get_tile_indx(void)
{
    return tile_indx;
}


int32_t Pattern::get_ofst_x(void)
{
    return ofst_x;
}


int32_t Pattern::get_ofst_y(void)
{
    return ofst_y;
}


Pattern *PatternBank::rotate_func(uint32_t timer)
{
    uint32_t indx = (timer / rotate_factor) % count;
    return &bank[indx];
}


void Pattern::dump(const char *prfx)
{
    printf("%sPattern -\n", prfx);
    printf("%s  dimen : %d, %d\n", prfx, size_x, size_y);
    printf("%s  scale : %d\n", prfx, scale);
    printf("%s  shape : %p\n", prfx, pattern);
    printf("%s  count : %d\n", prfx, tile_count);
    printf("%s  color : %d, %d, %d\n", prfx, color.red, color.green, color.blue);
    printf("%s  t_indx: %d\n", prfx, tile_indx);
    printf("%s  offset: %i, %i\n", prfx, ofst_x, ofst_y);
    printf("\n");

    if (tile_count == 0) {
        printf("%spattern is empty !!\n\n", prfx);
        return;
    }

    uint32_t indx, indx_x;
    for (indx = indx_x = 0; indx < tile_count; ++indx) {
        if (indx_x == 0) {
            printf("%s  ", prfx);
        }
        putchar(pattern[indx]);

        ++indx_x;
        if (indx_x == size_x) {
            indx_x = 0;
            putchar('\n');
        }
    }
    printf("\n");
}


void PatternBank::init()
{
    for (uint32_t n = 0; n < count; ++n) {
        bank[n].init();
    }
}


void PatternBank::dump(void)
{
    printf("PatternBank -\n");
    printf("  Name   : %s\n", name);
    printf("  Pattern: %d\n", count);
    printf("  RotFctr: %d\n", rotate_factor);
    printf("\n");

    for (uint32_t n = 0; n < count; ++n) {
        bank[n].dump("  ");
    }
}


void PatternInfo::dump()
{
    printf("PatternInfo - \n");
    printf("  x0, y0: [%d, %d]\n", x0, y0);
    pattern->dump("  ");
}
