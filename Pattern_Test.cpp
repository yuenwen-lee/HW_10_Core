//
//  Shape_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#include "Pattern.hpp"


Pattern exmp_0 = {
    {10, 20, 30},   // <red, green, blue>
    8, 6,           // <size_x, size_y>
    2,              // scale
    "   xx   "      // shape[]
    "  xxxx  "
    " xxxxxx "
    "xxxxxxxx"
    "xxx  xxx"
    "xxx  xxx"
};

Pattern exmp_1;


void Pattern_Test()
{
    Pattern ptrn_local;

    exmp_0.init();
    printf("Pattern - \n");
    printf("  color: r %d, g %d, b %d\n",
           exmp_0.color.red, exmp_0.color.green, exmp_0.color.blue);
    printf("  size  : x %d, y %d\n", exmp_0.size_x, exmp_0.size_y);
    printf("  scale : %d\n", exmp_0.scale);
    printf("  tiles : %d\n", exmp_0.tile_count);
    printf("  t_indx: %d\n", exmp_0.get_tile_indx());
    printf("  offset: x %i, y %i\n", exmp_0.get_ofst_x(), exmp_0.get_ofst_y());
    printf("\n");

    exmp_0.dump("");
    printf("\n");

    int32_t  x, y, rslt;
    uint32_t indx = 0;
    exmp_0.fetch_tile_ofst_init();
    while (1) {
        rslt = exmp_0.fetch_tile_ofst(&x, &y);
        if (rslt < 0) {
            break;
        }
        
        printf("%2d  [%2d, %2d] - ", indx, x, y);
        if (rslt) {
            printf("x\n");
        } else {
            printf("_\n");
        }

        ++indx;
    }
    printf("\n");

    printf("After complete the retrieving ....\n");
    printf("  t_indx: %d\n", exmp_0.get_tile_indx());
    printf("  offset: x %i, y %i\n", exmp_0.get_ofst_x(), exmp_0.get_ofst_y());
    printf("\n");

    rslt = exmp_0.fetch_tile_ofst(&x, &y);
    printf("Retrieve the tile location AGAIN ....\n");
    printf("  rslt: %i\n", rslt);
    printf("  t_indx: %d\n", exmp_0.get_tile_indx());
    printf("  offset: x %i, y %i\n", exmp_0.get_ofst_x(), exmp_0.get_ofst_y());
    printf("\n");

    exmp_0.fetch_tile_ofst_init();
    printf("Call fetch_tile_ofst_init() ....\n");
    printf("  t_indx: %d\n", exmp_0.get_tile_indx());
    printf("  offset: x %i, y %i\n", exmp_0.get_ofst_x(), exmp_0.get_ofst_y());
    printf("\n");

    printf("..............!!!!  Test unconfig global Pattern !!!!..............\n");
    exmp_1.fetch_tile_ofst_init();

    rslt = exmp_1.fetch_tile_ofst(&x, &y);
    printf("Retrieve the tile location ....\n");
    printf("  rslt: %i\n", rslt);
    printf("  t_indx: %d\n", exmp_0.get_tile_indx());
    printf("  offset: x %i, y %i\n", exmp_0.get_ofst_x(), exmp_0.get_ofst_y());
    printf("\n");


    printf("..............!!!!  Test unconfig Pattern without init !!!!..............\n");
    printf("!!!! will trigger assert() failure !!!!\n");
    ptrn_local.fetch_tile_ofst_init();

    rslt = ptrn_local.fetch_tile_ofst(&x, &y);
    printf("Retrieve the tile location AGAIN ....\n");
    printf("  rslt: %i\n", rslt);
    printf("  t_indx: %d\n", ptrn_local.get_tile_indx());
    printf("  offset: x %i, y %i\n", ptrn_local.get_ofst_x(), exmp_0.get_ofst_y());
    printf("\n");
}
