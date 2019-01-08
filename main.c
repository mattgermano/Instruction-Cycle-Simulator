/*
* Lab Exercise 1 - Instruction Cycle Simulator
* Author - Matt Germano and Gary Lam
* Date - 1/8/2019
*/

#include <stdio.h>

// Function Prototypes
int decode_opcode(int);
int decode_address(int);

int main()
{
    int PC, IR, AC = 0;

    int instructions[] = {0x1940, 0x5941, 0x2941};
    int data[] = {0x2, 0x3};
    
    int * instruction_ptr = (int*) 300;
    int * data_ptr = (int*) 940;

    printf("BEGIN SIMULATION");

    printf("\n\nInstruction Memory");
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        *(instruction_ptr + i) = instructions[i];
        printf("%d\t", instruction_ptr + i);
    }

    printf("\n\nData Memory");
    for (int i = 0; i < sizeof(instructions)/sizeof(data[0]); i++)
    {
        *(data_ptr + i) = data[i];
        printf("%p %d", data_ptr, *data_ptr);
    }
}

int decode_opcode(int instruction)
{
    int opcode;
    opcode = instruction >> 12;
    return opcode;
}

int decode_address(int instruction)
{
    int address;
    address = instruction & 0x0FFF;
    return address;
}