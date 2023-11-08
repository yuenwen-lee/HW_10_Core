//
//  Collision2_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/2/23.
//

#include <cstdio>
#include "Collision.hpp"


void ClsnItem_Test(void)
{
    printf("____________ !!!! ClsnItem_Test !!!! ________________________________\n\n");

    ClsnItem info1, info2, info3, info4;
    int32_t  vtal1, vtal2, vtal3, vtal4;

    vtal1 = 111;
    vtal2 = 222;
    vtal3 = 333;
    vtal4 = 444;

    info1.set(&vtal1, 10, &vtal2, 20, 1);
    info2.set(&vtal2, 20, &vtal3, 30, 2);
    info3.set(&vtal3, 30, &vtal4, 40, 3);
    info4.set(&vtal4, 40, &vtal1, 10, 4);

    Link  head(1100);
    
    head.insert_prev(&info1.link);
    head.insert_prev(&info2.link);
    head.insert_prev(&info3.link);
    head.insert_prev(&info4.link);

    printf("Dump ClsnItem: \n");
    info1.dump("  ");
    info2.dump("  ");
    info3.dump("  ");
    info4.dump("  ");
    printf("\n");

    ClsnItem *info_p = (ClsnItem *) info1.link.get_ent();
    info_p->dump("  ");
    
    printf("\n\n");
}

