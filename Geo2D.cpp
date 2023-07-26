//
//  geo2d.cpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/29/20.
//

#include <cstdio>
#include "Geo2D.hpp"


void Geo2D::set(int32_t x, int32_t y)
{
    this->x = x;
    this->y = y;
}

void Geo2D::dump(void)
{
    printf("<%d, %d>", x, y);
}


// .................... Testing Code Section .................... //
void Geo2D_test(void)
{
    printf("____________ !!!! Geo2D_test !!!! ____________\n\n");

    Geo2D geo(10, 20);
    Geo2D geo1(9, 11);
    Geo2D geo2(3, 5);

    printf("geo  "); geo.dump();  printf("\n");
    printf("geo1 "); geo1.dump(); printf("\n");
    printf("geo2 "); geo2.dump(); printf("\n");

    printf("\n");
}
