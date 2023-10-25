//
//  Shape_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#include "Shape.hpp"


Shape exmp_0 = {
    {10, 20, 30},   // <red, green, blue>
    8, 6,           // <size_x, size_y>
    2,              // scale
    "   xx   "      // shape[]
    "  xxxx  "
    " xxxxxx "
    "xxxxxxxx"
    "xxx  xxx"
    "xxx  xxx"
//  0               // tile_count
};

Shape exmp_1;


void Shape_Test()
{
    exmp_0.check();
    printf("Shape - \n");
    printf("  color: r %d, g %d, b %d\n",
           exmp_0.color.red, exmp_0.color.green, exmp_0.color.blue);
    printf("  size  : x %d, y %d\n", exmp_0.size_x, exmp_0.size_y);
    printf("  scale : %d\n", exmp_0.scale);
    printf("  tiles : %d\n", exmp_0.tile_count);
    printf("  t_indx: %d\n", exmp_0.tile_indx);
    printf("  offset: x %i, y %i\n", exmp_0.ofst_x, exmp_0.ofst_y);
    printf("\n");

    exmp_0.dump("");

    int32_t x, y;
    int32_t rslt;
    printf("\n");
    exmp_0.fetch_tile_ofst_init();
    while (1) {
        rslt = exmp_0.fetch_tile_ofst(&x, &y);
        if (rslt < 0) {
            break;
        }
        
        printf("%2d, %2d - ", x, y);
        if (rslt) {
            printf("x\n");
        } else {
            printf("_\n");
        }
    }

    printf("\n");
    printf("  t_indx: %d\n", exmp_0.tile_indx);
    printf("  offset: x %i, y %i\n", exmp_0.ofst_x, exmp_0.ofst_y);

    printf("\n");
    rslt = exmp_0.fetch_tile_ofst(&x, &y);
    printf("  rslt: %i\n", rslt);
    printf("  t_indx: %d\n", exmp_0.tile_indx);
    printf("  offset: x %i, y %i\n", exmp_0.ofst_x, exmp_0.ofst_y);
    
    exmp_0.fetch_tile_ofst_init();
    printf("\n");
    printf("  t_indx: %d\n", exmp_0.tile_indx);
    printf("  offset: x %i, y %i\n", exmp_0.ofst_x, exmp_0.ofst_y);

}