void ClsnList_Test(void)
{
    printf("____________ !!!! ClsnList_Test !!!! ________________________________\n\n");
    
    ClsnList clsn_list;

    int32_t  v_missl_0, v_missl_1, v_shltr_0, v_shltr_1;
    int32_t  v_missl_Z, v_shltr_Z, v_alien_A, v_aa_gun;

    uint32_t d_missl, d_shltr;
    int32_t  v_missl, v_shltr;

    v_missl =  3;
    d_missl = 30;
    v_shltr = 40;
    d_shltr =  4;

    v_alien_A = 40;
    v_aa_gun = 30;

    v_missl_0 = v_missl_1 = v_missl_Z = v_missl;
    v_shltr_0 = v_shltr_1 = v_shltr_Z = v_shltr;

    Segment t_seg;

    printf("........ Test 0.0 - Init : 8 info     .............................\n");
    printf("                  - t_seg: [10 ~ 30]  .............................\n");
    printf("\n");
    clsn_list.config(8);
    clsn_list.set_t_seg(10, 30);
    clsn_list.dump_all();

    printf("........ Test 1.a - Add: Alien_A + AA_Gun [  8 ~ 15] ...............\n");
    t_seg.set( 8, 15);
    clsn_list.add(&v_alien_A, 10, &v_aa_gun, 20, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 2.a - Add: Misl_0 + Shltr_0 [ 10 ~ 12] ...............\n");
    t_seg.set(10, 12);
    clsn_list.add(&v_missl_0, d_missl, &v_shltr_0, d_shltr, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 2.x - Add: Shltr_0 + Misl_0 (Dup ...) ...............\n");
    clsn_list.add(&v_shltr_0, d_shltr, &v_missl_0, d_missl, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 2.b - Add: Misl_0 + Shltr_1 [18 ~ 21] ...............\n");
    t_seg.set(18, 21);
    clsn_list.add(&v_missl_0, d_missl, &v_shltr_1, d_shltr, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 3.a - Add: Shltr_0 + Misl_1 [11 ~ 14] ...............\n");
    t_seg.set(11, 14);
    clsn_list.add(&v_shltr_0, d_shltr, &v_missl_1, d_missl, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 3.b - Add: Shltr_1 + Misl_1 [20 ~ 23] ...............\n");
    t_seg.set(20, 23);
    clsn_list.add(&v_shltr_1, d_shltr, &v_missl_1, d_missl, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 4.a - Add: Misl_Z + Shltr_1 [22 ~ 28] ...............\n");
    t_seg.set(22, 28);
    clsn_list.add(&v_shltr_1, d_shltr, &v_missl_Z, d_missl, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test 4.b - Add: Misl_Z + Shltr_Z [30 ~ 35] ...............\n");
    t_seg.set(30, 35);
    clsn_list.add(&v_shltr_Z, d_shltr, &v_missl_Z, d_missl, t_seg.p0);
    clsn_list.dump_clsnList();

    printf("........ Test X.0 - Before Process ................................\n");
    clsn_list.dump_all();

    printf("........ Test Y.0 - Process the CollisionList .....................\n");
    clsn_list.proc();
    clsn_list.dump_all();

    printf("........ Test Z.Z - Dump all OBJ ..................................\n");
    printf("Missl 0: %d\n", v_missl_0);
    printf("Missl 1: %d\n", v_missl_1);
    printf("Missl Z: %d\n", v_missl_Z);
    printf("Shltr 0: %d\n", v_shltr_0);
    printf("Shltr 1: %d\n", v_shltr_1);
    printf("Shltr Z: %d\n", v_shltr_Z);
    printf("Alien A: %d\n", v_alien_A);
    printf("AA Gun : %d\n", v_aa_gun );

    printf("\n\n");
}

void ClsnList_Test_2(void)
{
    ClsnList clsn_list;

    printf("____________ !!!! ClsnList_Test_2 !!!! ______________________________\n\n");

    BlkGeo   missl("Missle_0",  20,  10,   4,  10,  0, 10);
    BlkGeo   shltr("Shelter",   18, 100,  20,  10,  0,  0);
    int32_t  v_missl, v_shltr;
    uint32_t d_missl, d_shltr;

    clsn_list.config(8);

    v_missl =  10;  v_shltr = 200;
    d_missl = 300;  d_shltr =   6;

    missl.dump();
    printf("  vtal: %d\n",   v_missl);
    printf("  damg: %d\n\n", d_missl);
    shltr.dump();
    printf("  vtal: %d\n",   v_shltr);
    printf("  damg: %d\n\n", d_shltr);

    printf("__________ !!!!!! Start Simulation !!!!!! __________\n\n");

    int d_time = 1;
    clsn_list.set_t_seg(-d_time, 0);

    for (int time = 0; time < 14; time += d_time) {

        clsn_list.clean();
        printf("____________ Time: [%d, %d] ________________________\n\n",
               time, (time + d_time));

        missl.dump();
        printf("  vtal: %d\n",   v_missl);
        printf("  damg: %d\n\n", d_missl);
        shltr.dump();
        printf("  vtal: %d\n",   v_shltr);
        printf("  damg: %d\n\n", d_shltr);

        if (v_missl > 0 && v_shltr > 0) {

            Segment t_cld;
            bool cld = blk_collide(missl, shltr, t_cld);
            if (cld) {
                printf("Collission: "); t_cld.dump(); printf("\n\n");

                if (clsn_list.add(&v_missl, d_missl, &v_shltr, d_shltr, t_cld.p0)) {

                    printf("..... Before Process .......................\n");
                    clsn_list.dump_clsnList();

                    printf("..... After Process ........................\n");
                    clsn_list.proc();
                    clsn_list.dump_clsnList();

                    missl.dump();
                    printf("  vtal: %d\n",   v_missl);
                    printf("  damg: %d\n\n", d_missl);
                    shltr.dump();
                    printf("  vtal: %d\n",   v_shltr);
                    printf("  damg: %d\n\n", d_shltr);
                }
            }
        }

        if (v_missl > 0) {
            missl.move_dtime(d_time);
        }
        if (v_shltr > 0) {
            shltr.move_dtime(d_time);
        }
    }

    printf("\n\n");
}

void ClsnList_Test_Sort(void)
{
    printf("____________ !!!! ClstList_Test_Sort !!!! ___________________________\n\n");

    ClsnList clsnList;

    int32_t  v_A0, v_A1, v_A2;
    int32_t  v_B0, v_B1;
    int32_t  v_C0, v_C1, v_C2;

    v_A0 = 1000;
    v_A1 = 1001;
    v_A2 = 1002;

    v_B0 = 2000;
    v_B1 = 2010;

    v_C0 = 3000;
    v_C1 = 3100;
    v_C2 = 3200;

    clsnList.config(12);
    clsnList.set_t_seg(-10, 80);   // 10 ~ 30
    printf("---------- Time Slot [10, 30]\n");
    printf("\n");
    
    Segment t_seg;

    t_seg.set(13, 28);
    clsnList.add(&v_A0, 10, &v_A2, 12, t_seg.p0);
    printf("---------- Insert [%d, %d] - A0, A2\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    t_seg.set(10, 22);
    clsnList.add(&v_A1, 11, &v_A2, 12, t_seg.p0);
    printf("---------- Insert [%d, %d] - A1, A2\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    t_seg.set(30, 36);
    clsnList.add(&v_B0, 20, &v_B1, 21, t_seg.p0);
    printf("---------- Insert [%d, %d] - B0, B1\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    t_seg.set( 9, 12);
    clsnList.add(&v_C0, 30, &v_C2, 32, t_seg.p0);
    printf("---------- Insert [%d, %d] - C0, C2\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    t_seg.set(15, 18);
    clsnList.add(&v_C0, 30, &v_C1, 31, t_seg.p0);
    printf("---------- Insert [%d, %d] - C0, C1\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    printf("========== Duplicated Collison Info ==========\n\n");

    t_seg.set(10, 22);
    clsnList.add(&v_A2, 12, &v_A1, 11, t_seg.p0);
    printf("---------- Insert [%d, %d] - A2, A1\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    t_seg.set(15, 18);
    clsnList.add(&v_C1, 31, &v_C0, 30, t_seg.p0);
    printf("---------- Insert [%d, %d] - C1, C0\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    t_seg.set(30, 36);
    clsnList.add(&v_B1, 21, &v_B0, 20, t_seg.p0);
    printf("---------- Insert [%d, %d] - B1, B0\n", t_seg.p0, t_seg.p1);
    clsnList.dump_clsnList();

    printf("========== Dump ALL ==========================\n\n");
    clsnList.dump_all();

    printf("\n\n");
}
