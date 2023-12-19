//
//  Explosion.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/28/23.
//

#include <cstring>
#include "Explosion.hpp"


void Explosion::config(int32_t ofst_x, int32_t ofst_y,
                       uint32_t size_x, uint32_t size_y, uint32_t damage)
{
    vital.init(0x7FFFFFFF, damage);    // set explosion's life to maximum ...
    size.set(size_x, size_y);
    ofst.set(ofst_x, ofst_y);
}


void Explosion::update(int32_t x0, int32_t y0)
{
    int32_t x_0 = x0 + ofst.x;
    int32_t y_0 = y0 + ofst.y;
    area_loc.set(x_0, x_0 + size.x,
                 y_0, y_0 + size.y);
}

void Explosion::update(Vec2D orig)
{
    orig += ofst;
    area_loc.set(orig.x, orig.x + size.x,
                 orig.y, orig.y + size.y);
}


void Explosion::dump(const char *prfx)
{
    char str[20] = "  ";
    strcat(str, prfx);

    printf("%sExplosion - %s\n", prfx, name);
    printf("%sofst: ", str); ofst.dump(); printf("\n");
    printf("%ssize: ", str); size.dump(); printf("\n");
    printf("%srect: ", str); area_loc.dump(); printf("\n");
    vital.dump(str);
}


void Explosion_Test(void)
{
    Explosion  expl;

    expl.config(100, -4, -3, 30, 40);
    expl.update(0, 0);
    expl.dump("");
}
