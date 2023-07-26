//
//  FifoTest.cpp
//  HW_04.0_Template
//
//  Created by Yuen-Wen Lee on 7/3/23.
//

#include <cassert>
#include "FIFO.hpp"
#include "FifoTest.hpp"


#define PCKG_ARRAY_SIZE   8


using PckgFifo = FIFO<Pckg>;


const char *name_bank[PCKG_ARRAY_SIZE] = {
    "Code  00",
    "Code  11",
    "Code  22",
    "Code  33",
    "Code  44",
    "Code  55",
    "Code  66",
    "Code  77",
};

Pckg pckgBank[PCKG_ARRAY_SIZE];


void Fifo_Test(void)
{
    PckgFifo   fifo;
    PckgFifo   fifo2("Hello", 20);
    Pckg      *pckg_p;
    uint32_t   n;

    printf("____________ !!!! Fifo_Test !!!! ________________________________\n\n");

    for (n = 0; n < PCKG_ARRAY_SIZE; ++n) {
        pckgBank[n].id = n;
        pckgBank[n].code_name = name_bank[n];
    }

    // Sanity test, non-initialized FIFO and initialized FIFO
    printf("!!!!________ Test 0.0 - Befor config ________!!!!\n");
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 0.1 - Befor config, Input ________!!!!\n");
    if (fifo.input(&pckgBank[0]) == false) {
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    };
    printf("\n");

    printf("!!!!________ Test 0.2 - Befor config, Output ________!!!!\n");
    if (fifo.output() == nullptr) {
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    };
    printf("\n");

    printf("!!!!________ Test 0.3 - Initialized FIFO, \'fifo2\' ________!!!!\n");
    fifo2.dump("");
    printf("\n\n");

    
    // FIFO Configuration
    printf("!!!!________ Test 1.0 - FIFO.config() ________!!!!\n");
    if (fifo.config("Sample", (PCKG_ARRAY_SIZE / 2))) {
        fifo.dump("");
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    }
    printf("\n\n");


    // Test FIFO input
    printf("!!!!________ Test 2.0 - FIFO.input() ________!!!!\n");
    printf("FIFO Input:\n");
    for (n = 0; n < (PCKG_ARRAY_SIZE / 2); ++n) {
        pckg_p = pckgBank + n;
        pckg_p->dump("  ");
        if (fifo.input(pckg_p) == false) {
            printf("  Test FAIL !!!!! (should not be full)\n");
            break;
        }
    }
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 2.1 - FIFO.input() But FIFO Full !! ________!!!!\n");
    if (fifo.input(&pckgBank[PCKG_ARRAY_SIZE - 1]) == false) {
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    }
    printf("\n\n");


    // Test FIFO output
    printf("!!!!________ Test 3.0 - FIFO.output() ________!!!!\n");
    printf("FIFO Output:\n");
    while (fifo.get_length() > 0) {
        pckg_p = fifo.output();
        if (pckg_p != nullptr) {
            pckg_p->dump("  ");
        } else {
            printf("  Test FAIL !!!!! (NULL pointer?)\n");
        }
    }
    fifo.dump("");
    printf("\n");
    
    // Test FIFO output when it's empty
    printf("!!!!________ Test 3.1 - FIFO.output() But Empty !! ________!!!!\n");
    pckg_p = fifo.output();
    if (pckg_p != nullptr) {
        printf("  Test FAILED !!!!!\n");
        pckg_p->dump("  ");
    } else {
        printf("  Test Pass\n");
        fifo.dump("");
    }
    printf("\n\n");


    // Test FIFO reconfig
    printf("!!!!________ Test 4.0 - FIFO.config() FIFO not empty, FAIL ________!!!!\n");
    fifo.input(&pckgBank[PCKG_ARRAY_SIZE - 1]);
    fifo.dump("");
    fifo.config("New FIFO", PCKG_ARRAY_SIZE);
    printf("\n");

    printf("!!!!________ Test 4.1 - FIFO.config() ________!!!!\n");
    printf("FIFO output\n");
    fifo.output()->dump("  ");
    fifo.config("New FIFO", PCKG_ARRAY_SIZE);
    fifo.dump("");
    printf("\n\n");


    // Test FIFO input/output and Overrun .....
    printf("!!!!________ Test 5.0 - FIFO.input() ________!!!!\n");
    fifo.dump("");
    printf("FIFO Input:\n");
    for (n = 0; n < PCKG_ARRAY_SIZE; ++n) {
        pckg_p = pckgBank + (PCKG_ARRAY_SIZE - 1) - n;
        pckg_p->dump("  ");
        if (fifo.input(pckg_p) == false) {
            printf("ERROR, shout not be full ..............\n");
            break;
        }
    }
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 5.1 - FIFO.output() ________!!!!\n");
    printf("FIFO Output:\n");
    while (fifo.get_length() > 0) {
        pckg_p = fifo.output();
        if (pckg_p != nullptr) {
            pckg_p->dump("  ");
        } else {
            printf("  NULL pointer .... ?\n");
        }
    }
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 5.2 - FIFO.input() Over-run ________!!!!\n");
    fifo.dump("");
    printf("FIFO Input:\n");
    for (n = 0; n < (PCKG_ARRAY_SIZE / 2); ++n) {
        pckg_p = pckgBank + n;
        pckg_p->dump("  ");
        if (fifo.input(pckg_p) == false) {
            printf("ERROR, shout not be full ..............\n");
            break;
        }
    }
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 5.3 - FIFO.output() Over-run ________!!!!\n");
    printf("FIFO Output:\n");
    while (fifo.get_length() > 0) {
        pckg_p = fifo.output();
        if (pckg_p != nullptr) {
            pckg_p->dump("  ");
        } else {
            printf("  NULL pointer .... ?\n");
        }
    }
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 5.4 - FIFO.input() Over-run ________!!!!\n");
    fifo.dump("");
    printf("FIFO Input:\n");
    for (n = 0; n < PCKG_ARRAY_SIZE; ++n) {
        pckg_p = pckgBank + (PCKG_ARRAY_SIZE - 1) - n;
        pckg_p->dump("  ");
        if (fifo.input(pckg_p) == false) {
            printf("ERROR, shout not be full ..............\n");
            break;
        }
    }
    fifo.dump("");
    printf("\n");
    
    printf("!!!!________ Test 5.3 - FIFO.output() Over-run ________!!!!\n");
    printf("FIFO Output:\n");
    while (fifo.get_length() > 0) {
        pckg_p = fifo.output();
        if (pckg_p != nullptr) {
            pckg_p->dump("  ");
        } else {
            printf("  NULL pointer .... ?\n");
        }
    }
    fifo.dump("");
    printf("\n\n");


    // Test reconfigure FIFO, same size and smaller size
    printf("!!!!________ Test 6.0 - FIFO.config() But Same Size ________!!!!\n");
    fifo.config("Same_Config", PCKG_ARRAY_SIZE);
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 6.1 - FIFO.config() size reduced ________!!!!\n");
    fifo.config("Smaller", 1);
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 6.2 - FIFO.input() FIFO Full ________!!!!\n");
    pckg_p = &pckgBank[PCKG_ARRAY_SIZE - 1];
    pckg_p->dump("");
    assert(fifo.input(pckg_p) == true);
    if (fifo.input(&pckgBank[1]) == false) {
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    }
    fifo.dump("");
    printf("\n");

    printf("!!!!________ Test 6.3 - FIFO.output() ________!!!!\n");
    pckg_p = fifo.output();
    if (pckg_p != nullptr) {
        pckg_p->dump("");
        printf("  Test Pass\n");
        fifo.dump("");
    } else {
        printf("  Test FAIL !!!!! \n");
    }
    printf("\n\n");


    // Test resetting FIFO, FIFO size is 0 ...
    printf("!!!!________ Test 7.0 - FIFO.config() size is ZERO! ________!!!!\n");
    fifo2.config("???", 0);
    fifo2.dump("");
    printf("\n");

    printf("!!!!________ Test 7.1 - Zero config, Input ________!!!!\n");
    if (fifo2.input(&pckgBank[0]) == false) {
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    };
    printf("\n");

    printf("!!!!________ Test 7.2 - Zero config, Output ________!!!!\n");
    if (fifo2.output() == nullptr) {
        printf("  Test Pass\n");
    } else {
        printf("  Test FAIL !!!!! \n");
    };
    printf("\n\n");
}
