#include <string.h>

typedef struct {
    char name[20];
    int posX;
    int posY;
    int hp;
    int damage;
} Hero;

void initializeHero(Hero *hero, char *name, int posX, int posY, int hp) {
    strcpy(hero->name, name);
    hero->posX = posX;
    hero->posY = posY; 
    hero->hp = hp;
    hero->damage = 5;
}

void moveHero(Hero *hero, char *direction, int size) {
    if (strcmp(direction, "north") == 0) {
        if(hero->posY == 0) {
            printf("You can't go north, you are at the top of the map.\n");
            return;
        }
        hero->posY--;
    } else if (strcmp(direction, "south") == 0) {
        if(hero->posY == size - 1) {
            printf("You can't go south, you are at the bottom of the map.\n");
            return;
        }
        hero->posY++;
    } else if (strcmp(direction, "west") == 0) {
        if(hero->posX == 0) {
            printf("You can't go west, you are at the left edge of the map.\n");
            return;
        }
        hero->posX--;
    } else if (strcmp(direction, "east") == 0) {
        if(hero->posX == size - 1) {
            printf("You can't go east, you are at the right edge of the map.\n");
            return;
        }
        hero->posX++;
    }
}