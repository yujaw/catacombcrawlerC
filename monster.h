#include <math.h>

typedef struct {
    int id;
    int posX;
    int posY;
    int hp;
    int damage;
} Monster;

void initializeMonster(Monster *monster, int id, int posX, int posY, int hp, int damage) {
    monster->id = id;
    monster->posX = posX;
    monster->posY = posY;
    monster->hp = hp;
    monster->damage = damage;
}