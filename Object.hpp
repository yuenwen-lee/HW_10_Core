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
#include "Link.hpp"


typedef void (*DispFunc)(uint32_t time, uint32_t stat,
                         uint32_t num_disp, BlkDisp *disp);


class Object {
    
public:
    const char *name;
    Link        link;
    uint32_t    state;
    uint32_t    num_disp;
    BlkGeo      blk_geo;
    BlkDisp    *blk_disp;
    DispFunc    disp_func;
    
    Object() {
        link.set_ent((void *) this);
        num_disp = 0;
        blk_disp = NULL;
        disp_func = NULL;
    }
    
    void set_name(const char *name);
};

#endif /* Object_hpp */
