//
//  DynMem.hpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 6/20/23.
//

#ifndef DynMem_hpp
#define DynMem_hpp

#include <cstdio>
#include "Link.hpp"


#define POOL_ID_MASK          0xFFFF0000
#define POOL_ID_MASK_SHIFT   (8)


template <class T>
class Item : public T {
public:
    Link      link;

    Item() {
        T();
        link.reset();
        link.set_ent((void *) this);
    }
};


template <class T>
class Pool {
private:
    const char *name;
    Item<T>    *bank;
    uint32_t    bank_size;
    Link        pool;
    uint32_t    pool_space;
    
public:
    Pool() {
        name = "No Name";
        bank = nullptr;
        bank_size = 0;
        pool.id = 0;
        pool_space = 0;
    }

    bool config(const char *name, uint32_t size);

    Item<T> *peek(uint32_t indx);
    Item<T> *allocate(void);
    void free(Item<T> *blck);
    uint32_t available(void);
    
    void dump(const char *prfx);
};


template <class T>
bool Pool<T>::config(const char *name, uint32_t size)
{
    if (pool_space < bank_size) {
        printf("Error, can not config Pool \'%s\', when it is in use !!\n",
               this->name);
        return false;
    }
    
    this->name = name;

    if (bank_size != size) {

        if (bank != nullptr) {
            delete [] bank;
            bank = nullptr;
        }
        bank_size = size;

        if (size != 0) {

            bank = new Item<T> [size];

            uint32_t tmp = (((unsigned long) &bank[0]) &
                            (POOL_ID_MASK >> POOL_ID_MASK_SHIFT));
            pool.id = tmp << POOL_ID_MASK_SHIFT;
            pool.reset();
            pool_space = 0;
            for (uint32_t n = 0; n < size; ++n) {
                bank[n].link.id = pool.id + (n + 1);
                pool.insert_prev(&bank[n].link);
                pool_space++;
            }
        }
    }

    return true;;
}

template<class T>
Item<T> *Pool<T>::peek(uint32_t indx)
{
    if (indx < bank_size) {
        return &bank[indx];
    } else {
        return nullptr;
    }
}

template<class T>
Item<T> *Pool<T>::allocate(void)
{
    if (pool.linked()) {
        Link *link_p = pool.remove_next();
        pool_space--;
        link_p->reset();
        return (Item<T> *) (link_p->get_ent());

    } else {
        printf("Error! pool \'%s\' is empty!\n", name);
        return nullptr;
    }
}

template<class T>
void Pool<T>::free(Item<T> *item_p)
{
    if (item_p < &bank[0] || item_p > &bank[bank_size - 1]) {
        printf("ERROR, free non-member item to pool \'%s\'!!\n", name);
        return;
    }

    if (item_p->link.linked()) {
        uint32_t idx_nxt = item_p->link.next()->id;
        uint32_t idx_prv = item_p->link.prev()->id;
        if ((idx_nxt & POOL_ID_MASK) == pool.id ||
            (idx_prv & POOL_ID_MASK) == pool.id) {
            printf("ERROR, item is already in pool \'%s\'\n", name);
            return;
        }
    }
    pool.insert_prev(&item_p->link);
    pool_space++;
}

template<class T>
uint32_t Pool<T>::available(void)
{
    return pool_space;
}

template<class T>
void Pool<T>::dump(const char *prfx)
{
    printf("Pool Name: %s\n", name);
    printf("Bank: \n");
    if (bank_size) {
        for (uint32_t n = 0; n < bank_size; ++n) {
            bank[n].link.dump(prfx);
            bank[n].dump(prfx);
            printf("\n");
        }
    } else {
        printf("%sEmpty ...\n", prfx);
    }

    printf("Pool: <0x%08x>\n", pool.id);
    if (pool.linked()) {
        Link *link = pool.next();
        while (link != &pool) {
            link->dump(prfx);
            ((Item<T> *) link->get_ent())->dump(prfx);
            printf("\n");
            link = link->next();
        }

    } else {
        printf("%sEmpty ...\n", prfx);
    }
}


#endif /* DynMem_hpp */
