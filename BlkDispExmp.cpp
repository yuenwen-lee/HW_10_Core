//
//  BlkDispBase_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/24.
//

#include "BlkDispExmp.hpp"


static Pattern ptrn_array_0[] = {
    {
        {10, 20, 30},   // <red, green, blue>
        8, 6,           // <size_x, size_y>
        2,              // scale
        "   xx   "      // shape[]
        "  xxxx  "
        " xxxxxx "
        "xxxxxxxx"
        "xxx  xxx"
        "xxx  xxx"
    },
    {
        {15, 25, 35},   // <red, green, blue>
        9, 6,           // <size_x, size_y>
        2,              // scale
        "x  xxx  x"     // shape[]
        "  xxxxx  "
        " xxx xxx "
        " xxx xxx "
        "  xxxxx  "
        "x  xxx  x"
    },
    {
        {5, 6, 7},
        6, 6,
        3,
        "  xx  "
        "  xx  "
        "xxxxxx"
        "xxxxxx"
        "  xx  "
        "  xx  "
    }
};


static Pattern ptrn_array_1[] = {
    {
        {11, 21, 31},
        5, 5,
        1,
        "x    "
        " x   "
        "  x  "
        "   x "
        "    x"
    },
    {
        {12, 22, 32},
        5, 5,
        1,
        "  x  "
        "  x  "
        "  x  "
        "  x  "
        "  x  "
    },
    {
        {13, 23, 33},
        5, 5,
        1,
        "    x"
        "   x "
        "  x  "
        " x   "
        "x    "
    },
    {
        {14, 24, 34},
        5, 5,
        1,
        "     "
        "     "
        "xxxxx"
        "     "
        "     "
    },
};


static PatternBank ptrn_Db[] = {
    {
        "Test Ptrn_0",
        sizeof(ptrn_array_0) / sizeof(Pattern),
        ptrn_array_0
    },
    {
        "Test Ptrn_1",
        sizeof(ptrn_array_1) / sizeof(Pattern),
        ptrn_array_1
    }
};


void BlkDispExmp_Test(void)
{
    BlkDispExmp blk_disp_exmp;
    blk_disp_exmp.config(sizeof(ptrn_Db)/sizeof(PatternBank), ptrn_Db);

    BlkDisplay__ *blk_disp = &blk_disp_exmp;
    uint32_t indx_bank, indx_shape;

    blk_disp->dump();
    printf("\n");

    Pattern *ptrn_p = blk_disp->ptrn_func(10, 5, &indx_bank, &indx_shape);

    printf("............!!!! After call the state_fn() !!!!............\n\n");
    printf("  indx_bank: %d, indx_shape: %d\n", indx_bank, indx_shape);
    printf("\n");
    ptrn_p->dump("  ");
    printf("\n");

    uint32_t indx = 0;
    ptrn_p->fetch_tile_ofst_init();
    while (1) {
        int32_t x, y, scale;

        scale = ptrn_p->fetch_tile_ofst(&x, &y);
        if (scale < 0) {
            break;
        }
        printf("  %2d - %s [%4d, %4d]\n", indx, (scale > 0 ? "x" : "_"), x, y);
        ++indx;
    }
    printf("\n");
}
