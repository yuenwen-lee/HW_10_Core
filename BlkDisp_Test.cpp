//
//  BlkDisp_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/6/23.
//

#include "BlkDisp.hpp"


Shape *exmp_func(void *blk_disp, uint32_t mode, int32_t time,
                 uint32_t *indx_bank, uint32_t *indx_shape);


Shape shape_array_0[] = {
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
        "x  xxx  x"      // shape[]
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


Shape shape_array_1[] = {
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


ShapeBank shape_Db[] = {
    {
        3,
        shape_array_0
    },
    {
        4,
        shape_array_1
    }
};


void BlkDisp_Test()
{
    BlkDisp blk_disp;

    blk_disp.config(2, shape_Db, exmp_func);
//  blk_disp.dump();

    uint32_t indx_bank, indx_shape;
    Shape *shape_p = blk_disp.stat_fn((void *) &blk_disp,
                                      10, 5, &indx_bank, &indx_shape);
    printf("... indx_bank: %d, indx_shape: %d\n", indx_bank, indx_shape);
    printf("\n");
    shape_p->dump("....");
    printf("\n");

    uint8_t red;
    red = shape_p->color.red;

    int32_t x, y;
    int32_t scale;
    shape_p->fetch_tile_ofst_init();
    while (1) {
        scale = shape_p->fetch_tile_ofst(&x, &y);
        if (scale < 0) {
            break;
        }
        
        if (scale > 0) {
            
        }
    }
}


Shape *exmp_func(void *idnt, uint32_t mode, int32_t time,
                 uint32_t *indx_bank, uint32_t *indx_shape)
{
    BlkDisp *blk_disp = (BlkDisp *) idnt;
//  blk_disp->dump();

    uint32_t bank_idx, shape_idx;
    bank_idx = 1;
    shape_idx = 2;
    *indx_bank = bank_idx;
    *indx_shape = shape_idx;

    printf("Exmp_Func() - \n");
    printf("  mode: %d\n", mode);
    printf("  time: %d\n", time);
    printf("  bank_idx : %d\n", bank_idx);
    printf("  shape_idx: %d\n", shape_idx);
    printf("\n");

    return &blk_disp->bank_dB[bank_idx].bank[shape_idx];
}
