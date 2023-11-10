//
//  Collision2_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/2/23.
//

#include <cstdio>
#include "Damage.hpp"
#include "Vitality.hpp"


void DamgPair_Test(void)
{
    printf("____________ !!!! %s !!!! ________________________________\n\n",
           __FUNCTION__);

    DamgPair pair1, pair2, pair3, pair4;
    Vitality vtal1, vtal2, vtal3, vtal4;

    vtal1.init(111, 10);
    vtal2.init(222, 20);
    vtal3.init(333, 30);
    vtal4.init(444, 40);

    pair1.set(&vtal1, &vtal2, 1);
    pair2.set(&vtal2, &vtal3, 2);
    pair3.set(&vtal3, &vtal4, 3);
    pair4.set(&vtal4, &vtal1, 4);

    Link  head(1100);
    
    head.insert_prev(&pair1.link);
    head.insert_prev(&pair2.link);
    head.insert_prev(&pair3.link);
    head.insert_prev(&pair4.link);

    printf("Dump DamgPair: \n");
    pair1.dump("  ");
    pair2.dump("  ");
    pair3.dump("  ");
    pair4.dump("  ");
    printf("\n");

    DamgPair *pair_p = (DamgPair *) pair1.link.get_ent();
    pair_p->dump("  ");
    
    printf("\n\n");
}

