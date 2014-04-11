/*
 *  ======== main.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

#include <stdio.h>
#include <xdc/runtime/Timestamp.h>

#define DDR3_BASE_ADDR 0x80000000
#define SIZE 0x10000
#define A_ADDRESS DDR3_BASE_ADDR
#define B_ADDRESS A_ADDRESS + (SIZE) * 4
#define C_ADDRESS B_ADDRESS + (SIZE) * 4

/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1)
{
    System_printf("enter taskFxn()\n");

    	unsigned int *a;
        unsigned int *b;
        unsigned int *c;
        unsigned int i = 0;
        unsigned int delta = 0;
        unsigned int timestamp = 0;

        a = (unsigned int *)A_ADDRESS;
        b = (unsigned int *)B_ADDRESS;

        c = (unsigned int *)C_ADDRESS;

        printf("Address of a: %.8X, b: %.8X, c: %.8X\n", a, b, c);
        printf("Initializing arrays and performing vector add\n");

        timestamp = Timestamp_get32();

        for (i = 0; i < SIZE; i++){
        a[i] = i;
        b[i] = i;
        c[i] = a[i] + b[i];
        }
        delta = Timestamp_get32() - timestamp;
        printf("vector add done random check %d (a[2000]) + %d (b[2000]) = %d (c[2000]) \n", a[2000], b[2000], c[2000]);
        printf("\n# of Clock Cycles: %d\n", delta);

        printf("\nexecution time: %0.2fms\n", (float)delta/1000000);

    System_printf("exit taskFxn()\n");
}

/*
 *  ======== main ========
 */
Void main()
{ 
    Task_Handle task;
    Error_Block eb;

    System_printf("enter main()\n");

    Error_init(&eb);
    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    BIOS_start();     /* enable interrupts and start SYS/BIOS */
}
