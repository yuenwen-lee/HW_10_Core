//
//  Rectangle_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 9/14/22.
//

#include <cstdio>
#include "Rectangle.hpp"


static void RectangleTest_OverlapCk_core(Rectangle &rec0, Rectangle &rec1)
{
    printf("   rec0: "); rec0.dump(); printf("\n");
    printf("   rec1: "); rec1.dump(); printf("\n");
    if (rec_overlap_check(rec0, rec1)) {
        printf("   overlap: YES\n");;
    } else {
        printf("   overlap: No!\n");;
    }
}


static void RectangleTest_Overlap_Check(void)
{
    Rectangle rec0, rec1;

    printf(">> Case A0, No OvLp <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 4,  9, 10, 13);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case B1, No OvLp (horizontally shadowed) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set(-1,  4, 10, 13);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case B1, No OvLp (vertically shadowed) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 4,  9, -1,  2);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case C0, No OvLp (corner touched) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 0,  5,  7, 10);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case C1, No OvLp (horizontally touched) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set(-2,  3,  7, 10);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case C2, No OvLp (vertically touched) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 0,  5, -1,  2);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case D0, Overlap Type A\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set(-2,  3,  6,  9);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");

    printf(">> Case D1, Overlap Type B\n");
    rec0.set(-7,  0,  0,  7);  // 7x7
    rec1.set(-6, -1,  2,  5);  // 5x3
    RectangleTest_OverlapCk_core(rec0, rec1);
    printf("\n");
}


static void RectangleTest_OverlapRec_core(Rectangle &rec0, Rectangle &rec1)
{
    Rectangle rec_ov;

    printf("   rec0: "); rec0.dump(); printf("\n");
    printf("   rec1: "); rec1.dump(); printf("\n");
    if (rec_overlap(rec0, rec1, rec_ov)) {
        printf("   overlap: YES\n");;
        printf("       rec: "); rec_ov.dump(); printf("\n");
    } else {
        printf("   overlap: No!\n");
    }
}


static void RectangleTest_Overlap(void)
{
    Rectangle rec0, rec1;

    printf(">> Case A0, No OvLp <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 4,  9, 10, 13);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case B1, No OvLp (horizontally shadowed) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set(-1,  4, 10, 13);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case B1, No OvLp (vertically shadowed) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 4,  9, -1,  2);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case C0, No OvLp (corner touched) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 0,  5,  7, 10);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case C1, No OvLp (horizontally touched) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set(-2,  3,  7, 10);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case C2, No OvLp (vertically touched) <<\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set( 0,  5, -1,  2);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case D0, Overlap Type A\n");
    rec0.set(-3,  0,  0,  7);  // 3x7
    rec1.set(-2,  3,  6,  9);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");

    printf(">> Case D1, Overlap Type B\n");
    rec0.set(-7,  0,  0,  7);  // 7x7
    rec1.set(-6, -1,  2,  5);  // 5x3
    RectangleTest_OverlapRec_core(rec0, rec1);
    printf("\n");
}


static void rec_collide_check_core(Rectangle &rec_A, Vec2D &vec_A,
                                   Rectangle &rec_B, Vec2D &vec_B)
{
    bool    ov;
    Segment tm;

    ov = rec_collide(rec_A, vec_A, rec_B, vec_B, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
}


void Rectangle_Test(void)
{
    printf("____________ !!!! Rectangle_test !!!! ____________\n\n");

    bool ov;
    Vec2D vec;
    Segment segX(-2, 1);
    Segment segY(5, 8);
    Segment tm;

    Rectangle rec0;
    Rectangle rec1(2, 3, 6, 11);
    Rectangle rec2(segX, segY);

    printf("rec1: "); rec1.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("\n");
    printf("\n");

    printf("== Test 1.0 copy(rec2) ===============================\n");
    rec0.set(rec2);
    printf("rec0: "); rec0.dump(); printf("\n");
    printf("\n\n");


    printf("== Test 2.0 shift(2, -1) ===============================\n");
    vec.set(2, -1);
    rec0.shift(vec);
    printf("rec0: "); rec0.dump(); printf("\n");
    printf("\n\n");


    printf("== Test 3.0 reset() ===============================\n");
    rec0.reset();
    printf("rec0: "); rec0.dump(); printf("\n");
    printf("\n\n");


    printf("== Test 4.0 overlap_check() ===============================\n");
    RectangleTest_Overlap_Check();
    printf("\n");


    printf("== Test 5.0 overlap_rec() ===============================\n");
    RectangleTest_Overlap();
    printf("\n");


    printf("== Test 6.0 collide() ===============================\n");
    Vec2D vec0, vec1, vec2;
    rec2.set(rec0);
    vec.set(1, 1);

    rec2.shift(vec);
    vec2.set(0, 0);
    vec0.set(0, 0);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");

    printf("== Test 6.1 collide() ==\n");
    rec2.set(rec0);
    vec.set(6, 8);
    rec2.shift(vec);
    vec2.set(0, 0);
    vec0.set(0, 0);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");

    printf("== Test 6.2 collide() ==\n");
    vec2.set(-3, -4);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");

    printf("== Test 6.3 collide() ==\n");
    vec2.set(3, 4);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");

    printf("== Test 6.4 collide() ==\n");
    vec2.set(3, -4);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");

    printf("== Test 6.5 collide() ==\n");
    rec2.set(2, 5, 8, 11);
    vec2.set(0, -4);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");

    printf("== Test 6.6 collide() ==\n");
    rec2.set(6, 9, 2, 5);
    vec2.set(-3, 0);
    printf("rec0: "); rec0.dump(); printf("   vec: "); vec0.dump(); printf("\n");
    printf("rec2: "); rec2.dump(); printf("   vec: "); vec2.dump(); printf("\n");
    rec_collide_check_core(rec0, vec0, rec2, vec2);
    printf("\n");
    printf("\n");


    printf("== Test 7.0 collide() ===============================\n");
    Rectangle recA, recB;
    Vec2D vecA, vecB;
    recA.set(0, 1, 0, 1);
    vecA.set(0, 0);

    recB.set(0, 1, 0, 1);
    vecB.set(-5, -5);
    printf("recA: "); recA.dump(); printf("   vec: "); vecA.dump(); printf("\n");
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(1, 2, 1, 2);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(2, 3, 2, 3);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(3, 4, 3, 4);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(4, 5, 4, 5);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(5, 6, 5, 6);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(6, 7, 6, 7);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");

    recB.set(7, 8, 7, 8);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    rec_collide_check_core(recA, vecA, recB, vecB);
    printf("\n");
    printf("\n");

    printf("== Test 7.1 collide() ==\n");
    recA.set(0, 1, 0, 1);
    vecA.set(0, 0);
    recB.set(0, 1, 0, 1);
    vecB.set(5, 5);
    printf("recA: "); recA.dump(); printf("   vec: "); vecA.dump(); printf("\n");
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(1, 2, 1, 2);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(2, 3, 2, 3);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(3, 4, 3, 4);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(4, 5, 4, 5);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(5, 6, 5, 6);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(6, 7, 6, 7);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    recB.set(7, 8, 7, 8);
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }
    printf("\n");


    printf("== Test 8.0 collide() ===============================\n");
    recA.set(0, 2, 0, 2);
    vecA.set(0, 0);
    recB.set(11, 12, 11, 12);
    vecB.set(-5, -5);
    printf("recA: "); recA.dump(); printf("   vec: "); vecA.dump(); printf("\n");
    printf("recB: "); recB.dump(); printf("   vec: "); vecB.dump(); printf("\n");
    ov = rec_collide(recA, vecA, recB, vecB, tm);
    if (ov) {
        printf("Collide_time: "); tm.dump(); printf("\n");
    } else {
        printf("Never collide ...\n");
    }

    printf("\n\n");
}


