//
//  BlkDisp.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#include "BlkDisp.hpp"


void ShapeBank::init()
{
    for (uint32_t n = 0; n < count; ++n) {
        bank[n].check();
    }
}


void ShapeBank::dump(void)
{
    printf("ShapeBank: %d shape\n", count);

    for (uint32_t n = 0; n < count; ++n) {
        bank[n].dump("  ");
    }
}


void BlkDisp::config(uint32_t bank_num, ShapeBank *banks_dB, State_McHn func_ptr)
{
    this->bank_num = bank_num;
    this->bank_dB = banks_dB;
    this->stat_fn = func_ptr;

    for (uint32_t n = 0; n < bank_num; ++n) {
        bank_dB[n].init();
    }
}


void BlkDisp::dump(void)
{
    printf("BlkDisp - %d banks\n", bank_num);
    if (bank_num == 0) {
        return;
    }
    
    for (int n = 0; n < bank_num; ++n) {
        bank_dB[n].dump();
    }
    printf("\n");
}
