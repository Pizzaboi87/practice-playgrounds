#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[15];
    int xp;
    char species[10] = "human";
} Player;

int main()
{
    Player player1 = {"Nunez", 6};
    Player player2 = {"Pepe", 7};
    Player player3 = {"Pottyos", 10, "cat"};
    
    Player players[] = {player1, player2, player3};
    
    for(int i = 0; i < sizeof(players)/sizeof(players[0]); i++)
    {
        printf("Name: %s\n", players[i].name);
        printf("XP: %d\n", players[i].xp);
        printf("Species: %s\n\n", players[i].species);        
    }
    
    return 0;
}