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


class Vitality_Abst {
public:
    uint32_t  life;
    uint32_t  damage_recv;
    uint32_t  damage;

    Vitality_Abst() {
        life = damage_recv = damage = 0;
    }

    void init(uint32_t life, uint32_t damage);
    bool destroyed(void);
    bool alived(void);
    void dump(const char *prfx);

    virtual void damage_eval(Vitality_Abst &vtal) = 0;
};


class Vitality : public Vitality_Abst {
public:
    void damage_eval(Vitality_Abst &vtal);
};


#endif /* Vitality_hpp */
