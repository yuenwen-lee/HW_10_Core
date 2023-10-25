//
//  BlkDisp.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#ifndef BlkDisp_hpp
#define BlkDisp_hpp

#include <cstdio>
#include "Shape.hpp"


typedef Shape *(* State_McHn)(void *blk_disp, uint32_t mode, int32_t time,
                              uint32_t *indx_bank, uint32_t *indx_shape);


struct ShapeBank {
    uint32_t  count;
    Shape    *bank;

    inline void set_count(uint32_t count) {
        this->count = count;
    }
    inline void set_bank(Shape *bank) {
        this->bank = bank;
    }

    void init(void);
    void dump(void);
};


class BlkDisp {
public:
    uint32_t    bank_num;
    ShapeBank  *bank_dB;
    State_McHn  stat_fn;

    void config(uint32_t bank_num, ShapeBank *banks_dB, State_McHn func_ptr);
    void dump(void);
};


void BlkDisp_Test();


#endif /* BlkDisp_hpp */
