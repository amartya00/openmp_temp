/*
 *  ======== main.c ========
 */

#include "main.h"



/*
 *  ======== taskFxn ========
 */
Void taskFxn(UArg a0, UArg a1)
{


    printf("enter taskFxn()\n");

    vector_stream_sp();

    printf("exit taskFxn()\n");
}

/*
 *  ======== main ========
 */
Void main()
{ 
    Task_Handle task;
    Error_Block eb;

    printf("enter main()\n");

    Error_init(&eb);
    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
        printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
    BIOS_start();     /* enable interrupts and start SYS/BIOS */
}
