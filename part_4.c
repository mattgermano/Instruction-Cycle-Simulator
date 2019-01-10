/*
* Lab Exercise 1 - Instruction Cycle Simulator
* Author - Matt Germano and Gary Lam
* Date - 1/8/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes

int main()
{
    int PC = 300, IR, AC = 0;
    int opcode, address;
    int step = 1;

    int instructions[] = {0x3005, 0x0000, 0x5940, 0x9941, 0x7006, 0x0000, 0x2942, 0x3005, 0x0000, 
                          0x8942, 0x6943, 0x2944, 0x7006, 0x0000};
    int data[] = {0x3, 0x5, 0x0, 0x10, 0x0};

    int device_5_index = 0;
    int device_6_index = 0;

    int device_5[] = {0x2, 0x13};
    int device_6[] = {0, 0};

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

    srand(time(NULL));
    int random;

    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        /* Fetch Stage */
        IR = instructions[i];

        if (IR == 0)
        {
            random = rand() % 3;
            printf("Random: %d", random);
        }

        if (random == 0)
        {
            printf("\nINTERRUPT");
            continue;
        }
        else
        {
            random--;
        }

        printf("\n\nStep %d\n", step);
        printf("Fetch instruction from memory location %d\n", PC);
        printf("PC = %d\nAC = %x\nIR = %x\n", PC, AC, IR);

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
            case 3:
                if (address == 5)
                {
                    AC = device_5[device_5_index];
                    device_5_index++;
                }
                else
                    AC = device_6[0];
                printf("load AC from I/O\n");
                break;
            case 5: 
                AC += data[address-0x940];  /* Add to AC from memory */
                printf("add to AC from memory location %x\n", address);
                break;
            case 6: 
                AC -= data[address-0x940];  /* Add to AC from memory */
                printf("subtract AC from memory location %x\n", address);
                break;
            case 7:
                if (address == 5)
                    device_5[0] = AC;
                else
                {
                    device_6[device_6_index] = AC;
                    device_6_index++;
                } 
                printf("store AC to I/O\n");
                break;
            case 8:
                AC *= data[address-0x940];  /* Add to AC from memory */
                printf("multiply AC from memory location %x\n", address);
                break;
            case 9:
                AC /= data[address-0x940];  /* Add to AC from memory */
                printf("divide AC from memory location %x\n", address);
                break;

        }

        printf("PC = %d\nAC = %x\nIR = %x\n", PC, AC, IR);

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

    printf("\n\nDevice 6 Memory\n");
    for (int i = 0; i < sizeof(device_6)/sizeof(device_6[0]); i++)
    {
        printf("%d\t", device_6[i]);
    }

    printf("\n\nEND SIMULATION");

    return 0;
}