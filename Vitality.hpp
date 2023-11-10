//
//  Vitality.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 11/9/23.
//

#ifndef Vitality_hpp
#define Vitality_hpp

#include <cstdint>
#include <cstdio>


extern void damg_func_default(void *vtal, uint32_t damage);

using DamgFunc = void (*)(void *vtal, uint32_t damage);


class Vitality {
public:
    uint32_t  life;
    uint32_t  damage_recv;
    uint32_t  damage;
    DamgFunc  damg_func;
    
    Vitality() {
        life = damage_recv = damage = 0;
        damg_func = damg_func_default;
    }
    
    inline void init(uint32_t life, uint32_t damage) {
        this->life = life;
        this->damage = damage;
    }
    
    inline void set_func(DamgFunc func_ptr) {
        this->damg_func = func_ptr;
    }

    inline bool destroyed(void) {
        return life <= damage_recv;
    }
    
    inline bool alived(void) {
        return life > damage_recv;
    }

    void dump(const char *prfx);
};


#endif /* Vitality_hpp */
