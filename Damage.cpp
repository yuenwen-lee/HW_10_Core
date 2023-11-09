//
//  Collision2.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/1/23.
//

#include "Segment.hpp"
#include "Damage.hpp"


void PairInfo::dump(const char *prfx)
{
    printf("%sclsn_info - t: %d\n", prfx, t_start);

    if (vtal_1 != nullptr) {
        printf("%s  vtal_1 (%p) - %d (dmg %d)\n", prfx, vtal_1, *vtal_1, damg_1);
    } else {
        printf("%s  vtal_1 is NULL\n", prfx);
    }

    if (vtal_2 != nullptr) {
        printf("%s  vtal_2 (%p) - %d (dmg %d)\n", prfx, vtal_2, *vtal_2, damg_2);
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
    if (pool.config("ClsnInfo", pool_size) == false) {
        printf("Error, fail to configure ClsnInfo pool!\n");
    }
}

bool DamgList::add(int32_t *vtal_1, uint32_t damg_1,
                   int32_t *vtal_2, uint32_t damg_2, int32_t t0)
{
    if (t_seg.p0 <= t0 && t0 < t_seg.p1) {
        // If collision happen within this time segment ....

        DamgPair *pair = pool.allocate();
        if (pair == NULL) {
            assert(0);
            return false;  // pool is empty !!!
        }

        pair->t_start = t0;
        pair->damg_1 = damg_1;
        pair->vtal_1 = vtal_1;
        pair->damg_2 = damg_2;
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
        if (*pair->vtal_1 > 0 && *pair->vtal_2 > 0) {
            *pair->vtal_1 -= pair->damg_2;
            *pair->vtal_2 -= pair->damg_1;
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
