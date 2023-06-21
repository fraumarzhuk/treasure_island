#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "logo.h"
#include <stdbool.h>
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_RED "\x1b[31m"

bool game_on = true;
// A function to make responces to lower case
void toLowercase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}
void playAgaginf()
{
    char playAgain[50];
    printf(ANSI_COLOR_BLUE "Do you want to play again?\n" ANSI_COLOR_RESET);
    scanf("%49s", playAgain);
    getchar();
    toLowercase(playAgain);
    if ((strstr(playAgain, "yes") != NULL) || (strstr(playAgain, "y") != NULL) || ((strstr(playAgain, "okay") != NULL)) || ((strstr(playAgain, "go") != NULL)))
    {
        game_on = true;
    }
    else
    {
        printf("Good bye.\n");
        game_on = false;
    }
}

// Main function
void playGame()
{
    printf(ANSI_COLOR_BLUE "Ready to go?\n" ANSI_COLOR_RESET);
    char answer1[50];
    scanf("%49s", answer1);
    getchar(); // Consume the newline character
    toLowercase(answer1);

    if ((strstr(answer1, "yes") != NULL) || (strstr(answer1, "y") != NULL) || ((strstr(answer1, "okay") != NULL)) || ((strstr(answer1, "go") != NULL))) // Checking if the answer contains yes or y
    {
        printf(ANSI_COLOR_BLUE "Ok let's go!\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "You can use any answers to proceed with your adventure, but I still recommend you to be specific.\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "You are standing in the forest. The sky above is very dark, it's almost midnight and you are feeling pretty cold.\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_BLUE "You can go East, West, North or South\n" ANSI_COLOR_RESET); // West, North or South left
        char answer2[50];
        scanf("%49s", answer2);
        getchar();
        toLowercase(answer2);
        if (strstr(answer2, "east") != NULL)
        {
            printf(ANSI_COLOR_BLUE "You keep walking for 20 minutes. It's getting even more dark and more cold. You also start to feel a bit thirsty. \n" ANSI_COLOR_RESET);
            printf(ANSI_COLOR_BLUE "Then accidentally you see an enourmous bear. Whout would you do? Fight or run?\n" ANSI_COLOR_RESET); // run left
            char answerFight[50];
            char answerContinue[50];
            scanf("%49s", answerFight);
            getchar();
            toLowercase(answerFight);
            if (strstr(answerFight, "fight") != NULL)
            {
                printf(ANSI_COLOR_BLUE "The bear is really strong and seems like you don't have any chance to win.\n" ANSI_COLOR_RESET);
                printf(ANSI_COLOR_BLUE "Do you want to continue fighting or you better run away?\n" ANSI_COLOR_RESET);
                scanf("%49s", answerContinue);
                getchar();
                toLowercase(answerContinue);
                if ((strstr(answerContinue, "continue") != NULL) || (strstr(answerContinue, "fight") != NULL))
                {
                    printf(ANSI_COLOR_RED "The bear has eaten you. What a pity death..." ANSI_COLOR_RESET);
                    printDeath();
                    printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
                    playAgaginf();
                }
                else if (strstr(answerContinue, "run") != NULL)
                {
                    printf(ANSI_COLOR_BLUE "You were very slow...\n" ANSI_COLOR_RESET);
                    printDeath();
                    printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
                    playAgaginf();
                }
            }
            else if ((strstr(answerFight, "run") != NULL))
            {
                printf(ANSI_COLOR_BLUE "You were very slow...\n" ANSI_COLOR_RESET);
                printDeath();
                printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
                playAgaginf();
            }
        }
        else if (strstr(answer2, "west") != NULL)
        {
            printf(ANSI_COLOR_BLUE "Oh no...You fell into a big whole and died..." ANSI_COLOR_RESET);
            printDeath();
            printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
            playAgaginf();
        }
        else if (strstr(answer2, "north") != NULL)
        {
            printf(ANSI_COLOR_BLUE "Oh no...You fell into a big whole and died..." ANSI_COLOR_RESET);
            printDeath();
            printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
            playAgaginf();
        }
        else if (strstr(answer2, "south") != NULL)
        {
            printf(ANSI_COLOR_BLUE "Oh no...You fell into a big whole and died..." ANSI_COLOR_RESET);
            printDeath();
            printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
            playAgaginf();
        }
    }
    else
    {
        printf(ANSI_COLOR_BLUE "Wow, you don't really like to risk. But you saved your life at least\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "Game Over.\n" ANSI_COLOR_RESET);
        // Play again
        playAgaginf();
    }
}

int main()
{

    printLogo();
    printf(ANSI_COLOR_BLUE "Welcome to the Treasure Island. You can try to find a golden chest today, but be careful. A mistake can cost you a life\n" ANSI_COLOR_RESET);
    while (game_on == true)
    {
        playGame(); // Start the game
    }

    return 0;
}
