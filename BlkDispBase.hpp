//
//  BlkDispVirtual.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/24.
//

#ifndef BlkDispBase_hpp
#define BlkDispBase_hpp

#include <cstdio>
#include "Pattern.hpp"


class BlkDisplay__ {
public:
    uint32_t       bank_num;
    PatternBank   *bank_dB;
    PatternInfo    ptrn_info;

    void config(uint32_t bank_num, PatternBank *banks_dB);
    void dump(void);

    virtual Pattern *ptrn_func(uint32_t mode, int32_t time,
                               uint32_t *indx_bank, uint32_t *indx_shape) = 0;
};


#endif /* BlkDispBase_hpp */
