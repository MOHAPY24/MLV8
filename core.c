// Re-implementation of my MBOA8 CPU Emulator in C
// Renamed: MLV8 (Mini Low-level Von neumann 8 bit)
#include <stdio.h>
#include "utils.c"
#include <stdbool.h>

#define MEM_SIZE 65536
#define NUM_REGS 8
unsigned char memory[MEM_SIZE]; // Memory tape
unsigned int ip = 0; // Pointer
int registers[NUM_REGS]; // Registers

void add_opcode(unsigned char opcode, int location){
    memory[location] = opcode;
}

void clear_memory(){
    unsigned int i;
    for(i = 0; i < MEM_SIZE; i++){
        memory[i] = 0;
    }
}

void dump_memory(){
    unsigned int i;
    for(i = 0; i < MEM_SIZE; i++){
        if (i % 16 == 0) printf("\n%04X: ", i);
        printf("%02X ", memory[i]);
    }
}

void dump_registers(){
    unsigned int i;
    for(i = 0; i < NUM_REGS; i++){
        if (i % 1 == 0) printf("\n%04X: ", i);
        printf("%02X ", registers[i]);
    }
}


void clear_registers(){
    unsigned int i;
    for(i = 0; i < NUM_REGS; i++){
        registers[i] = 0;
    }
}

int run(){
    if(check_if_in(0xFF, memory, MEM_SIZE) == false & check_if_in(0xFE, memory, MEM_SIZE) == false){
        printf("ERR! Opcode: '0xFF/0xFE' not found in memory set, stopping to prevent memory overload: 01..\n");
        return 1;
    }
    while(ip < MEM_SIZE && memory[ip] != 0xFF){
        unsigned char opcode = memory[ip];
        opcode = memory[ip];
        printf("Opcode: %u\n", memory[ip]);
        printf("Pointer: %u\n", ip);
        printf("Registers: %d\n", *registers);
        switch (opcode) {
            case 0x01: // LDA
                registers[0] = memory[ip+1];
                ip += 2;
                break;
            case 0x00: // PDA
                ip++;
                break;
            case 0xFF: // HALT
                return 0;
            case 0xFE: // HALTD
                dump_memory();
                dump_registers();
                return 0;
            case 0x02: // ADD
                registers[0] += memory[ip + 1];
                ip += 2;
                break;
            case 0x03: // SUB
                registers[0] -= memory[ip + 1];
                ip += 2;
                break;
            case 0x10: // JMP
                ip = memory[ip + 1];
                break;
            case 0x11: // JZ
                if(registers[0] == 0) ip = memory[ip + 1];
                else ip ++;
                break;
            case 0x04: // STA
                ip++;
                memory[memory[ip + 1]] = registers[0];
                break;
            case 0x12: // RSE
                clear_memory();
                clear_registers();
                ip = 0;
                break;
            case 0x13: // CLR
                clear_memory();
                clear_registers();
                ip++;
                break;
        }
    }
    return 0;
}