//
//  Explosion.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 10/28/23.
//

#ifndef Explosion_hpp
#define Explosion_hpp

#include <cstdint>
#include <cstdio>
#include "Vec2D.hpp"
#include "Geo2D.hpp"
#include "Rectangle.hpp"


class Explosion {
    bool        enable;         // explosion flag, when fully damaged
    Vec2D       orig_ofst;      // origin offset (against 'orig') of the
                                // explosion area
    Geo2D       exp_size;       // explosion area dimension
    Rectangle   exp_loc;        // explosion rectangle location

    uint32_t    damage;         // damage caused by explosion
};

/* ********************************************************************** *

 Note:
 (0) This is just a place holder ......
 (1) When the object explodes, the explosion will damage objects within
     its rectangle area.
 (2) If we leverage the BlkGeo, the calculation and interaction with other
     objects conceptually could be the same as object collision.
 (3) So, it is better to leverage the class BlkGeo, later .....

 * ********************************************************************** */

 #endif /* Explosion_hpp */
