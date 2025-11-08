#include "core.c"




int main(){
    add_opcode(parse_opcode("0x02"), 0x00);
    add_opcode(parse_opcode("0x02"), 0x02);
    add_opcode(parse_opcode("0x02"), 0x03);
    add_opcode(parse_opcode("0x02"), 0x04);
    add_opcode(parse_opcode("0x01"), 0x05);
    add_opcode(0x00, 0x06);
    add_opcode(0xFF, 0x07);
    run();
    return 0;
}