//
//  Explosion.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/28/23.
//

#ifndef Explosion_hpp
#define Explosion_hpp

#include <cstdio>
#include "BlkGeo.hpp"
#include "Vitality.hpp"


class Explosion {
public:
    const char  *name;
    Vec2D        ofst;       // Explosion area related to the Object BlkGeo's origin.
    Geo2D        size;
    Rectangle    area_loc;
    Vitality     vital;     // Damage caused by the explosion

    Explosion() {
        name = "No_Name ...";
    }
    
    void set_name(const char *name) {
        this->name = name;
    }
    void config(int32_t ofst_x, int32_t ofst_y,
                uint32_t size_x, uint32_t size_y, uint32_t damage);
    void update(int32_t x0, int32_t y0);
    void update(Vec2D orig);

    void dump(const char *prfx);
};


void Explosion_Test(void);


 #endif /* Explosion_hpp */
