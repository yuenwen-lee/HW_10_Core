//
//  BlkDisp.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#include "BlkDisp.hpp"


void BlkDisp::config(uint32_t bank_num, PatternBank *banks_dB, PatternFunc func_ptr)
{
    this->bank_num = bank_num;
    this->bank_dB = banks_dB;
    this->ptrn_func = func_ptr;

    for (uint32_t n = 0; n < bank_num; ++n) {
        bank_dB[n].init();
    }
}


void BlkDisp::dump(void)
{
    printf("BlkDisp -\n");
    printf("  PatternBank: %d\n", bank_num);
    printf("  PatternFunc: %p\n", ptrn_func);
    printf("\n");

    if (bank_num == 0) {
        return;

    } else {
        for (int n = 0; n < bank_num; ++n) {
            bank_dB[n].dump();
        }
        printf("\n");
    }
}
