//
//  BlkDisp_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/6/23.
//

#include "Stack.hpp"
#include "BlkDisp.hpp"


Pattern *exmp_func(void *blk_disp, uint32_t mode, int32_t time,
                   uint32_t *indx_bank, uint32_t *indx_shape);


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


Pattern *exmp_func(void *idnt, uint32_t mode, int32_t time,
                   uint32_t *indx_bank, uint32_t *indx_shape)
{
    BlkDisp *blk_disp = (BlkDisp *) idnt;

    uint32_t bank_idx, shape_idx;
    bank_idx = 1;
    shape_idx = 2;
    *indx_bank = bank_idx;
    *indx_shape = shape_idx;

    printf("............ !!!! exmp_func() !!!! ............\n\n");
    printf("Exmp_Func() - \n");
    printf("  mode: %d\n", mode);
    printf("  time: %d\n", time);
    printf("  bank_idx : %d\n", bank_idx);
    printf("  shape_idx: %d\n", shape_idx);
    printf("\n");
    blk_disp->dump();

    return &blk_disp->bank_dB[bank_idx].bank[shape_idx];
}


void BlkDisp_Test(void)
{
    BlkDisp  blk_disp;
    uint32_t indx_bank, indx_shape;

    blk_disp.config(sizeof(ptrn_Db)/sizeof(PatternBank), ptrn_Db, exmp_func);
    blk_disp.dump();
    printf("\n");

    Pattern *ptrn_p = blk_disp.state_fn((void *) &blk_disp,
                                        10, 5, &indx_bank, &indx_shape);

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


void BlkDisp_Test_2(void)
{
#define BLK_DISP_NUM  3
    int  n;

    BlkDisp *blk_disp = new BlkDisp [BLK_DISP_NUM];   // allocated in heap
    for (n = 0; n < BLK_DISP_NUM; n++) {
        blk_disp[n].config(2, ptrn_Db, exmp_func);
    }

    for (n = 0; n < BLK_DISP_NUM; ++n) {
        printf("........!!!!!!!! BlkDisp[%d] !!!!!!!!........\n\n", n);
        blk_disp[n].dump();
        printf("\n");
    }
    printf("\n");

    // Simulate the
    blk_disp[0].pattern_info.config( 100,  110, &ptrn_Db[0].bank[2]);
    blk_disp[1].pattern_info.config( 300,  310, &ptrn_Db[1].bank[0]);
    blk_disp[2].pattern_info.config(-100, -110, &ptrn_Db[1].bank[3]);
    printf("........!!!!!!!! PatternInfo !!!!!!!!........\n\n");
    for (n = 0; n < BLK_DISP_NUM; ++n) {
        blk_disp[n].pattern_info.dump();
        printf("\n");
    }
    printf("\n");



    Stack<PatternInfo>  stack;
    PatternInfo  *ptrn_info_p;

    printf("............!!!! Stack Test !!!!............\n\n");
    stack.config("PtrnInfo", 10);
    for (n = 0; n < BLK_DISP_NUM; ++n) {
        stack.push(&blk_disp[n].pattern_info);
    }
    stack.dump("--------> ");
    printf("\n");

    printf("............ Pop the stack ............\n\n");
    for (n = 0; n < BLK_DISP_NUM; ++n) {
        uint32_t indx;
        int32_t rslt, x, y;

        printf("____ %d PatternInfo ____\n\n", n);
        ptrn_info_p = stack.pop();
        ptrn_info_p->dump();
        printf("\n");

        indx = 0;
        ptrn_info_p->fetch_tile_info_init();
        while (1) {
            rslt = ptrn_info_p->fetch_tile_info(&x, &y);
            if (rslt < 0) {
                break;
            }
            printf("  %2d - %s [%4d, %4d]\n", indx, (rslt > 0 ? "x" : "_"), x, y);
            ++indx;
        }
        printf("\n");
    }

    delete [] blk_disp;
}
