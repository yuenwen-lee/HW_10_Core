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


class PatternInfo {
public:
    int32_t   x0;       // pattern origin in x
    int32_t   y0;       // pattern origin in y
    Pattern  *pattern;  // pointer to the pattern

    inline void config(int32_t x0, int32_t y0, Pattern *ptrn_p) {
        this->x0 = x0;
        this->y0 = y0;
        pattern = ptrn_p;
    }
    inline void fetch_tile_info_init(void) {
        pattern->fetch_tile_ofst_init();
    }
    inline int32_t fetch_tile_info(int32_t *x_p, int32_t *y_p) {
        int32_t x, y;
        int32_t rslt = pattern->fetch_tile_ofst(&x, &y);
        *x_p = x + x0;
        *y_p = y + y0;
        return rslt;
    }
    void dump(void);
};


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
