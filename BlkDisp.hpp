//
//  BlkDisp.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#ifndef BlkDisp_hpp
#define BlkDisp_hpp

#include "Segment.hpp"
#include "Geo2D.hpp"
#include "Vec2D.hpp"


using namespace::std;


class BlkDisp {

public:
    Geo2D           size;
    uint32_t        pxl_num;
    const uint8_t  *shape;
    Vec2D           location;

    BlkDisp() {
        size.set(0, 0);
        pxl_num = 0;
        shape = (uint8_t *) NULL;
    }
    BlkDisp(int32_t x, int32_t y, uint32_t color, const uint8_t *shape) {
        this->size.set(x, y);
        this->pxl_num = x * y;
        this->shape = new uint8_t[pxl_num];
        this->shape = shape;
    };

    void set_size(Geo2D &size);
    void set_size(int32_t x, int32_t y);
    void set_shape(const uint8_t *shape);
    void draw(int32_t x, int32_t y);
    void erase(void);
};


extern const Segment canvas_x;
extern const Segment canvas_y;


#endif /* BlkDisp_hpp */
