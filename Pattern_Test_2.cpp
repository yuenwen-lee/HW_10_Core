//
//  Pattern_Test_2.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/3/24.
//

#include <cstdio>
#include "Pattern.hpp"


static Pattern ptrn_array_A[] = {
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


static Pattern ptrn_array_B[] = {
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
        "Test Ptrn_A",
        sizeof(ptrn_array_A) / sizeof(Pattern),
        ptrn_array_A,
        4
    },
    {
        "Test Ptrn_B",
        sizeof(ptrn_array_B) / sizeof(Pattern),
        ptrn_array_B,
        5
    }
};


void Pattern_Test_2_A(void)
{
    Pattern *ptrn_p;
    uint32_t db_size;
    
    printf("............!!!! %s() !!!!............\n\n", __FUNCTION__);
    
    db_size = sizeof(ptrn_Db) / sizeof(PatternBank);
    for (uint32_t n = 0; n < db_size; ++n) {
        ptrn_Db[n].init();
        ptrn_Db[n].dump();
    }
    printf("\n");

    printf("............!!!! %s() Ptrn_A Index !!!!............\n\n", __FUNCTION__);
    for (uint32_t time = 0; time < 30; ++time) {
        ptrn_p = ptrn_Db[0].rotate_func(time);
        printf("%2d -\n", time);
        ptrn_p->dump("  ");
    }
    printf("\n");
    
    printf("............!!!! %s() Ptrn_B Index !!!!............\n\n", __FUNCTION__);
    for (uint32_t time = 0; time < 30; ++time) {
        ptrn_p = ptrn_Db[1].rotate_func(time);
        printf("%2d -\n", time);
        ptrn_p->dump("  ");
    }
    printf("\n");
}
