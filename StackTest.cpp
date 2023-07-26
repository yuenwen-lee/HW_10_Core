//
//  StackTest.cpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 6/28/23.
//

#include "StackTest.hpp"


#define  STCKSMPL_ARRAY_SIZE    6


void StackTest_Test(void)
{
    StckSmpl        *array;
    StckSmpl        *smpl_p;
    Stack<StckSmpl>  stack;
    int n;
    bool rslt;

    printf("____________ !!!! StackTest_Test !!!! ________________________________\n\n");

    array = new StckSmpl [STCKSMPL_ARRAY_SIZE];
    for (n = 0; n < STCKSMPL_ARRAY_SIZE; ++n) {
        smpl_p = &array[n];
        smpl_p->id = 100 + n;
        smpl_p->val = 100.11 + (double) n;
    }

    printf("!!!!________ Test 0.0, befor config() ________!!!!\n");
    stack.dump("");
    printf("\n");

    printf("!!!!________ Test 0.1, push() befor config() ________!!!!\n");
    rslt = stack.push(&array[1]);
    assert(rslt == false);
    printf("Pass the test, push() failed ...\n");
    printf("\n");

    printf("!!!!________ Test 0.2, pop() befor config() ________!!!!\n");
    smpl_p = stack.pop();
    assert(smpl_p == nullptr);
    printf("Pass the test, pop() failed ...\n");
    printf("\n");

    // Test stack.top(), stack.name() and stack.available() .......................
    printf("!!!!________ Test 0.3 after config() ________!!!!\n");
    stack.config("Sample Stack", STCKSMPL_ARRAY_SIZE);
    stack.dump("");
    smpl_p = stack.top();
    if (smpl_p == nullptr) {
        printf("stack is empty\n");
    } else {
        smpl_p->dump("  ");
    }
    printf("\n");


    // Test stack.push(), stack.top() .............................................
    printf("!!!!________ Test 1.0, push() ________ !!!!\n");
    n = 0;
    while (1) {
        rslt = stack.push(array + n);
        if (rslt == false) {
            break;
        }
        n++;
    }

    stack.dump("");
    smpl_p = stack.top();
    if (smpl_p == nullptr) {
        printf("stack is empty\n");
    } else {
        printf("stack.top() -\n");
        smpl_p->dump("  ");
    }
    printf("\n");


    // Test stack.pop() and stack.available() .....................................
    printf("!!!!________ Test 2.0, pop() ________ !!!!\n");
    n = 0;
    while (1) {
        smpl_p = stack.pop();
        if (smpl_p != nullptr) {
            smpl_p->dump("  ");
        } else {
            break;
        }
    }
    stack.dump("");
    printf("\n");


    // Test stack.config() ........................................................
    printf("!!!!________ Test 3.0 reconfig(), non-empty ________ !!!!\n");
    stack.push(array);
    smpl_p = stack.top();
    if (smpl_p == nullptr) {
        printf("stack is empty\n");
    } else {
        printf("stack.top() -\n");
        smpl_p->dump("  ");
    }
    stack.dump("");
    stack.config("New Stack", (STCKSMPL_ARRAY_SIZE + 4));
    printf("\n");


    // Test stack.config() ........................................................
    printf("!!!!________ Test 3.1 reconfig() ________!!!!\n");
    stack.pop();
    stack.config("New Stack", (STCKSMPL_ARRAY_SIZE + 4));
    stack.dump("");
    printf("\n");

    while (1) {
        rslt = stack.push(array + n);
        if (rslt == false) {
            break;
        }
        
        n++;
        if (n >= STCKSMPL_ARRAY_SIZE) {
            break;
        }
    }
    printf("After push %d items .....\n", STCKSMPL_ARRAY_SIZE);
    stack.dump("");
    printf("\n");
}
