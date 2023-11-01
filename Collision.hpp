//
//  Collision2.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 7/1/23.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <cstdio>
#include "BlkGeo.hpp"
#include "Pool.hpp"


class ClsnInfo {
public:
    int32_t  t_start;
    BlkGeo  *blk1;
    BlkGeo  *blk2;
    
    ClsnInfo() {
        blk1 = blk2 = nullptr;
    }

    void set(BlkGeo *blk1, BlkGeo *blk2, int32_t time) {
        this->blk1 = blk1;
        this->blk2 = blk2;
        t_start = time;
    }
    
    void dump(const char *prfx) {
        printf("%sclsn_info - t: %d, ", prfx, t_start);
        if (blk1 != nullptr) {
            printf("blk1: %s, ", blk1->name);
        } else {
            printf("blk1: NULL, ");
        }
        if (blk2 != nullptr) {
            printf("blk2: %s\n", blk2->name);
        } else {
            printf("blk2: NULL\n");
        }
    }
};


using ClsnItem = Item<ClsnInfo>;
using ClsnPool = Pool<ClsnInfo>;


class ClsnList {
private:
    ClsnPool  pool;
    Segment   t_seg;
    Link      clsnList;
    
    bool      insert(ClsnItem *clsnItem);
    
public:
    ClsnList() {
        t_seg.set(0, 1);
        clsnList.id = 11110000;
    }
    
    void config(uint32_t pool_size);

    void set_t_seg(int32_t t0, int32_t t1);
    void set_t_seg(Segment &time);

    bool add(BlkGeo &bk1, BlkGeo &bk2, int32_t t0);
    void proc(void);
    void clean(void);
    
    void dump_all(void);
    void dump_clsnList(void);
};


inline void ClsnList::set_t_seg(int32_t t0, int32_t t1)
{
    t_seg.set(t0, t1);
}

inline void ClsnList::set_t_seg(Segment &time)
{
    set_t_seg(time.p0, time.p1);
}


void ClsnItem_Test(void);
void ClsnList_Test(void);
void ClsnList_Test_2(void);
void ClsnList_Test_Sort(void);


#endif /* Collision_hpp */
