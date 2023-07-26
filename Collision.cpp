//
//  Collision2.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/1/23.
//

#include "Segment.hpp"
#include "Collision.hpp"


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
        
        if ((info->blk1 == ref->blk1 && info->blk2 == ref->blk2) ||
            (info->blk1 == ref->blk2 && info->blk2 == ref->blk1)) {
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

bool ClsnList::add(BlkGeo &bk1, BlkGeo &bk2, Segment &time)
{
    if (seg_overlap_check(t_seg, time)) {

        ClsnItem *info = pool.allocate();
        if (info == NULL) {
            assert(0);
            return false;  // pool is empty !!!
        }

        info->t_start = time.p0;
        info->blk1 = &bk1;
        info->blk2 = &bk2;

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
    BlkGeo   *bk1, *bk2;
    uint32_t damage;
    
    while (clsnList.linked()) {

        link = clsnList.remove_next();
        info = (ClsnItem *) link->get_ent();
        bk1 = info->blk1;
        bk2 = info->blk2;

        if (bk1->obj_life > 0 && bk2->obj_life > 0) {
            damage = (bk1->obj_life > bk2->obj_life) ? bk2->obj_life : bk1->obj_life;
            bk1->dmg_val += damage;
            bk2->dmg_val += damage;
            bk1->obj_life -= damage;
            bk2->obj_life -= damage;
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
    printf("tSlotH - t_seg: "); t_seg.dump(); printf("\n");
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


