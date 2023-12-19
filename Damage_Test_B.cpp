//
//  Damage_Test_B.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 11/11/23.
//

#include "Geo2D.hpp"
#include "BlkGeo.hpp"
#include "BlkDisp.hpp"
#include "Damage.hpp"
#include "Explosion.hpp"
#include "Object.hpp"


void Damage_Test_Explsn(void)
{
    Explosion  expl;
    BlkGeo     missl, alien;
    Vitality   v_msl, v_aln;

    printf("____________ !!!! %s() !!!! ___________________________\n\n",
           __FUNCTION__);
    printf("sizeof BlkGeo    - %lu\n", sizeof(BlkGeo));
    printf("sizeof BlkDisp   - %lu\n", sizeof(BlkDisp));
    printf("sizeof Vitality  - %lu\n", sizeof(Vitality));
    printf("sizeof Explosion - %lu\n", sizeof(Explosion));
    printf("\n");
    printf("sizeof Object    - %lu\n", sizeof(Object));
    printf("\n");

    v_msl.init(10, 100);
    missl.set_name("missle");
    missl.set_orig(200, 400);
    missl.set_size(10, 20);
    missl.set_speed(3, -2);

    expl.config(-10, -10, 20, 20, 8);

    missl.dump("");
    v_msl.dump("");
    expl.dump("");

    Segment t_seg;
    bool rslt;
    Vec2D expl_speed(0, 0);
    rslt = rec_collide(missl.block_loc, missl.speed,
                       expl.area_loc,   expl_speed,  t_seg);
    
    printf("%s\n", rslt ? "True" : "False");
    t_seg.dump(); printf("\n");

    missl.move_dtime(-3);

    Rectangle ovlp;
    if (v_msl.alived()) {

        expl.update(200, 400);
        rslt = rec_overlap(missl.block_loc, expl.area_loc, ovlp);
        if (rslt) {
            expl.vital.damage_eval(v_msl);
            v_msl.damage_eval(expl.vital);

            printf("In damage zone ....\n");

        } else {
            printf("No affected !!\n");
        }

        expl.dump("");
        v_msl.dump("");
    }
}
