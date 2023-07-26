//
//  Link_Test.cpp
//  HW_10.0
//
//  Created by Yuen-Wen Lee on 11/19/22.
//

#include <cstdio>
#include "Link.hpp"


void Link_test(void)
{
//  printf("\n........ line: %d - %s() ......\n", __LINE__, __FUNCTION__);

    Link que0(0);
    Link que1(1);
    Link que2(2);
    Link que3(3);
    Link queX(4);

    que0.insert_next(&que1);
    que1.insert_next(&que2);
    que2.insert_next(&que3);

    Link *que;

    printf("........ Test 0.0 ........................\n");
    printf("---- Next, start que0 ----\n");
    que = &que0;
    do {
        que->dump("  ");
        que = que->next();
    } while (que != &que0);
    printf("\n");

    printf("---- Prev, start que3 ----\n");
    que = &que3;
    do {
        que->dump("  ");
        que = que->prev();
    } while (que != &que3);
    printf("\n");

    printf("........ Test 0.1 ........................\n");
    printf("que_0 lenth: %d\n", que0.lenth());
    printf("que_1 lenth: %d\n", que1.lenth());
    printf("que_X lenth: %d\n", queX.lenth());
    printf("\n");

    printf("........ Test 1.0 ........................\n");
    que0.reset();
    que1.reset();
    que2.reset();
    que3.reset();
    queX.reset();

    que0.insert_next(&que1);
    que0.insert_prev(&que2);
    que0.dump_link();
    printf("\n");
    printf("que3 insert prev to que0 ....\n");
    que0.insert_prev(&que3);
    printf("que4 insert next to que0 ....\n");
    que0.insert_next(&queX);
    printf("\n");
    que0.dump_link();
    printf("\n");

    printf("........ Test 1.1 ........................\n");
    que0.reset();
    que1.reset();
    que2.reset();
    que3.reset();
    queX.reset();

    que0.insert_next(&que1);
    que0.dump_link();
    printf("\n");
    que = que0.remove_prev();
    que0.dump("  ");
    que->dump("  ");
    printf("\n");

    printf("........ Test 2.0 ........................\n");
    que0.reset();
    que1.reset();
    que2.reset();
    que3.reset();
    queX.reset();

    que0.insert_next(&que1);
    que0.insert_prev(&que2);
    que0.insert_prev(&que3);
    que0.dump_link();
    printf("\n");

    printf("remove prev\n");
    que = que0.remove_prev();
    que0.dump_link();
    printf("> "); que->dump(""); printf("\n");

    printf("remove next\n");
    que = que0.remove_next();
    que0.dump_link();
    printf("> "); que->dump(""); printf("\n");

    printf("remove prev\n");
    que = que0.remove_prev();
    que0.dump_link();
    printf("> "); que->dump(""); printf("\n");

    printf("remove next\n");
    que = que0.remove_next();
    que0.dump_link();
    printf("> que is ... %p\n", que);

    printf("\n");
}
