///Users/ywlee/prog/Xcode Project/Homework C++/HW_10.0/HW_10.0/main.cpp
//  Segment_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 9/12/22.
//

#include <cstdio>
#include <math.h>
#include "Segment.hpp"


#define  bool_str(a)    ((a) ? "true" : "false")


static void SegmentTest_floor(int32_t a, int32_t b)
{
    int32_t  ans, test;

    ans = (int32_t) floor((double_t) a / (double_t) b);
    test = floor_div(a, b);

    if (test != ans) {
        printf("   Fail: floor_div(%d, %d) = %d, Not %d !!!\n", a, b, ans, test);
    } else {
        printf("   Pass: floor_div(%d, %d) = %d\n", a, b, test);
    }
}


static void SegmentTest_ceil(int32_t a, int32_t b)
{
    int32_t  ans, test;

    ans = (int32_t) ceil((double_t) a / (double_t) b);
    test = ceil_div(a, b);

    if (test != ans) {
        printf("   Fail: ceil_div(%d, %d) = %d, Not %d !!!\n", a, b, ans, test);
    } else {
        printf("   Pass: ceil_div(%d, %d) = %d\n", a, b, test);
    }
}


static void SegmentTest_floor_div(void)
{
    printf("== Case A ==\n");
    SegmentTest_floor(  1,   3);
    SegmentTest_floor( -1,  -3);
    SegmentTest_floor(  1,  -3);
    SegmentTest_floor( -1,   3);
    printf("\n");

    printf("== Case B ==\n");
    SegmentTest_floor( 10,   3);
    SegmentTest_floor(-10,  -3);
    SegmentTest_floor( 10,  -3);
    SegmentTest_floor(-10,   3);
    printf("\n");

    printf("== Case C ==\n");
    SegmentTest_floor( 11,   3);
    SegmentTest_floor(-11,  -3);
    SegmentTest_floor( 11,  -3);
    SegmentTest_floor(-11,   3);
    printf("\n");

    printf("== Case D ==\n");
    SegmentTest_floor( 12,   3);
    SegmentTest_floor(-12,  -3);
    SegmentTest_floor( 12,  -3);
    SegmentTest_floor(-12,   3);
    printf("\n");

    printf("== Case E ==\n");
    SegmentTest_floor( 13,   3);
    SegmentTest_floor(-13,  -3);
    SegmentTest_floor( 13,  -3);
    SegmentTest_floor(-13,   3);
    printf("\n");
}


static void SegmentTest_ceil_div(void)
{
    printf("== Case A ==\n");
    SegmentTest_ceil(  1,   3);
    SegmentTest_ceil( -1,  -3);
    SegmentTest_ceil(  1,  -3);
    SegmentTest_ceil( -1,   3);
    printf("\n");

    printf("== Case B ==\n");
    SegmentTest_ceil( 10,   3);
    SegmentTest_ceil(-10,  -3);
    SegmentTest_ceil( 10,  -3);
    SegmentTest_ceil(-10,   3);
    printf("\n");

    printf("== Case C ==\n");
    SegmentTest_ceil( 11,   3);
    SegmentTest_ceil(-11,  -3);
    SegmentTest_ceil( 11,  -3);
    SegmentTest_ceil(-11,   3);
    printf("\n");

    printf("== Case D ==\n");
    SegmentTest_ceil( 12,   3);
    SegmentTest_ceil(-12,  -3);
    SegmentTest_ceil( 12,  -3);
    SegmentTest_ceil(-12,   3);
    printf("\n");

    printf("== Case E ==\n");
    SegmentTest_ceil( 13,   3);
    SegmentTest_ceil(-13,  -3);
    SegmentTest_ceil( 13,  -3);
    SegmentTest_ceil(-13,   3);
    printf("\n");
}


static void SegmentTest_overlap_core(Segment &seg0, Segment &seg1)
{
    Segment seg_ov;

    printf("   seg0: "); seg0.dump(); printf("\n");
    printf("   seg1: "); seg1.dump(); printf("\n");
    if (seg_overlap(seg0, seg1, seg_ov)) {
        printf("   overlap: YES\n");
        printf("   OvSg: "); seg_ov.dump(); printf("\n");
    } else {
        printf("   overlap: No!\n");
    }
}


