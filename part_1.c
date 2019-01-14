/*
* Lab Exercise 1 - Instruction Cycle Simulator
* Author - Matt Germano and Gary Lam
* Date - 1/8/2019
*/

#include <stdio.h>

int main()
{
    int PC = 300, AC = 0, IR;
    int opcode, address;
    int step = 1;

    /* Arrays to store the list of instructions and data */
    int instructions[] = {0x1940, 0x5941, 0x2941, 0x0, 0x0};
    int data[] = {3, 2, 0, 0, 0};

    printf("BEGIN SIMULATION");

    /* Print the contents of the instruction and data memory */
    printf("\n\nInstruction Memory\n");
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        printf("%d %x\t", 300+i, instructions[i]);
    }

    printf("\n\nData Memory\n");
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        printf("%d %d\t", 940+i, data[i]);
    }

    /* Fetch and execute each instruction in memory by decoding its opcode and address */
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        /* Fetch Stage */
        IR = instructions[i]; /* Copy the instruction in memory to the instruction register */

        /* Skip the instruction if it is 0 (no data) */
        if (IR == 0)
            continue;

        printf("\nStep %d\n", step);
        printf("Fetch instruction from memory location %d\n", PC);
        printf("PC = %d\nAC = %d\nIR = %x\n", PC, AC, IR);

        PC++;   /* Increment the Program Counter */
        step++; /* Increment the Step */

        /* Execute Stage */
        opcode = instructions[i] >> 12;     /* Right shift the instruction by 12 bits to determine the opcode */
        address = instructions[i] & 0x0FFF; /* Bitwise AND the instruction with 0x0FFF to determine the address */

        printf("\nStep %d\n", step);
        printf("Execute the instruction and increment the PC: ");

        switch(opcode)
        {
            case 1: 
                AC = data[address-0x940];   /* Load AC from memory */
                printf("Load AC from memory location %x\n", address);
                break;
            case 2: 
                data[address-0x940] = AC;   /* Store AC to memory */
                printf("Store AC to memory location %x\n", address);
                printf("%x = %d data memory location update\n", address, AC);
                break;
            case 5: 
                AC += data[address-0x940];  /* Add to AC from memory */
                printf("Add to AC from memory location %x\n", address);
                break;
            default:
                printf("Opcode not found...no action taken\n");
        }

        printf("PC = %d\nAC = %d\nIR = %x", PC, AC, IR);

        step++; /* Increment the Step */
    }

    /* Print the updated contents of the instruction and data memory */
    printf("\nInstruction Memory\n");
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        printf("%d %x\t", 300+i, instructions[i]);
    }

    printf("\n\nData Memory\n");
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); i++)
    {
        printf("%d %d\t", 940+i, data[i]);
    }

    printf("\n\nEND SIMULATION");

    return 0;
}