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
#include "Vitality.hpp"


class PairInfo {
public:
    int32_t    t_start;
    Vitality  *vtal_1;
    Vitality  *vtal_2;

    PairInfo() {
        vtal_1 = vtal_2 = nullptr;
    }
    
    void set(Vitality *vtal_1, Vitality *vtal_2, int32_t time) {
        t_start = time;
        this->vtal_1 = vtal_1;
        this->vtal_2 = vtal_2;
    }

    void dump(const char *prfx);
};


using DamgPair = Item<PairInfo>;
using DamgPool = Pool<PairInfo>;


class DamgList {
private:
    DamgPool  pool;
    Segment   t_seg;
    Link      list;
    bool      insert(DamgPair *pair);

public:
    DamgList() {
        t_seg.set(0, 1);
        list.id = 11110000;
    }
    
    void config(uint32_t pool_size);
    
    void set_t_seg(int32_t t0, int32_t t1);
    void set_t_seg(Segment &time);

    bool add(Vitality *vtal_1, Vitality *vtal_2, int32_t time);
    void proc(void);
    void clean(void);
    
    void dump(void);
    void dump_list(void);
};


inline void DamgList::set_t_seg(int32_t t0, int32_t t1)
{
    t_seg.set(t0, t1);
}

inline void DamgList::set_t_seg(Segment &time)
{
    set_t_seg(time.p0, time.p1);
}


void DamgPair_Test(void);
void DamgList_Test(void);
void DamgList_Test_2(void);
void DamgList_Test_Sort(void);


#endif /* Collision_hpp */
