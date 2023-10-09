//
//  BlkShape.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#include "BlkShape.hpp"


bool BlkShape::get_tile_loc(uint32_t indx, uint32_t *x, uint32_t *y)
{
    if (indx >= tiles_count) {
        return false;
    }

    uint32_t indx_x, indx_y;
    indx_y = indx / shape_dimn.x;
    indx_x = indx - (indx_y * shape_dimn.x);
    *x = indx_x * scale;
    *y = indx_y * scale;
    if (shape[indx] == ' ') {
        return false;
    } else {
        return true;
    }
}


void BlkShape::dump_info(const char *prfx)
{
    printf("%sBlkDisp: \n", prfx);
    printf("%s  scale: %d\n", prfx, scale);
    printf("%s  shape_dimn: %d, %d\n", prfx, shape_dimn.x, shape_dimn.y);
    printf("%s  shape: %p\n", prfx, shape);
    printf("%s  shape_count: %d\n", prfx, tiles_count);
    printf("%s  color: %d, %d, %d\n", prfx, color.red, color.green, color.blue);
    printf("\n");
}


void BlkShape::dump_shape(const char *prfx)
{
    uint32_t indx, indx_x;

    if (tiles_count == 0) {
        printf("%sshape is empty !!\n\n", prfx);
        return;
    }

    for (indx = indx_x = 0; indx < tiles_count; ++indx) {
        if (indx_x == 0) {
            printf("%s", prfx);
        }
        putchar(shape[indx]);

        ++indx_x;
        if (indx_x == shape_dimn.x) {
            indx_x = 0;
            putchar('\n');
        }
    }
    printf("\n");
}


void BlkShape::dump(const char *prfx)
{
    dump_info(prfx);
    dump_shape(prfx);
}
