//
//  FifoTest.hpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 7/3/23.
//

#ifndef FifoTest_hpp
#define FifoTest_hpp

#include <cstdio>


class Pckg {
public:
    uint32_t     id;
    const char  *code_name;
    
    Pckg() {
        id = 0;
        code_name = "??";
    }
    
    void dump(const char *prfx) {
        printf("%sID: %d, name: %s\n", prfx, id, code_name);
    }
};


void Fifo_Test(void);


#endif /* FifoTest_hpp */
