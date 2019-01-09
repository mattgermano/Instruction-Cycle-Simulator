/*
* Lab Exercise 1 - Instruction Cycle Simulator
* Author - Matt Germano and Gary Lam
* Date - 1/8/2019
*/

#include <stdio.h>

// Function Prototypes

int main()
{
    int PC = 300, IR, AC = 0;
    int opcode, address;
    int step = 1;

    int instructions[] = {0x1940, 0x5941, 0x2941, 0x0, 0x0};
    int data[] = {0x3, 0x2};

    printf("BEGIN SIMULATION");

    printf("\n\nInstruction Memory\n");
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        printf("%d %x\t", 300+i, instructions[i]);
    }

    printf("\n\nData Memory\n");
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        printf("%d %x\t", 940+i, data[i]);
    }

    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        /* Fetch Stage */
        IR = instructions[i];

        if (IR == 0)
            continue;

        printf("\n\nStep %d\n", step);
        printf("Fetch instruction from memory location %d\n", PC);
        printf("PC = %d\nAC = %d\nIR = %x\n", PC, AC, IR);

        PC++; /* Increment the Program Counter */
        step++; /* Increment the Step */

        /* Execute Stage */
        opcode = instructions[i] >> 12;
        address = instructions[i] & 0x0FFF;

        printf("\nStep %d\n", step);
        printf("Execute instruction and increment the PC: ");

        switch(opcode)
        {
            case 1: 
                AC = data[address-0x940];   /* Load AC from memory */
                printf("load AC from memory location %x\n", address);
                break;
            case 2: 
                data[address-0x940] = AC;   /* Store AC to memory */
                printf("store AC to memory location %x\n", address);
                break;
            case 5: 
                AC += data[address-0x940];  /* Add to AC from memory */
                printf("add to AC from memory location %x\n", address);
                break;
        }

        printf("PC = %d\nAC = %d\nIR = %x\n", PC, AC, IR);

        step++; /* Increment the Step */
    }

    printf("\n\nInstruction Memory\n");
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        printf("%d %x\t", 300+i, instructions[i]);
    }

    printf("\n\nData Memory\n");
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        printf("%d %x\t", 940+i, data[i]);
    }

    printf("\n\nEND SIMULATION");

    return 0;
}