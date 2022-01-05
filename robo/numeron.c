#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Eranp[3], Branp[3];
void shuffle(char array[], int size)
{
    srand((int)time(NULL));
    for (int i = 0; i < size; i++)
    {
        int j = rand() % size;
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}
void game(char user[], char rdom[])
{
    int n = 0, y = 0;
    for (int i = 0; i < 3; i++)
    {
        if (user[i] == rdom[i])
        {
            Eranp[n] = 1;
            n++;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int w = 0; w < 3; w++)
        {
            if (rdom[i] == user[w])
            {
                Branp[y] = 1;
                y++;
            }
        }
    }
}
int main()
{
    char array[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char user[3];
    shuffle(array, 9);
    for (int i = 0; i < 3; i++)
    {
        printf("%c", array[i]);
    }
    scanf("%c%c%c", &user[0], &user[1], &user[2]);
    game(array, user);
    for (int i = 0; i < 3; i++)
    {
        printf("B:%d", Branp[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("E:%d", Eranp[i]);
    }
}