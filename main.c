#include "core.c"

int main(){
    add_opcode(0x00, 0x00);
    add_opcode(0x01, 0x01);
    add_opcode(2, 2);
    add_opcode(0x02, 0x03);
    add_opcode(2, 4);
    add_opcode(0xFF, 0x05);
    run();
    return 0;
}