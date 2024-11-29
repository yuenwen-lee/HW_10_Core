//
//  BlkDispBase_Test.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/24.
//

#ifndef BlkDispExmp_hpp
#define BlkDispExmp_hpp

#include "BlkDispBase.hpp"


class BlkDispExmp : public BlkDisplay__ {
    Pattern *ptrn_func(uint32_t mode, int32_t time,
                       uint32_t *indx_bank, uint32_t *indx_shape) {
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
        this->dump();

        return &bank_dB[bank_idx].bank[shape_idx];
    }
};


#endif /* BlkDispExmp_hpp */
