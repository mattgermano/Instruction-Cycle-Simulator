/*
* Lab Exercise 1 - Instruction Cycle Simulator
* Author - Matt Germano and Gary Lam
* Date - 1/8/2019
*/

#include <stdio.h>

// Function Prototypes
void dump_memory(int[], int, int);

int main()
{
    int PC = 300, AC = 0, IR;
    int opcode, address;
    int step = 1;

    /* Arrays to store the list of instructions and data */
    int instructions[] = {0x1940, 0x5941, 0x2941};
    int data[] = {0x3, 0x2};

    printf("BEGIN SIMULATION");

    /* Print the contents of the instruction and data memory */
    dump_memory(instructions, sizeof(instructions)/sizeof(instructions[0]), 300);
    dump_memory(data, sizeof(data)/sizeof(data[0]), 940);

    /* Fetch and execute each instruction in memory by decoding its opcode and address */
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        /* Fetch Stage */
        IR = instructions[i]; /* Copy the instruction in memory to the instruction register */

        if (IR == 0)
            continue;

        printf("\n\nStep %d\n", step);
        printf("Fetch instruction from memory location %d\n", PC);
        printf("PC = %d\nAC = %x\nIR = %x\n", PC, AC, IR);

        PC++;   /* Increment the Program Counter */
        step++; /* Increment the Step */

        /* Execute Stage */
        opcode = instructions[i] >> 12;     /* Right shift the instruction by 12 bits to determine the opcode */
        address = instructions[i] & 0x0FFF; /* Bitwise AND the instruction with 0x0FFF to determine the address */

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

        printf("PC = %d\nAC = %x\nIR = %x\n", PC, AC, IR);

        step++; /* Increment the Step */
    }

    /* Print the updated contents of the instruction and data memory */
    dump_memory(instructions, sizeof(instructions)/sizeof(instructions[0]), 300);
    dump_memory(data, sizeof(data)/sizeof(data[0]), 940);

    printf("\n\nEND SIMULATION");

    return 0;
}

void dump_memory(int array[], int size, int address)
{
    if (address == 300)
        printf("\n\nInstruction Memory\n");
    else if (address == 940)
        printf("\n\nData Memory\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d %x\t", address+i, array[i]);
    }
}