static void RecTest2_Setup(Rectangle &rec_0, uint32_t x0, uint32_t y0,
                           Rectangle &rec_1, uint32_t x1, uint32_t y1,
                           Vec2D &vec_0, Vec2D &vec_1, int32_t dt)
{
    int32_t x, y;

    x = (int32_t) x0;
    y = (int32_t) y0;
    rec_0.set(-x, x, -y, y);
    
    x = (int32_t) x1;
    y = (int32_t) y1;
    rec_1.set(-x, x, -y, y);

    Vec2D vec = vec_1 * dt;
    rec_1.shift(vec);

    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
}


void Rectangle_Test_2(void)
{
    Rectangle  rec_0, rec_1;
    uint32_t   x0, y0, x1, y1;
    Vec2D      vec_0, vec_1, vec;
    Segment    t_seg;
    int32_t    dt;

    printf("____________________ !!!! Rectangle_test !!!! ____________________\n\n");

    x0 = 6; y0 = 6;
    vec_0.set(0, 0);

    // Test case 1 - same size, move only on Y axis ................................
    printf("Test case 1 - same size, move only on Y axis .....................\n\n");
    
    x1 = 6; y1 = 6;
    vec_1.set(0, 1);
    dt = 0;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    dt = -12;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    vec_1.set(0, 3);
    dt = 0;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    dt = -4;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    printf("\n");
    
    // Test case 2 - different size, move only on Y axis ...........................
    printf("Test case 2 - different size, move only on X axis ................\n\n");
    x1 = 1; y1 = 1;
    vec_1.set(1, 0);
    dt = 0;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    dt = -12;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    vec_1.set(3, 0);
    dt = 0;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    dt = -4;
    RecTest2_Setup(rec_0, x0, y0, rec_1, x1, y1, vec_0, vec_1, dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    printf("\n");
    
    // Test case 3 - different size, move only on Y axis ...........................
    printf("Test case 3 - different size, move both on X and Y axis ..........\n\n");
    rec_1.set(4, 6, -6, -4);
    vec_1.set(1, 1);
    dt = 0;
    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    dt = -5;
    vec = vec_1 * dt;
    rec_1.shift(vec);
    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    vec_1.set(-1, 1);
    dt = 0;
    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");
    
    printf("\n");

    // Test case 4 - different size, will or will NOT collide ......................
    printf("Test case 4 - different size, will or will NOT collide ...........\n\n");
    rec_1.set(6, 8, -8, -6);
    vec_1.set(1, 1);
    dt = 0;
    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");

    vec_1.set(-1, 1);
    dt = 0;
    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");

    vec_1.set(-1, 4);
    dt = 0;
    printf("rec_0: "); rec_0.dump(); printf("  vec: "); vec_0.dump(); printf("\n");
    printf("rec_1: "); rec_1.dump(); printf("  vec: "); vec_1.dump(); printf("\n");
    printf("time: %d\n", dt);
    rec_collide_check_core(rec_0, vec_0, rec_1, vec_1);
    printf("\n");

    printf("\n\n");
}

