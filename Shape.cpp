//
//  Shape.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#include <cassert>
#include <cstring>
#include "Shape.hpp"


void Shape::check()
{
    tile_indx = ofst_x = ofst_y = 0;
    tile_count = (uint32_t) strlen(shape);
    assert(size_x * size_y == tile_count);
}


// x : tile location offset (in number of pixels) in x axis
// y : tile location offset (in number of pixels) in y axis
//
// Return:
//   Positive  - solid tile, scale value
//    0        - empty tile, scale is 0
//   -1        - invalid, all tiles are already read out
int32_t Shape::fetch_tile_ofst(int32_t *x, int32_t *y)
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

    if (shape[tile_indx++] != ' ') {
        return scale;
    } else {
        return 0;
    }
}

void Shape::dump(const char *prfx)
{
    printf("%sShape: \n", prfx);
    printf("%s  dimen : %d, %d\n", prfx, size_x, size_y);
    printf("%s  scale : %d\n", prfx, scale);
    printf("%s  shape : %p\n", prfx, shape);
    printf("%s  count : %d\n", prfx, tile_count);
    printf("%s  color : %d, %d, %d\n", prfx, color.red, color.green, color.blue);
    printf("%s  t_indx: %d\n", prfx, tile_indx);
    printf("%s  offset: %i, %i\n", prfx, ofst_x, ofst_y);
    printf("\n");

    if (tile_count == 0) {
        printf("%sshape is empty !!\n\n", prfx);
        return;
    }

    uint32_t indx, indx_x;
    for (indx = indx_x = 0; indx < tile_count; ++indx) {
        if (indx_x == 0) {
            printf("%s  ", prfx);
        }
        putchar(shape[indx]);

        ++indx_x;
        if (indx_x == size_x) {
            indx_x = 0;
            putchar('\n');
        }
    }
    printf("\n");
}
