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

    BlkGeo mssl( "Missle",  26,  0,  1, 4, 1, 1);
    BlkGeo shlt( "Shelter", 20, 10, 13, 6, 0, 0);
    BlkGeo alien("Alien",   26,  0,  1, 4, 1, 1);
    BlkGeo tank( "tank",    20, 10, 13, 6, 0, 0);
    
    ClsnItem info1, info2, info3, info4;
    
    info1.set(&mssl,  &shlt,   1);
    info2.set(&shlt,  &alien,  2);
    info3.set(&alien, &tank,   3);
    info4.set(&tank,  &mssl,   4);
    
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
    
    BlkGeo missl_0("Missile_0",  0, 1,  1, 1,  0, 0);
    BlkGeo missl_1("Missile_1",  0, 1,  1, 1,  0, 0);
    BlkGeo shltr_0("Shelter_0",  0, 1,  1, 1,  0, 0);
    BlkGeo shltr_1("Shelter_1",  0, 1,  1, 1,  0, 0);
    
    BlkGeo missl_Z("Missile_Z",  0, 1,  1, 1,  0, 0);
    BlkGeo shltr_Z("Shelter_Z",  0, 1,  1, 1,  0, 0);
    
    BlkGeo alien_A("Alien_A",    0, 1,  1, 1,  0, 0);
    BlkGeo alien_B("Alien_B",    0, 1,  1, 1,  0, 0);
    BlkGeo aa_gun( "AA_Gun",     0, 1,  1, 1,  0, 0);
    
    missl_0.set_life(3);
    missl_1.set_life(3);
    shltr_0.set_life(4);
    shltr_1.set_life(4);
    
    missl_Z.set_life(3);
    shltr_Z.set_life(4);
    
    alien_A.set_life(4);
    alien_B.set_life(4);
    aa_gun.set_life(3);
    
    Segment t_seg;

    printf("........ Test 0.0 - Init : 8 info     .............................\n");
    printf("                  - t_seg: [10 ~ 30]  .............................\n");
    printf("\n");
    clsn_list.config(8);
    clsn_list.set_t_seg(10, 30);
    clsn_list.dump_all();
    
    printf("........ Test 1.a - Add: Misl_0 + Shltr_0 [ 9 ~ 12] ...............\n");
    t_seg.set(9, 12);
    clsn_list.add(missl_0, shltr_0, t_seg);
    clsn_list.dump_clsnList();

    printf("........ Test 1.x - Add: Shltr_0 + Misl_0 (Dup ...) ...............\n");
    clsn_list.add(shltr_0, missl_0, t_seg);
    clsn_list.dump_clsnList();

    printf("........ Test 1.b - Add: Misl_0 + Shltr_1 [18 ~ 21] ...............\n");
    t_seg.set(18, 21);
    clsn_list.add(missl_0, shltr_1, t_seg);
    clsn_list.dump_clsnList();

    printf("........ Test 2.a - Add: Misl_1 + Shltr_0 [11 ~ 14] ...............\n");
    t_seg.set(11, 14);
    clsn_list.add(missl_1, shltr_0, t_seg);
    clsn_list.dump_clsnList();

    printf("........ Test 2.b - Add: Misl_1 + Shltr_1 [20 ~ 23] ...............\n");
    t_seg.set(20, 23);
    clsn_list.add(missl_1, shltr_1, t_seg);
    clsn_list.dump_clsnList();

    printf("........ Test 3.a - Add: Misl_Z + Shltr_Z [30 ~ 35] ...............\n");
    t_seg.set(30, 35);
    clsn_list.add(shltr_Z, missl_Z, t_seg);
    clsn_list.dump_clsnList();

    printf("........ Test X.0 - Before Process ................................\n");
    clsn_list.dump_all();

    printf("........ Test Y.0 - Process the CollisionList .....................\n");
    clsn_list.proc();
    clsn_list.dump_all();

    printf("........ Test Z.Z - Dump all OBJ ..................................\n");
    missl_0.dump();
    missl_1.dump();
    shltr_0.dump();
    shltr_1.dump();
    missl_Z.dump();
    shltr_Z.dump();
