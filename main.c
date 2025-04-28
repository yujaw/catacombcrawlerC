#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "hero.h"
#include "monster.h"
#include "healing.h"

void drawMap(int size, int cataComb[size][size], Hero hero)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (hero.posX == j && hero.posY == i)
                printf("H ");
            else
                printf("%s ", cataComb[j][i] == 0 ? "." : cataComb[j][i] > 0 ? "M" : "P");
        }
        printf("\n");
    }
}

int checkMonster(Hero *hero, int size, int cataComb[size][size])
{
    if (cataComb[hero->posX + 1][hero->posY] > 0 || cataComb[hero->posX - 1][hero->posY] > 0 || cataComb[hero->posX][hero->posY + 1] || cataComb[hero->posX][hero->posY - 1] > 0)
    {
        return 1;
    }

    return 0;
}

int fight(Hero *hero, Monster *monster, int size, int cataComb[size][size])
{
    printf("Fighting monster %d!\n", monster->id);
    while (hero->hp > 0 && monster->hp > 0)
    {
        monster->hp -= rand() % hero->damage + 1;
        printf("Monster %d HP: %d\n", monster->id, monster->hp);
        if (monster->hp <= 0)
        {
            printf("Monster %d defeated!\n", monster->id);
            break;
        }
        hero->hp -= rand() % monster->damage + 1; // Monster attacks
        printf("Hero HP: %d\n", hero->hp);
    }

    if (hero->hp <= 0)
    {
        printf("Hero defeated!\n");
        return 0; // End the game if hero is defeated
    }
    else
    {
        printf("Hero wins!\n");
        return 1;
    }
}

void heal(Hero *hero, healingPotion *potion, int size, int cataComb[size][size])
{
    if (hero->hp < 100)
    {
        printf("Healing....\n");
        printf("Hero HP: %d\n", hero->hp);
        hero->hp += potion->heal;
        if(hero->hp > 100) hero->hp = 100;
        printf("Hero new HP: %d\n", hero->hp);
        cataComb[hero->posX][hero->posY] = 0;
    }
}

int main(void)
{
    int game = 1;
    Hero hero;
    unsigned int size;
    char *name = malloc(20 * sizeof(char));

    printf("Enter your hero's name : ");
    scanf("%s", name);

    printf("Enter the size of the map: ");
    scanf("%d", &size);

    // Seed the random number generator
    srand(time(NULL));

    int cataComb[size][size];
    // Initialize the map with 0s
    memset(cataComb, 0, sizeof(cataComb));

    int monsterCount = (size * size) / 6;
    Monster monster[monsterCount];

    int potionCount = (size * size) / 9;
    healingPotion potion[potionCount];

    initializeHero(&hero, name, 0, 0, 100);

    for (int i = 0; i < monsterCount; i++)
    {
        int a, b;

        do
        {
            a = rand() % size;
            b = rand() % size;
        } while ((a == 0 && b == 0) || (cataComb[a][b] > 0));

        int damage = rand() % 10 + 1;

        initializeMonster(&monster[i], i + 1, a, b, 25, damage);
        cataComb[monster[i].posX][monster[i].posY] = monster[i].id;
    }

    for (int i = 0; i < potionCount; i++)
    {
        int a, b;

        do
        {
            a = rand() % size;
            b = rand() % size;
        } while ((a == 0 && b == 0) || (cataComb[a][b] < 0));

        int heal = rand() % 50 + 1;

        initializeHealing(&potion[i], (i + 1) * (-1), a, b, heal);
        cataComb[potion[i].posX][potion[i].posY] = potion[i].id;
    }

    while (game == 1)
    {
        printf("%s is at X:{%d} Y:{%d}\n", hero.name, hero.posX, hero.posY);
        drawMap(size, cataComb, hero);
        char direction[10];
        if (checkMonster(&hero, size, cataComb))
        {
            printf("I smell monster nearby\n");
        }
        printf("Enter a direction (north, south, east, west): ");
        scanf("%s", direction);
        moveHero(&hero, direction, size);
        if (cataComb[hero.posX][hero.posY] > 0)
        {
            if (fight(&hero, &monster[cataComb[hero.posX][hero.posY] - 1], size, cataComb))
            {
                cataComb[hero.posX][hero.posY] = 0; // Remove the monster from the map
            }
            else
            {
                game = 0; // End the game if hero is defeated
            } // Assuming the first monster is encountered
        }
        else if (cataComb[hero.posX][hero.posY] < 0)
        {
            heal(&hero, &potion[abs(cataComb[hero.posX][hero.posY])], size, cataComb);
        }
        if (hero.posX == size - 1 && hero.posY == size - 1)
        {
            printf("You won!!!\n");
            game = 0;
        }
    }

    return 0;
}