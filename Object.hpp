//
//  Object.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 2/1/21.
//

#ifndef Object_hpp
#define Object_hpp

#include "BlkGeo.hpp"
#include "BlkDisp.hpp"
#include "Explosion.hpp"


class Object {
    
public:
    const char *name;
    uint32_t    state;
    Vitality    vital;
    BlkGeo      block;      // Dimension, location, movement
    Explosion  *explsn;     // If the pointer is NULL, no explosion
    BlkDisp     disp;

    Object() {
        name = "No Name";
    }
    
    void set_name(const char *name);
};

#endif /* Object_hpp */
