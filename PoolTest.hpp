//
//  DynMemExmp.hpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 6/22/23.
//

#ifndef PoolTest_hpp
#define PoolTest_hpp

#include <cstdint>


class Sample {
public:
    const char  *name;
    uint32_t     numb;

    Sample() {
        name = "No Name";
    }
    void dump(const char *prfx);
};


void PoolTest(void);


#endif /* PoolTest_hpp */
