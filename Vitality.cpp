//
//  Vitality.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 11/9/23.
//

#include "Vitality.hpp"


void Vitality_Abst::init(uint32_t life, uint32_t damage)
{
    this->life = life;
    this->damage = damage;
}

bool Vitality_Abst::destroyed(void)
{
    return life <= damage_recv;
}

bool Vitality_Abst::alived(void)
{
    return life > damage_recv;
}

void Vitality_Abst::dump(const char *prfx)
{
    printf("%sVitality - %p\n", prfx, this);
    printf("%s  life: %d\n", prfx, life);
    printf("%s  damage (received): %d\n", prfx, damage_recv);
    printf("%s  damage: %d\n", prfx, damage);
}


void Vitality::damage_eval(Vitality_Abst &vtal)
{
    damage_recv += vtal.damage;
}
