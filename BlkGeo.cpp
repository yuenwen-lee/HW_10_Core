//
//  Block.cpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/31/20.
//
#include <cstdio>
#include "BlkGeo.hpp"


// ................... set ................... //
void BlkGeo::set_name(const char *name)
{
    this->name = name;
}

void BlkGeo::block_loc_update(void)
{
    block_loc.set(orig.x, orig.x + block_size.x,
                  orig.y, orig.y + block_size.y);
}

void BlkGeo::set_orig(Vec2D &loc)
{
    orig = loc;
    block_loc_update();
}

void BlkGeo::set_orig(int32_t x0, int32_t y0)
{
    orig.set(x0, y0);
    block_loc_update();
}

void BlkGeo::set_size(uint32_t size_x, uint32_t size_y)
{
    block_size.set(size_x, size_y);
    block_loc_update();
}

void BlkGeo::set_speed(Vec2D &speed)
{
    this->speed = speed;
}

void BlkGeo::set_speed(int32_t x, int32_t y)
{
    speed.x = x;
    speed.y = y;
}

void BlkGeo::explosion_enable(bool same_size, uint32_t size_x, uint32_t size_y)
{
    exp_flag = true;

    if (same_size == true) {
        // the explosion area is the same as the object size
        exp_orig_ofst.set(0, 0);
        exp_size.x = block_size.x;
        exp_size.y = block_size.y;

    } else {
        // the explosion area is different to the object size
        exp_orig_ofst.x = (block_size.x - size_x) / 2;
        exp_orig_ofst.y = (block_size.y - size_y) / 2;
        exp_size.x = size_x;
        exp_size.y = size_y;
    }
}

void BlkGeo::exp_loc_update(void)
{
    Vec2D exp_orig = orig + exp_orig_ofst;
    exp_loc.set(exp_orig.x, exp_orig.x + exp_size.x,
                exp_orig.y, exp_orig.y + exp_size.y);
}

// ................... damage ................... //
void BlkGeo::set_life(uint32_t dmg)
{
    obj_life = dmg;
}

bool BlkGeo::destoryed(void)
{
    return (obj_life == 0);
}

// ................... move ................... //
void BlkGeo::move_dtime(int32_t dt)
{
    orig += (speed * dt);
    block_loc_update();
}

void BlkGeo::move_vec(Vec2D &vec)
{
    orig += vec;
    block_loc_update();
}


// ................... overlap ................... //
bool blk_overlap_check(BlkGeo &b0, BlkGeo &b1)
{
    return rec_overlap_check(b0.block_loc, b1.block_loc);
}

bool blk_overlap(BlkGeo &b0, BlkGeo &b1, Rectangle &rec_ov)
{
    return rec_overlap(b0.block_loc, b1.block_loc, rec_ov);
}


// ................... collision ................... //
bool blk_collide(BlkGeo &bk0, BlkGeo &bk1, Segment &time)
{
    return rec_collide(bk0.block_loc, bk0.speed,
                       bk1.block_loc, bk1.speed, time);
}


// ................... dump ................... //
void BlkGeo::dump(void)
{
    printf("Block Obj: %s\n", name);
    printf("  Orig     : "); orig.dump(); printf("\n");
    printf("  Size     : "); block_size.dump(); printf("\n");
    printf("  Block Loc: "); block_loc.dump(); printf("\n");
    printf("  Speed    : "); speed.dump(); printf("\n");
    printf("  Obj Life : %d\n", obj_life);
    printf("  Dmg Value: %d\n", dmg_val);
    printf("\n");
}