void DamgList_Test(void)
{
    printf("____________ !!!! %s !!!! ________________________________\n\n",
           __FUNCTION__);
    
    DamgList damg_list;

    Vitality v_missl_0, v_missl_1, v_shltr_0, v_shltr_1;
    Vitality v_missl_Z, v_shltr_Z, v_alien_A, v_aa_gun;

    v_missl_0.init(3, 30);
    v_missl_1.init(3, 30);
    v_missl_Z.init(3, 30);

    v_shltr_0.init(40, 4);
    v_shltr_1.init(40, 4);
    v_shltr_Z.init(40, 4);

    v_alien_A.init(40, 19);
    v_aa_gun.init(30, 20);

    Segment t_seg;

    printf("........ Test 0.0 - Init : 8 pair     .............................\n");
    printf("                  - t_seg: [10 ~ 30]  .............................\n");
    printf("\n");
    damg_list.config(8);
    damg_list.set_t_seg(10, 30);
    damg_list.dump();

    printf("........ Test 1.a - Add: Alien_A + AA_Gun [  8 ~ 15] ...............\n");
    t_seg.set( 8, 15);
    damg_list.add(&v_alien_A, &v_aa_gun, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 2.a - Add: Misl_0 + Shltr_0 [ 10 ~ 12] ...............\n");
    t_seg.set(10, 12);
    damg_list.add(&v_missl_0, &v_shltr_0, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 2.x - Add: Shltr_0 + Misl_0 (Dup ...) ...............\n");
    damg_list.add(&v_shltr_0, &v_missl_0, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 2.b - Add: Misl_0 + Shltr_1 [18 ~ 21] ...............\n");
    t_seg.set(18, 21);
    damg_list.add(&v_missl_0, &v_shltr_1, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 3.a - Add: Shltr_0 + Misl_1 [11 ~ 14] ...............\n");
    t_seg.set(11, 14);
    damg_list.add(&v_shltr_0, &v_missl_1, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 3.b - Add: Shltr_1 + Misl_1 [20 ~ 23] ...............\n");
    t_seg.set(20, 23);
    damg_list.add(&v_shltr_1, &v_missl_1, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 4.a - Add: Misl_Z + Shltr_1 [22 ~ 28] ...............\n");
    t_seg.set(22, 28);
    damg_list.add(&v_shltr_1, &v_missl_Z, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test 4.b - Add: Misl_Z + Shltr_Z [30 ~ 35] ...............\n");
    t_seg.set(30, 35);
    damg_list.add(&v_shltr_Z, &v_missl_Z, t_seg.p0);
    damg_list.dump_list();

    printf("........ Test X.0 - Before Process ................................\n");
    damg_list.dump();

    printf("........ Test Y.0 - Process the CollisionList .....................\n");
    damg_list.proc();
    damg_list.dump();

    printf("........ Test Z.Z - Dump all OBJ ..................................\n");
    printf("Missl 0 -\n"); v_missl_0.dump("  ");
    printf("Missl 1 -\n"); v_missl_1.dump("  ");
    printf("Missl Z -\n"); v_missl_Z.dump("  ");

    printf("Shltr 0 -\n"); v_shltr_0.dump("  ");
    printf("Shltr 1 -\n"); v_shltr_1.dump("  ");
    printf("Shltr Z -\n"); v_shltr_Z.dump("  ");

    printf("Alien A -\n"); v_alien_A.dump("  ");
    printf("AA Gun -\n");  v_aa_gun.dump("  ");

    printf("\n\n");
}

void DamgList_Test_2(void)
{
    DamgList damg_list;

    printf("____________ !!!! %s !!!! ______________________________\n\n",
           __FUNCTION__);

    BlkGeo   missl("Missle_0",  20,  10,   4,  10,  0, 10);
    BlkGeo   shltr("Shelter",   18, 100,  20,  10,  0,  0);
    Vitality v_missl, v_shltr;

    damg_list.config(8);

    v_missl.init( 10, 300);
    v_shltr.init(200,   6);

    missl.dump(); v_missl.dump("  ");
    shltr.dump(); v_shltr.dump("  ");

    printf("__________ !!!!!! Start Simulation !!!!!! __________\n\n");

    int d_time = 1;
    damg_list.set_t_seg(-d_time, 0);

    for (int time = 0; time < 14; time += d_time) {

        damg_list.clean();
        printf("____________ Time: [%d, %d] ________________________\n\n",
               time, (time + d_time));

        missl.dump(); v_missl.dump("  ");
        shltr.dump(); v_shltr.dump("  ");
        printf("\n");

        if (v_missl.alived() && v_shltr.alived()) {

            Segment t_cld;
            bool cld = blk_collide(missl, shltr, t_cld);
            if (cld) {
                printf("Collission: "); t_cld.dump(); printf("\n\n");

                if (damg_list.add(&v_missl, &v_shltr, t_cld.p0)) {

                    printf("..... Before Process .......................\n");
                    damg_list.dump_list();

                    printf("..... After Process ........................\n");
                    damg_list.proc();
                    damg_list.dump_list();

                    missl.dump(); v_missl.dump("  ");
                    shltr.dump(); v_shltr.dump("  ");
                    printf("\n");
                }
            }
        }

        if (v_missl.alived()) {
            missl.move_dtime(d_time);
        }
        if (v_shltr.alived()) {
            shltr.move_dtime(d_time);
        }
    }

    printf("\n\n");
}

void DamgList_Test_Sort(void)
{
    printf("____________ !!!! %s !!!! ___________________________\n\n",
           __FUNCTION__);

    DamgList damgList;

    Vitality v_A0, v_A1, v_A2;
    Vitality v_B0, v_B1;
    Vitality v_C0, v_C1, v_C2;

    v_A0.init(1000, 10);
    v_A1.init(1001, 11);
    v_A2.init(1002, 12);

    v_B0.init(2000, 20);
    v_B1.init(2010, 21);

    v_C0.init(3000, 30);
    v_C1.init(3100, 31);
    v_C2.init(3200, 32);

    damgList.config(12);
    damgList.set_t_seg(-10, 80);   // 10 ~ 30
    printf("---------- Time Slot [10, 30]\n");
    printf("\n");
    
    Segment t_seg;

    t_seg.set(13, 28);
    damgList.add(&v_A0, &v_A2, t_seg.p0);
    printf("---------- Insert [%d, %d] - A0, A2\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    t_seg.set(10, 22);
    damgList.add(&v_A1, &v_A2, t_seg.p0);
    printf("---------- Insert [%d, %d] - A1, A2\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    t_seg.set(30, 36);
    damgList.add(&v_B0, &v_B1, t_seg.p0);
    printf("---------- Insert [%d, %d] - B0, B1\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    t_seg.set( 9, 12);
    damgList.add(&v_C0, &v_C2, t_seg.p0);
    printf("---------- Insert [%d, %d] - C0, C2\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    t_seg.set(15, 18);
    damgList.add(&v_C0, &v_C1, t_seg.p0);
    printf("---------- Insert [%d, %d] - C0, C1\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    printf("========== Duplicated Collison Info ==========\n\n");

    t_seg.set(10, 22);
    damgList.add(&v_A2, &v_A1, t_seg.p0);
    printf("---------- Insert [%d, %d] - A2, A1\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    t_seg.set(15, 18);
    damgList.add(&v_C1, &v_C0, t_seg.p0);
    printf("---------- Insert [%d, %d] - C1, C0\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    t_seg.set(30, 36);
    damgList.add(&v_B1, &v_B0, t_seg.p0);
    printf("---------- Insert [%d, %d] - B1, B0\n", t_seg.p0, t_seg.p1);
    damgList.dump_list();

    printf("========== Dump ALL ==========================\n\n");
    damgList.dump();

    printf("\n\n");
}
