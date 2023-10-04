//
//  geo2d.hpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/29/20.
//

#ifndef Geo2D_hpp
#define Geo2D_hpp

#include <cstdint>


class Geo2D {
    
public:
    int32_t x, y;
    
    Geo2D(void) {
        x = 0;
        y = 0;
    };
    Geo2D(int32_t x, int32_t y) {
        this->x = x;
        this->y = y;
    };

    inline void set(int32_t x, int32_t y) {
        this->x = x;
        this->y = y;
    }
    void dump(void);
};


void Geo2D_test(void);

#endif /* Geo2D_hpp */
