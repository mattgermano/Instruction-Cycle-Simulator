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

    int instructions = [0x1940, 0x5941, 0x2941];
    int * instruction_ptr = 300

    int data = [0x2, 0x3];
    int * data_ptr = 940;

    printf("BEGIN SIMULATION\n\n");

    printf("Instruction Memory\n");
    for (int i = 0; i < sizeof(instructions)/sizeof(instructions[0]); i++)
    {
        *(instruction_ptr + i) = instructions[i];
        printf("%p %d\t", instruction_ptr, *instruction_ptr);
    }

    printf("Data Memory\n");
    for (int i = 0; i < sizeof(instructions)/sizeof(data[0]); i++)
    {
        *(data_ptr + i) = data[i];
        printf("%p %d", data_ptr, *data_ptr);
    }
}

int decode_opcode(instruction)
{
    opcode = instruction >> 12;
    return opcode;
}

int decode_address(instruction)
{
    address = instruction & 0x0FFF;
    return address;
}