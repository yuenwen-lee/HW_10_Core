//
//  DynMemExmp.cpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 6/22/23.
//

#include "Pool.hpp"
#include "PoolTest.hpp"


using ItemSmpl = Item<Sample>;


#define SAMPLE_POOL_SIZE_A     4
const char *name_a[SAMPLE_POOL_SIZE_A] = {
    "0000",
    "1111",
    "2222",
    "3333"
};


#define SAMPLE_POOL_SIZE_B     6
const char *name_B[SAMPLE_POOL_SIZE_B] = {
    "AAAA",
    "BBBB",
    "CCCC",
    "DDDD",
    "EEEE",
    "FFFF"
};


void Sample::dump(const char *prfx)
{
    printf("%sname: %s\n", prfx, name);
    printf("%snumb: %d\n", prfx, numb);
}


void PoolTest(void)
{
    Pool<Sample>  smpl_pool;
//  Item<Sample> *item_p;
    ItemSmpl     *item_p;
    Link          que(8800), *link_p;

    uint32_t  n;

    // Verify the content of Pool<Sample> before configuration
    printf("!!!!________ Test 0.0 - Befor Config ________!!!!\n");
    smpl_pool.dump("  ");
    printf("\n\n");


    // Dump the content of Pool<Sample> after configuration
    printf("!!!!________ Test 0.1 - After Config ________!!!!\n");
    smpl_pool.config("Sample", SAMPLE_POOL_SIZE_A);
    for (n = 0; n < SAMPLE_POOL_SIZE_A; ++n) {
        ItemSmpl *smpl_p = smpl_pool.peek(n);
        smpl_p->name = name_a[n];
        smpl_p->numb = 1000 + (11 * n);
    }
    smpl_pool.dump("  ");
    printf("\n\n");


    // Clean up the pool of Pool<Sample> and insert to another Link 'que'
    printf("!!!!________ Test 1.0 - Allocate from Pool ________!!!!\n");
    for (n = 0; n < SAMPLE_POOL_SIZE_A; ++n) {
        item_p = smpl_pool.allocate();
        if (item_p == nullptr) {
            break;
        }
        que.insert_next(&item_p->link);
    }
    smpl_pool.dump("  ");
    printf("\n");


    // Allocate the Item from an empty pool of Pool<Sample>
    printf("!!!!________ Test 1.1 - Allocate from empty Pool ________!!!!\n");
    item_p = smpl_pool.allocate();
    printf("\n\n");


    // Free all the item back to pool of Pool<Sample> (backward)
    printf("!!!!________ Test 2.0 - Free back to Pool ________!!!!\n");
    while (que.linked()) {
        link_p = que.remove_next();
        smpl_pool.free((ItemSmpl *) link_p->get_ent());
    }
    smpl_pool.dump("  ");
    printf("\n\n");


    // Try to reconfigure the pool of Pool<Sample>, when it is in used
    printf("!!!!________ Test 3.0 - Reconfig non-empty Pool ________!!!!\n");
    item_p = smpl_pool.allocate();
    smpl_pool.dump("  ");
    smpl_pool.config("New", SAMPLE_POOL_SIZE_B);
    smpl_pool.free(item_p);
    printf("\n");


    // Try to reconfigure the pool of Pool<Sample>, when it is in used
    printf("!!!!________ Test 3.1 - Reconfig Pool, zero size bank ________!!!!\n");
    smpl_pool.config("Empty", 0);
    smpl_pool.dump("  ");
    printf("\n");


    // Try to reconfigure the pool of Pool<Sample>, when it is in used
    printf("!!!!________ Test 3.2 - Reconfig empty Pool ________!!!!\n");
    smpl_pool.config("New", SAMPLE_POOL_SIZE_B);
    for (n = 0; n < SAMPLE_POOL_SIZE_B; ++n) {
        ItemSmpl *smpl_p = smpl_pool.peek(n);
        smpl_p->name = name_B[n];
        smpl_p->numb = 5500 + (11 * n);
    }
    smpl_pool.dump("  ");
    printf("\n\n");


    // Reonfigure the pool of Pool<Sample>, same size, but different name
    printf("!!!!________ Test 3.3 - Reconfig, just change name ________!!!!\n");
    smpl_pool.config("ZzzzzzZ", SAMPLE_POOL_SIZE_B);
    smpl_pool.dump("  ");
    printf("\n\n");


    // Free non-related item to pool
    printf("!!!!________ Test 4.0 - Free non-member item to Pool ________!!!!\n");
    ItemSmpl  smpl;
    smpl_pool.free(&smpl);
    printf("\n\n");


    // Free non-related item to pool
    printf("!!!!________ Test 4.1 - Free the item in Pool again ________!!!!\n");
    item_p = smpl_pool.peek(0);
    smpl_pool.free(item_p);
    printf("\n\n");
}
