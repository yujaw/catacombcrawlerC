typedef struct {
    int id;
    int posX;
    int posY;
    int heal;
} healingPotion;

void initializeHealing(healingPotion *potion, int id, int posX, int posY, int heal) {
    potion->id = id;
    potion->posX = posX;
    potion->posY = posY;
    potion->heal = heal;
}