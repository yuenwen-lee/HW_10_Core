//
//  Vec2D.cpp
//  HW_01.0
//
//  Created by Yuen-Wen Lee on 12/29/20.
//

#include <cstdio>
#include "Vec2D.hpp"


void Vec2D::dump(void)
{
    printf("<%d, %d>", x, y);
}


// .................... Testing Code Section .................... //
void Vec2D_test(void)
{
    printf("____________ !!!! Vec2D_test !!!! ____________\n");

    Vec2D vec1(11, 22);
    Vec2D vec2(7, 9);
    Vec2D vec3;
    Vec2D vec;

    vec3 = vec1 % 3;
//  vec3 = vec2;
    
    printf("vec1: "); vec1.dump(); printf("\n");
    printf("vec2: "); vec2.dump(); printf("\n");
    printf("vec3: "); vec3.dump(); printf("\n");
    printf("\n");

    printf("________ Test 1.0, vec3 += vec1; _______________\n");
    vec3 += vec1;
    printf("   vec3: "); vec3.dump(); printf("\n");
    printf("\n");

    printf("________ Test 2.0, vec = vec1; _________________\n");
    vec = vec1;
    printf("   vec: "); vec.dump(); printf("\n");
    printf("\n");

    printf("________ Test 3.0, vec = vec + vec2; ___________\n");
    vec = vec + vec2;
    printf("   vec: "); vec.dump(); printf("\n");
    printf("\n");

    printf("________ Test 4.0, vec -= vec2; ________________\n");
    vec -= vec2;
    printf("   vec: "); vec.dump(); printf("\n");
    printf("\n");

    printf("________ Test 5.0 vec *= 10; ___________________\n");
    vec *= 10;
    printf("   vec: "); vec.dump(); printf("\n");
    printf("\n");

    printf("\n");
}
