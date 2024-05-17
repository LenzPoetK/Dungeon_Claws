#include <Windows.h>

struct game_text {
    char text[500];
    int length;
};

struct player {
    int coord_x;
    int coord_y;
    char movement_keys;
    int HP;
};

struct monster {
    int coord_x;
    int coord_y;
    int movement_keys;
};
