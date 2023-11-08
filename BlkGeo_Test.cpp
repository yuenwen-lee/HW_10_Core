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
    bk2.set_orig(6, 6);
    bk2.set_size(8, 8);
    bk2.set_speed(1, 1);
    bk1.dump();
    bk2.dump();
    printf("\n");

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
