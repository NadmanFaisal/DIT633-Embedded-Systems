#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main(int argc, char **argv) {
    if(argc != 6) {
        printf("Invalid number of arguements!\n");
        return 0;
    }

    byte engine_on = atoi(argv[1]);
    byte floor_pos = atoi(argv[2]);
    byte door_pos = atoi(argv[3]);
    byte brake_1 = atoi(argv[4]);
    byte brake_2 = atoi(argv[5]);

    byte result = 0;
    result |= (engine_on & 0b1);
    result = result << 3;

    result |= (floor_pos & 0b111);
    result = result << 2;

    result |= (door_pos & 0b11);
    result = result << 1;

    result |= (brake_1 & 0b1);
    result = result << 1;

    result |= (brake_2 & 0b1);

    printf("0x%X\n", result);
    return 0;
}