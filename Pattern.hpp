//
//  Shape.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/9/23.
//

#ifndef Pattern_hpp
#define Pattern_hpp

#include <cstdio>
#include <cstdint>


struct Color {
    uint8_t  red;
    uint8_t  green;
    uint8_t  blue;
    uint8_t  __stuff;
};


struct Pattern {
    struct Color color;    // NOTE: Except the field, 'tile_count', which
    uint32_t size_x;       //       will be derived by calling the func
    uint32_t size_y;       //       check(), the other fields should be
    uint32_t scale;        //       explicitly initilized in the global
    const char *pattern;   //       varaible.
    uint32_t tile_count;   //       Pleas check the 'Pattern_Test.cpp'

    void init(void);       // Note: Must be called before using !!!!
    void fetch_tile_ofst_init(void);
    int32_t fetch_tile_ofst(int32_t *x, int32_t *y);

    uint32_t get_tile_indx(void);    // only for debugging ......
    int32_t  get_ofst_x(void);       // only for debugging ......
    int32_t  get_ofst_y(void);       // only for debugging ......

    void dump(const char *prfx);
};


struct PatternBank {
    const char  *name;
    uint32_t     count;
    Pattern     *bank;
    uint32_t     rotate_factor;
    Pattern     *rotate_func(uint32_t timer);

    inline void set_name(const char *name) {
        this->name = name;
    }
    inline void set_count(uint32_t count) {
        this->count = count;
    }
    inline void set_bank(Pattern *bank) {
        this->bank = bank;
    }
    inline void set_rotFctr(uint32_t factor) {
        this->rotate_factor = factor;
    }

    void init(void);
    void dump(void);
};


void Pattern_Test();
void Pattern_Test_2_A();


#endif /* Pattern_hpp */