static void SegmentTest_overlap(void)
{
    Segment seg0, seg1;

    printf("== Case A0, No OvLp ==\n");
    seg0.set(15, 19);
    seg1.set(0, 9);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case A1, No OvLp (boundary) ==\n");
    seg0.set(9, 11);
    seg1.set(0, 9);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case A2, No OvLp (boundary) ==\n");
    seg0.set(9, 11);
    seg1.set(11, 12);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case B0, OvLp (type A) ==\n");
    seg0.set(7, 11);
    seg1.set(0, 9);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case B1, OvLp (type B) ==\n");
    seg0.set(0, 9);
    seg1.set(7, 11);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case C0, OvLp (fully Shadowed) ==\n");
    seg0.set(-5, 13);
    seg1.set(0, 9);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case C1, OvLp (fully Shadowed + boundary) ==\n");
    seg0.set(-5, 13);
    seg1.set(7, 13);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case X0, No OvLp (boundary) ==\n");
    seg0.set(1, 2);
    seg1.set(2, 3);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case X1, OvLp (fully Shadowed + boundary) ==\n");
    seg0.set(2, 3);
    seg1.set(2, 3);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case X2, No OvLp (boundary) ==\n");
    seg0.set(3, 4);
    seg1.set(2, 3);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");

    printf("== Case X2, No OvLp (simple..) ==\n");
    seg0.set(4, 5);
    seg1.set(2, 3);
    SegmentTest_overlap_core(seg0, seg1);
    printf("\n");
}


static void SegmentTest_collide_float_core(Segment &sa, int32_t speed_a,
                                           Segment &sb, int32_t speed_b,
                                           double_t *t0_p, double_t *t1_p)
{
    if (speed_a == speed_b) {
        // both segments are stationary relatively
        *t0_p = *t1_p = NAN;
        return;
    }

    double_t speed;
    double_t dst_0, dst_1;

    speed = (double_t) speed_a - (double_t) speed_b;
    dst_0 = (double_t) sb.p0 - (double_t) sa.p1;
    dst_1 = (double_t) sb.p1 - (double_t) sa.p0;

    double_t t0 = dst_0 / speed;
    double_t t1 = dst_1 / speed;
    if (t0 < t1) {
        *t0_p = t0;
        *t1_p = t1;
    } else {
        *t0_p = t1;
        *t1_p = t0;
    }
}


static bool SegmentTest_collide_float(Segment &sa, int32_t speed_a,
                                      Segment &sb, int32_t speed_b, Segment &time)
{
    if (speed_a == speed_b) {
        // both segments are relative stationary
        if (seg_overlap_check(sa, sb)) {
            time.p0 = INT32_MIN;
            time.p1 = INT32_MAX;
            return true;
        } else {
            time.p0 = INT32_MAX - 1;
            time.p1 = INT32_MAX;
            return false;
        }
    }

    double_t  t0, t1;
    SegmentTest_collide_float_core(sa, speed_a, sb, speed_b, &t0, &t1);
    if (t0 < t1) {
        time.p0 = (int32_t) floor(t0);
        time.p1 = (int32_t) ceil(t1);
    } else {
        time.p0 = (int32_t) floor(t1);
        time.p1 = (int32_t) ceil(t0);
    }
    return true;
}


