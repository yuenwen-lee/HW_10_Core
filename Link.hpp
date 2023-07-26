//
//  Queue.hpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 2/1/21.
//

#ifndef Link_hpp
#define Link_hpp

#include <cstdint>


class Link {
private:
    Link *next_p;
    Link *prev_p;
    void *ent_p;

public:
    uint32_t id;

    Link() {
        next_p = this;
        prev_p = this;
        ent_p = nullptr;
    }
    Link(uint32_t id) {
        this->id = id;
        next_p = this;
        prev_p = this;
        ent_p = nullptr;
    }

    void set_ent(void *ent);
    void *get_ent(void);

    void reset(void);
    bool linked(void);

    Link *prev(void);
    Link *next(void);
    void insert_next(Link *que);
    void insert_prev(Link *que);
    Link *remove_next(void);
    Link *remove_prev(void);
    
    uint32_t lenth(void);
    
    void dump(const char *idnt);
    void dump_link(void);
};


inline void Link::set_ent(void *ent)
{
    ent_p = ent;
}

inline void *Link::get_ent(void)
{
    return ent_p;
}

inline void Link::reset(void)
{
    next_p = prev_p = this;
}

inline bool Link::linked(void)
{
    if (next_p == this && prev_p == this) {
        return false;
    } else {
        return true;
    }
}

inline Link *Link::next(void)
{
    return next_p;
}

inline Link *Link::prev(void)
{
    return prev_p;
}


void Link_test(void);


#endif /* Link_hpp */
