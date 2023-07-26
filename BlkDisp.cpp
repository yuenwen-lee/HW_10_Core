//
//  BlkDisp.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 1/30/21.
//

#include "BlkDisp.hpp"


void BlkDisp::set_size(Geo2D &size)
{
    this->size.set(size.x, size.y);
}

void BlkDisp::set_size(int32_t x, int32_t y)
{
    this->size.set(x, y);
}

void BlkDisp::set_shape(const uint8_t *shape)
{
    this->shape = shape;
}

void BlkDisp::draw(int32_t x, int32_t y)
{
    location.set(x, y);
}

void BlkDisp::erase(void)
{
    
}
