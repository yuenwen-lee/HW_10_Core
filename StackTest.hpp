//
//  StackTest.hpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 6/28/23.
//

#ifndef StackTest_hpp
#define StackTest_hpp

#include <cstdio>
#include "Stack.hpp"


class StckSmpl {
public:
    uint32_t    id;
    double      val;
    
    StckSmpl() {
        id = 0;
        val = 0;
    }

    void dump(const char *prfx) {
        printf("%sStckSmpl:\n", prfx);
        printf("%s  id  : %d\n", prfx, id);
        printf("%s  val : %f\n", prfx, val);
        printf("\n");
    }
};


void StackTest_Test(void);


#endif /* StackTest_hpp */
