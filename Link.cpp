//
//  Queue.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 2/1/21.
//

#include <cstdio>
#include "Link.hpp"


void Link::insert_prev(Link *que)
{
    que->prev_p = prev_p;
    prev_p->next_p = que;
    que->next_p = this;
    prev_p = que;
}

void Link::insert_next(Link *que)
{
    que->next_p = next_p;
    next_p->prev_p = que;
    que->prev_p = this;
    next_p = que;
}

Link *Link::remove_prev(void)
{
    if (this->linked() == false) {
        return nullptr;
    }
    Link *que = prev_p;
    prev_p = que->prev_p;
    prev_p->next_p = this;

    que->reset();
    return que;
}

Link *Link::remove_next(void)
{
    if (this->linked() == false) {
        return nullptr;
    }
    Link *que = next_p;
    next_p = que->next_p;
    next_p->prev_p = this;

    que->reset();
    return que;
}

uint32_t Link::lenth(void)
{
    uint32_t count = 1;
    Link *que = this->next();
    while (que != this) {
        count++;
        que = que->next();
    }
    return count;
}

void Link::dump(const char *idnt)
{
    printf("%sque_Id: 0x%08x - [prev 0x%08x, next 0x%08x], ",
           idnt, id, prev_p->id, next_p->id);
    if (ent_p == nullptr) {
        printf("NULL\n");
    } else {
        printf("ent: %p\n", ent_p);
    }
}

void Link::dump_link(void)
{
    printf("Link Dump .....\n");
    Link *que = this;
    do {
        que->dump("  ");
        que = que->next_p;
    } while (que != this);
}
