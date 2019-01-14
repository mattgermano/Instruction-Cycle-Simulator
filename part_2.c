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
    int instructions[] = {0x3005, 0x5940, 0x9941, 0x7006, 0x2942, 0x3005, 0x8942, 0x6943, 0x2944, 0x7006};
    int data[] = {3, 5, 0, 10, 0};

    /* Arrays to store the device data */
    int device_5[] = {2, 13};
    int device_6[] = {0, 0};

    int device_5_index = 0;
    int device_6_index = 0;

    printf("BEGIN SIMULATION");

    /* Print the contents of the instruction, data, and device memory */
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

    printf("\n\nDevice 5 Memory\n");
    for (int i = 0; i < sizeof(device_5)/sizeof(device_5[0]); i++)
    {
        printf("%d\t", device_5[i]);
    }

    printf("\n\nDevice 6 Memory\n");
    for (int i = 0; i < sizeof(device_6)/sizeof(device_6[0]); i++)
    {
        printf("%d\t", device_6[i]);
    }

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

        PC++; /* Increment the Program Counter */
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
                printf("Load AC from memory location %x\n", address);
                break;
            case 2: 
                data[address-0x940] = AC;   /* Store AC to memory */
                printf("Store AC to memory location %x\n", address);
                break;
            case 3:
                if (address == 5) /* Load AC from I/O */
                {
                    AC = device_5[device_5_index];
                    device_5_index++;
                }
                else
                {
                    AC = device_6[device_6_index];
                    device_6_index++;
                }
                printf("Load AC from I/O\n");
                break;
            case 5: 
                AC += data[address-0x940];  /* Add to AC from memory */
                printf("Add to AC from memory location %x\n", address);
                break;
            case 6: 
                AC -= data[address-0x940];  /* Subtract memory from AC */
                printf("Subtract AC from memory location %x\n", address);
                break;
            case 7:
                if (address == 5) /* Store AC to I/O */
                {
                    device_5[device_5_index] = AC;
                    device_5_index++;
                }
                else
                {
                    device_6[device_6_index] = AC;
                    device_6_index++;
                } 
                printf("Store AC to I/O\n");
                break;
            case 8:
                AC *= data[address-0x940];  /* Multiply AC with memory */
                printf("Multiply AC from memory location %x\n", address);
                break;
            case 9:
                AC /= data[address-0x940];  /* Divide AC by memory */
                printf("Divide AC from memory location %x\n", address);
                break;
            default:
                printf("Opcode not found...no action taken\n");
        }

        printf("PC = %d\nAC = %d\nIR = %x\n", PC, AC, IR);

        step++; /* Increment the Step */
    }

    /* Print the updated contents of the instruction, data, and device memory */
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

    printf("\n\nDevice 5 Memory\n");
    for (int i = 0; i < sizeof(device_5)/sizeof(device_5[0]); i++)
    {
        printf("%d\t", device_5[i]);
    }

    printf("\n\nDevice 6 Memory\n");
    for (int i = 0; i < sizeof(device_6)/sizeof(device_6[0]); i++)
    {
        printf("%d\t", device_6[i]);
    }

    printf("\n\nEND SIMULATION");

    return 0;
}