static void SegmentTest_collide_core(Segment &sa, int32_t speed_a,
                                     Segment &sb, int32_t speed_b)
{
    Segment  tSeg_ans, tSeg;
    bool     chk_ans, chk;

    chk = seg_collide(sa, speed_a, sb, speed_b, tSeg);
    chk_ans = SegmentTest_collide_float(sa, speed_a, sb, speed_b, tSeg_ans);

    double_t t0, t1;
    SegmentTest_collide_float_core(sa, speed_a, sb, speed_b, &t0, &t1);

    printf("   Seg_0 - "); sa.dump(); printf(", speed %d\n", speed_a);
    printf("   Seg_1 - "); sb.dump(); printf(", speed %d\n", speed_b);
    if (chk == chk_ans && tSeg.equal_to(tSeg_ans)) {
        printf("   Pass: %s, ", bool_str(chk)); tSeg.dump(); printf("\n");
        printf("            [%f, %f]\n", t0, t1);
    } else {
        printf("   Fail: ans  -> %s, ", bool_str(chk_ans)); tSeg_ans.dump(); printf("\n");
        printf("            [%f, %f]\n", t0, t1);
        printf("         test -> %s, ", bool_str(chk));     tSeg.dump(); printf("\n");
    }
}


static void SegmentTest_collide(void)
{
    Segment seg0, seg1;
    int32_t speed0, speed1;

    printf("== Both stationary ==\n");
    // same speed, both zero .................................
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(-11, (-11 + 5));
    speed1 = 0;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // same speed, both non-zero
    seg0.set(0, 11);
    speed0 = 100;
    seg1.set(5, (5 + 5));
    speed1 = 100;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");

    printf("== No OvLp, collide in the future ==\n");
    // no overlap, collide in the future, case A .............
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(-11, (-11 + 5));
    speed1 = 5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // no overlap, collide in the future, case B
    seg0.set(0, 11);
    speed0 = -5;
    seg1.set(-11, (-11 + 5));
    speed1 = 0;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // no overlap, collide in the future, case C
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(-5, (-5 + 5));
    speed1 = 5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");

    printf("== No OvLp, collide in the past ==\n");
    // no overlap, collided in the past, case A ..............
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(-11, (-11 + 5));
    speed1 = -5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // no overlap, collided in the past, case B
    seg0.set(0, 11);
    speed0 = 5;
    seg1.set(-11, (-11 + 5));
    speed1 = 0;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // no overlap, collide in the past, case C
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(11, (11 + 5));
    speed1 = 5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");


    printf("== OvLp, collide already happened ==\n");
    // overlapped, case A ....................................
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(7, (7 + 5));
    speed1 = 5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // overlapped, case B
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(7, (7 + 5));
    speed1 = -5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");

    printf("== OvLp (Shadowed), collide already happened ==\n");
    // overlapped, case A ....................................
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(3, (3 + 5));
    speed1 = 5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
    // overlapped, case B
    seg0.set(0, 11);
    speed0 = 0;
    seg1.set(3, (3 + 5));
    speed1 = -5;
    SegmentTest_collide_core(seg0, speed0, seg1, speed1);
    printf("\n");
}


/* ..............................................................
 * .................... Testing Code Section ....................
 * .............................................................. */

void Segment_test(void)
{
    Segment seg0;
    Segment seg1(0, 9);

    printf("____________ !!!! Segment_test !!!! ____________\n\n");

    printf("==== Test 0.0 - floor_div() ====\n");
    SegmentTest_floor_div();
    printf("\n");

    printf("==== Test 0.1 - ceil_div() ====\n");
    SegmentTest_ceil_div();
    printf("\n");

    printf("==== Test 1.0 - segP = new Segment(11, 22); ====\n");
    Segment *segP;
    segP = new Segment(11, 22);
    printf("  segP: "); segP->dump(); printf("\n");
    delete segP;
    printf("\n");

    printf("==== Test 1.1 - segP = new Segment(seg1); ====\n");
    segP = new Segment(seg1);
    printf("  seg1: "); seg1.dump(); printf("\n");
    printf("  segP: "); segP->dump(); printf("\n");
    delete segP;
    printf("\n");

    printf("==== Test 2.0 - seg0.set(seg1); ====\n");
    seg0.set(seg1);
    printf("  seg0: "); seg0.dump(); printf("\n");
    printf("  seg1: "); seg1.dump(); printf("\n");
    printf("\n");

    printf("==== Test 3.0 - overlap() ====\n");
    SegmentTest_overlap();
    printf("\n");

    printf("==== Test 4.0 - collide() ====\n");
    SegmentTest_collide();
    printf("\n");

    printf("\n");
}
