//
//  BlkDisp.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#ifndef BlkDisp_hpp
#define BlkDisp_hpp

#include <cstdio>
#include "Pattern.hpp"


// typedef Pattern *(* PatternFunc)(void *blk_disp, uint32_t mode, int32_t time,
//                                  uint32_t *indx_bank, uint32_t *indx_shape);
using PatternFunc = Pattern *(*)(void *blk_disp, uint32_t mode, int32_t time,
                                 uint32_t *indx_bank, uint32_t *indx_shape);


class BlkDisp {
public:
    uint32_t       bank_num;
    PatternBank   *bank_dB;
    PatternFunc    ptrn_func;
    PatternInfo    ptrn_info;

    void config(uint32_t bank_num, PatternBank *banks_dB, PatternFunc func_ptr);
    void dump(void);
};


void BlkDisp_Test(void);
void BlkDisp_Test_2(void);


#endif /* BlkDisp_hpp */
