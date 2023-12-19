//
//  Collision2.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/1/23.
//

#include "Segment.hpp"
#include "Damage.hpp"
#include <cstring>


void PairInfo::dump(const char *prfx)
{
    char str[20] = "  ";

    printf("%sPairInfo - t: %d\n", prfx, t_start);
    strcat(str, prfx);

    if (vtal_1 != nullptr) {
        vtal_1->dump(str);
    } else {
        printf("%s  vtal_1 is NULL\n", prfx);
    }

    if (vtal_2 != nullptr) {
        vtal_2->dump(str);
    } else {
        printf("%s  vtal_2 is NULL\n", prfx);
    }
}


// Private methods ..........................................................

bool DamgList::insert(DamgPair *pair)
{
    Link      *link;
    PairInfo  *ref;
    
    link = list.prev();
    while (link != &list) {
        ref = (DamgPair *) link->get_ent();
        
        // bubbble sorting based on the time ...
        if (pair->t_start > ref->t_start) {
            break;
        }
        
        if ((pair->vtal_1 == ref->vtal_1 && pair->vtal_2 == ref->vtal_2) ||
            (pair->vtal_1 == ref->vtal_2 && pair->vtal_2 == ref->vtal_1)) {
            return false;
        }
        link = link->prev();
    }

    link->insert_next(&pair->link);
    return true;
}


// Public methods ...........................................................

void DamgList::config(uint32_t pool_size)
{
    if (pool.config("PairInfo", pool_size) == false) {
        printf("Error, fail to configure ClsnInfo pool!\n");
    }
}

bool DamgList::add(Vitality *vtal_1, Vitality *vtal_2, int32_t t0)
{
    if (t_seg.p0 <= t0 && t0 < t_seg.p1) {
        // If collision happen within this time segment ....

        DamgPair *pair = pool.allocate();
        if (pair == NULL) {
            assert(0);
            return false;  // pool is empty !!!
        }

        pair->t_start = t0;
        pair->vtal_1 = vtal_1;
        pair->vtal_2 = vtal_2;

        if (insert(pair)) {
            return true;
        } else {
            pool.free(pair);
            return false;;
        }

    } else {
        return false;
    }
}

void DamgList::proc(void)
{
    Link     *link;
    DamgPair *pair;
    
    while (list.linked()) {

        link = list.remove_next();
        pair = (DamgPair *) link->get_ent();
        Vitality *vtal_1 = pair->vtal_1;
        Vitality *vtal_2 = pair->vtal_2;

        if (!vtal_1->destroyed() && !vtal_2->destroyed()) {
            vtal_1->damage_eval(*vtal_2);
            vtal_2->damage_eval(*vtal_1);
        }

        pool.free(pair);
    }
}

void DamgList::clean(void)
{
    while (list.linked()) {
        pool.free((DamgPair *) list.remove_next()->get_ent());
    }
}

void DamgList::dump_list(void)
{
    printf("tSlot - t_seg: "); t_seg.dump(); printf("\n");
    list.dump("  ");

    if (list.lenth() == 1) {
        printf("  Empty !!\n");
    } else {
        DamgPair *pair;
        Link *link = list.next();
        while (link != &list) {
            pair = (DamgPair *) link->get_ent();
            pair->dump("  ");
            link = link->next();
        }
    }
    printf("\n");
}

void DamgList::dump(void)
{
    printf("_____ ClsnList _____\n");
    pool.dump("  ");
    dump_list();
}
