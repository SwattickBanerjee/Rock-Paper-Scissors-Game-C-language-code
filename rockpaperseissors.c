#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generaterandomnumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int greater(char c1, char c2)
{
    if (c1 == c2)
    {
        return -1;
    }
    if (c1 == 'r' && c2 == 's')
    {
        return 1;
    }
    else if (c1 == 's' && c2 == 'r')
    {
        return 0;
    }
    if (c1 == 'p' && c2 == 'r')
    {
        return 1;
    }
    else if (c1 == 'r' && c2 == 'p')
    {
        return 0;
    }
    if (c1 == 's' && c2 == 'p')
    {
        return 1;
    }
    else if (c1 == 'p' && c2 == 's')
    {
        return 0;
    }
}
int main()
{
    int playerscore = 0, compscore = 0, temp;
    char playerchar, compchar;
    char dict[] = {'r', 'p', 's'};
    char m, name[45];
    system("cls");
    printf("Welcome to Rock Paper Scissors\n");
start:
    printf("Press p to play or press q to quit\n");
    scanf("%c", &m);
    getchar();
    if (m == 'p')
    {
        printf("*****Welcome to the game*****\n");
    }
    else if (m == 'q')
    {
        printf("Quiting the game\n");
        goto end;
    }
    else
    {
        printf("Wrong input\n");
        goto start;
    }

    printf("Enter player 1 name\n");
    scanf("%s", &name);
    printf("Welcome to the game %s\n", name);

    for (int i = 0; i < 3; i++)
    {
        //take player 1 input
        printf("%s your turn\n", name);
        printf("Choose 1 for rock, 2 for Paper, 3 for Scissors\n");
        scanf("%d", &temp);
        playerchar = dict[temp - 1];
        if (playerchar == 'r')
        {
            printf("You have chose Rock\n\n");
        }
        else if (playerchar == 'p')
        {
            printf("You have chose Paper\n\n");
        }
        else if (playerchar == 's')
        {
            printf("You have chose Scissors\n\n");
        }

        // printf("You have chose %c\n\n", playerchar);

        //comp turn
        printf("Computer's turn\n");
        temp = generaterandomnumber(3) + 1;
        compchar = dict[temp - 1];
        if (compchar == 'r')
        {
            printf("Computer have chose Rock\n\n");
        }
        else if (compchar == 'p')
        {
            printf("Computer have chose Paper\n\n");
        }
        else if (compchar == 's')
        {
            printf("Computer have chose Scissors\n\n");
        }
        // printf("Computer have chose %c\n\n", compchar);
        if (greater(playerchar, compchar) == 1)
        {
            playerscore += 1;
            printf("%s You got this round\n\n", name);
        }
        else if (greater(playerchar, compchar) == -1)
        {
            playerscore += 1;
            compscore += 1;
            printf("This is draw both side got points\n\n");
        }
        else
        {
            compscore += 1;
            printf("Computer got this round\n\n", name);
        }
        printf(" You : %d\n Computer : %d", playerscore, compscore);
        printf("\n");
    }

    if (playerscore > compscore)
    {
        printf("%s You won the game\n", name);
    }
    else if (playerscore == compscore)
    {
        printf("This is a draw\n");
    }
    else
    {
        printf("Computer won the game\n");
    }

end:
    return 0;
}