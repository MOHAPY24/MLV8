#include "core.c"
#include <stdio.h>
#include <string.h>



int main(){
    char command[256];
    int location = 0;
    printf("MLV8 >> ");
    scanf("%s", command);
    printf("Location >> ");
    scanf("%d", &location);
    add_opcode(parse_opcode(command), location);
    if(strcmp(command, "0x00") != 0){
        add_opcode(1, location+1);
        add_opcode(0xFF, location+2);
    }
    else {
        add_opcode(0xFF, location+1);
    }
    run();
    return 0;
}