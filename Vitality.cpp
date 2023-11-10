//
//  Vitality.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 11/9/23.
//

#include "Vitality.hpp"


void damg_func_default(void *obj, uint32_t damage)
{
    Vitality *vtal = (Vitality *) obj;
    vtal->damage_recv += damage;
}

void Vitality::dump(const char *prfx)
{
    printf("%sVitality - %p\n", prfx, this);
    printf("%s  life: %d\n", prfx, life);
    printf("%s  damage (receied): %d\n", prfx, damage_recv);
    printf("%s  damage: %d\n", prfx, damage);
    printf("%s  damg_func: %p\n", prfx, damg_func);
}
