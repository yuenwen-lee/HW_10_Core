//
//  Collision2.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/1/23.
//

#include "Segment.hpp"
#include "Collision.hpp"


void ClsnInfo::dump(const char *prfx)
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

bool ClsnList::insert(ClsnItem *info)
{
    Link      *link;
    ClsnInfo  *ref;
    
    link = clsnList.prev();
    while (link != &clsnList) {
        ref = (ClsnItem *) link->get_ent();
        
        // bubbble sorting based on the time ...
        if (info->t_start > ref->t_start) {
            break;
        }
        
        if ((info->vtal_1 == ref->vtal_1 && info->vtal_2 == ref->vtal_2) ||
            (info->vtal_1 == ref->vtal_2 && info->vtal_2 == ref->vtal_1)) {
            return false;
        }
        link = link->prev();
    }

    link->insert_next(&info->link);
    return true;
}


// Public methods ...........................................................

void ClsnList::config(uint32_t pool_size)
{
    if (pool.config("ClsnInfo", pool_size) == false) {
        printf("Error, fail to configure ClsnInfo pool!\n");
    }
}

bool ClsnList::add(int32_t *vtal_1, uint32_t damg_1,
                   int32_t *vtal_2, uint32_t damg_2, int32_t t0)
{
    if (t_seg.p0 <= t0 && t0 < t_seg.p1) {
        // If collision happen within this time segment ....

        ClsnItem *info = pool.allocate();
        if (info == NULL) {
            assert(0);
            return false;  // pool is empty !!!
        }

        info->t_start = t0;
        info->damg_1 = damg_1;
        info->vtal_1 = vtal_1;
        info->damg_2 = damg_2;
        info->vtal_2 = vtal_2;

        if (insert(info)) {
            return true;
        } else {
            pool.free(info);
            return false;;
        }

    } else {
        return false;
    }
}

void ClsnList::proc(void)
{
    Link     *link;
    ClsnItem *info;
    
    while (clsnList.linked()) {

        link = clsnList.remove_next();
        info = (ClsnItem *) link->get_ent();
        if (*info->vtal_1 > 0 && *info->vtal_2 > 0) {
            *info->vtal_1 -= info->damg_2;
            *info->vtal_2 -= info->damg_1;
        }

        pool.free(info);
    }
}

void ClsnList::clean(void)
{
    while (clsnList.linked()) {
        pool.free((ClsnItem *) clsnList.remove_next()->get_ent());
    }
}

void ClsnList::dump_clsnList(void)
{
    printf("tSlot - t_seg: "); t_seg.dump(); printf("\n");
    clsnList.dump("  ");

    if (clsnList.lenth() == 1) {
        printf("  Empty !!\n");
    } else {
        ClsnItem *info;
        Link *link = clsnList.next();
        while (link != &clsnList) {
            info = (ClsnItem *) link->get_ent();
            info->dump("  ");
            link = link->next();
        }
    }
    printf("\n");
}

void ClsnList::dump_all(void)
{
    printf("_____ ClsnList _____\n");
    pool.dump("  ");
    dump_clsnList();
}
