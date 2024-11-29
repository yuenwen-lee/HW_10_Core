//
//  BlkDispVirtual.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/24.
//

#include "BlkDispBase.hpp"


void BlkDisplay__::config(uint32_t bank_num, PatternBank *banks_dB)
{
    this->bank_num = bank_num;
    this->bank_dB = banks_dB;
    for (uint32_t n = 0; n < bank_num; ++n) {
        bank_dB[n].init();
    }
}


void BlkDisplay__::dump()
{
    printf("BlkDisp -\n");
    printf("  PatternBank: %d\n", bank_num);
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