//  alien_A.dump();
//  alien_B.dump();
//  aa_gun.dump();

    printf("\n\n");
}

void ClsnList_Test_2(void)
{
    ClsnList clsn_list;

    printf("____________ !!!! ClsnList_Test_2 !!!! ______________________________\n\n");

    BlkGeo missl("Missle_0",  20,  10,   4,  10,  0, 10);
    BlkGeo shltr("Shelter",   18, 100,  20,  10,  0,  0);

    clsn_list.config(8);

    missl.set_life(1);
    shltr.set_life(2);

    missl.dump();
    shltr.dump();

    printf("__________ !!!!!! Start Simulation !!!!!! __________\n\n");

    int d_time = 1;
    for (int time = 0; time < 14; ) {

        clsn_list.clean();
        clsn_list.set_t_seg(0, d_time);
        printf("____________ Time: [%d, %d] ________________________\n\n",
               time, (time + d_time));

        missl.dump();
        shltr.dump();

        if (!missl.destoryed() && !shltr.destoryed()) {

            Segment t_cld;
            bool cld = blk_collide(missl, shltr, t_cld);
            if (cld) {
                printf("Collission: "); t_cld.dump(); printf("\n\n");

                if (clsn_list.add(missl, shltr, t_cld)) {

                    printf("..... Before Process .......................\n");
                    clsn_list.dump_clsnList();

                    printf("..... After Process ........................\n");
                    clsn_list.proc();
                    clsn_list.dump_clsnList();
                    missl.dump();
                    shltr.dump();
                }
            }
        }

        if (!missl.destoryed()) {
            missl.move_dtime(d_time);
        }
        if (!shltr.destoryed()) {
            shltr.move_dtime(d_time);
        }

        time += d_time;
    }

    printf("\n\n");
}

void ClsnList_Test_Sort(void)
{
    printf("____________ !!!! ClstList_Test_Sort !!!! ___________________________\n\n");

    ClsnList clsnList;

    BlkGeo obj_A0("Obj_A0");
    BlkGeo obj_A1("Obj_A1");
    BlkGeo obj_A2("Obj_A2");

    BlkGeo obj_B0("Obj_B0");
    BlkGeo obj_B1("Obj_B1");

    BlkGeo obj_C0("Obj_C0");
    BlkGeo obj_C1("Obj_C1");
    BlkGeo obj_C2("Obj_C2");

    clsnList.config(12);
    clsnList.set_t_seg(10, 30);
    
    Segment t_seg;

    printf("---------- Insert [18, 20]\n");
    t_seg.set(18, 20);
    clsnList.add(obj_A0, obj_A2, t_seg);
    clsnList.dump_clsnList();

    printf("---------- Insert [19, 20]\n");
    t_seg.set(19, 20);
    clsnList.add(obj_A1, obj_A2, t_seg);
    clsnList.dump_clsnList();

    printf("---------- Insert [12, 16]\n");
    t_seg.set(12, 16);
    clsnList.add(obj_B0, obj_B1, t_seg);
    clsnList.dump_clsnList();

    printf("---------- Insert [ 9, 12]\n");
    t_seg.set(9, 12);
    clsnList.add(obj_C0, obj_C2, t_seg);
    clsnList.dump_clsnList();

    printf("---------- Insert [15, 18]\n");
    t_seg.set(15, 18);
    clsnList.add(obj_C0, obj_C1, t_seg);
    clsnList.dump_clsnList();

    printf("========== Duplicated Collison Info ==========\n\n");

    printf("---------- Insert [19, 20] A2 + A1\n");
    t_seg.set(19, 20);
    clsnList.add(obj_A2, obj_A1, t_seg);
    clsnList.dump_clsnList();

    printf("---------- Insert [ 9, 12] C2 + C0\n");
    t_seg.set(9, 12);
    clsnList.add(obj_C2, obj_C0, t_seg);
    clsnList.dump_clsnList();

    printf("---------- Insert [12, 16] B0 + B1\n");
    t_seg.set(12, 16);
    clsnList.add(obj_B0, obj_B1, t_seg);
    clsnList.dump_clsnList();

    printf("========== Dump ALL ==========================\n\n");
    clsnList.dump_all();

    printf("\n\n");
}
