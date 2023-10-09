//
//  BlkShape_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#include "BlkShape.hpp"


static const char shape_A[] = {
    "   XX   "
    "  XXXX  "
    " XXXXXX "
    "XXXXXXXX"
    "XXX  XXX"
    "XXX  XXX"
};


void BlkShape_Test_1(void)
{
    printf("shape_A - lenth: %d\n\n", (int) sizeof(shape_A));
    
    BlkShape shp0;
    shp0.dump("");
    
    BlkShape shp1(4, 8, 6, shape_A, 10, 20, 30);
    shp1.dump("");
    
    uint32_t scale, shape_count;
    uint32_t x_count, y_count;
    uint8_t red, green, blue;
    uint32_t loc_x, loc_y;
    bool valid;

    scale = shp1.get_scale();
    shape_count = shp1.get_block_count();
    shp1.get_shape_dimn(&x_count, &y_count);
    shp1.get_shape_color(&red, &green, &blue);
    printf("BlkDisp Info: \n");
    printf("  scale: %d\n", scale);
    printf("  shape_dimn: %d, %d\n", x_count, y_count);
    printf("  tiles_count: %d\n", shape_count);
    printf("  color: %d, %d, %d\n", red, green, blue);
    printf("\n");

    for (uint32_t indx = 0; indx < shape_count; ++indx) {
        valid = shp1.get_tile_loc(indx, &loc_x, &loc_y);
        printf("%2d, %2d - ", loc_x, loc_y);
        if (valid) {
            printf("O\n");
        } else {
            printf("_\n");
        }
    }
    printf("\n");
}

