//
//  Block.hpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/31/20.
//

#ifndef Block_hpp
#define Block_hpp

#include "Geo2D.hpp"
#include "Vec2D.hpp"
#include "Rectangle.hpp"


class BlkGeo {
    
public:
    const char *name;
    Vec2D       orig;           // <x0, y0>
    Geo2D       block_size;     // block dimension
    Rectangle   block_loc;      // location of the block
    Vec2D       speed;          //

    BlkGeo() {
        name = NULL;
        orig.set(0, 0);
        block_size.set(1, 1);
        speed.set(0, 0);
    }
    BlkGeo(const char *name) {
        this->name = name;
        orig.set(0, 0);
        block_size.set(1, 1);
        speed.set(0, 0);
    }
    BlkGeo(const char *name, int32_t x0, int32_t y0,
          int32_t size_x, int32_t size_y,
          int32_t speed_x, int32_t speed_y) {
        this->name = name;
        orig.set(x0, y0);
        block_size.set(size_x, size_y);
        speed.set(speed_x, speed_y);
        block_loc.set(x0, x0 + block_size.x, y0, y0 + block_size.y);
    }

    void dump(void);

    void set_name(const char *name);
    void block_loc_update(void);
    void set_orig(Vec2D &loc);
    void set_orig(int32_t x0, int32_t y0);
    void set_size(uint32_t size_x, uint32_t size_y);
    void set_speed(Vec2D &speed);
    void set_speed(int32_t x, int32_t y);

    void move_dtime(int32_t dt);
    void move_vec(Vec2D &vec);
};

bool blk_overlap_check(BlkGeo &bk0, BlkGeo &bk1);
bool blk_overlap(BlkGeo &bk0, BlkGeo &bk1, Rectangle &rec_ov);
bool blk_collide(BlkGeo &bk0, BlkGeo &bk1, Segment &t_seg);


void Block_test_static(void);


#endif /* Block_hpp */
