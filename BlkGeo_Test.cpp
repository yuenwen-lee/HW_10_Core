#include <cstdio>
#include "BlkGeo.hpp"


// .................... Testing .................... //
void Block_test_static(void)
{
    printf("____________ !!!! Block_test_static !!!! ____________\n\n");

    Rectangle ov_rec;
    bool ov;

    printf("====== Test 0.0 ======\n");
    BlkGeo bk1("Simple", 0, 0, 12, 12, 0, 0);
    BlkGeo bk2("Easy");
    bk2.set_orig(2, 2);
    bk2.set_size(8, 8);
    bk2.set_speed(1, 1);
    bk1.dump();
    bk2.dump();

    printf("====== Test 1.0 ======\n");
    ov = blk_overlap(bk1, bk2, ov_rec);
    bk1.dump();
    bk2.dump();
    printf("ov: %s\n", (ov ? "true" : "false"));
    if (ov) {
        printf("ov_rec: "); ov_rec.dump(); printf("\n");
    }
    printf("\n");

    printf("====== Test 2.0 ======\n");
    bk2.set_orig(0, 0);
    ov = blk_overlap(bk1, bk2, ov_rec);
    bk1.dump();
    bk2.dump();
    printf("ov: %s\n", (ov ? "true" : "false"));
    if (ov) {
        printf("ov_rec: "); ov_rec.dump(); printf("\n");
    }
    printf("\n");

    printf("====== Test 3.0 ======\n");
    bk2.move_dtime(100);
    ov = blk_overlap(bk1, bk2, ov_rec);
    bk1.dump();
    bk2.dump();
    printf("ov: %s\n", (ov ? "true" : "false"));
    if (ov) {
        printf("ov_rec: "); ov_rec.dump(); printf("\n");
    }
    printf("\n");

    printf("\n");
}


#if 0   // The following test code is obsolete ...........................

void Block_test_dynamic(void)
{
    printf("____________ !!!! Block_test_dynamic !!!! ____________\n\n");

    bool in_window;
    Rectangle window(0, 240, 0, 320);

    BlkGeo mssl("Missle",  26,  0,  1, 4, 1, 1);
    BlkGeo shlt("Shelter", 20, 10, 13, 6, 0, 0);

    mssl.dump();
    shlt.dump();
    printf("Area: "); window.dump(); printf("\n");
    printf("\n");

    bool ov;
    Segment t_seg, t_cld, t_ov;
    Rectangle ov_rec;
    const uint32_t dtime = 4;
    const uint32_t slice = 4;

    uint32_t n = 0;
    bool cld;
    do {

        // move the object ................................. (A)
        mssl.move_dtime(dtime);
        shlt.move_dtime(dtime);

        // set the time duration ........................... (B)
        t_seg.set(-dtime + 1, 0);

        // estimate the collision time ..................... (C)
        blk_collide(mssl, shlt, t_cld);
        cld = seg_overlap(t_cld, t_seg, t_ov);
        printf(".......................................\n");
        printf("time stamp : %d: ", n);
        if (cld) {
            printf("OV - ");
        } else {
            printf("__ - ");
        }
        printf(": t_seg: "); t_seg.dump();
        printf(", t_cld: "); t_cld.dump();
        printf(", t_ov: "); t_ov.dump();
        printf("\n");

        // Evaluate the damage withing overlap time ........ (D)
        if (cld) {
            uint32_t dt = t_ov.len() / slice;
            if (dt == 0) {
                dt = 1;
            }

            mssl.move_dtime(t_ov.p0);
            shlt.move_dtime(t_ov.p0);
            int32_t tt;
            for (tt = t_ov.p0; tt <= t_ov.p1; tt += dt) {
                ov = blk_overlap(mssl, shlt, ov_rec);
                if (ov) {
                }
                mssl.move_dtime(dt);
                shlt.move_dtime(dt);
            }
            if ((tt - t_ov.p1) < dt) {
                // FIXME .............................
            }
        }

        ov = blk_overlap(mssl, shlt, ov_rec);
        if (ov) {
        }
        mssl.dump();
        shlt.dump();
        printf("\n");

        in_window = rec_overlap_check(mssl.block_loc, window);
        n++;
    } while (in_window && !mssl.destoryed() && (n < 20));

    if (mssl.destoryed()) {
        printf("%s is destroyed\n", mssl.name);
    } else {
        printf("%s is GOOD\n", mssl.name);
    }

    printf("\n\n");
    printf("Time: %d\n", n);
    mssl.dump();
    shlt.dump();

    printf("\n");
}

#endif // The following test code is obsolete ...........................
