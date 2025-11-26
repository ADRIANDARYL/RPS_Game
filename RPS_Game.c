#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//Comps Choice
char* CompsGuess(){
    int guess = rand() % 3;
    if (guess == 0)
        return "rock";
    else if (guess == 1)
        return "paper";
    else
        return "scissor";
}

//Results
void winner(char* player,char* computer){

     if (strcmp(player, computer) == 0 ) {
        printf("It is a draw Daryl!");
     }else if ((strcmp(player, "rock")==0 && strcmp(computer, "scissor")==0)||
            (strcmp(player , "paper")==0 && strcmp(computer , "rock")==0)||
            (strcmp(player , "scissor")==0 && strcmp(computer , "paper")==0)){
        printf("You Win Daryl!!!");
     }else if ((strcmp(player , "rock")==0 && strcmp(computer , "paper")==0) ||
            (strcmp(player , "paper")==0 && strcmp(computer , "scissor")==0) ||
            (strcmp(player , "scissor")==0 && strcmp(computer , "rock")==0)){
        printf("You Win Daryl!!!");

    }else{
        printf("Incorrect choice Daryl. Try again");
    }
}


int main()
{
    char player[10];
    srand(time(0));

    //players choice
    printf("Enter your choice (either rock, paper or scissor):");
    scanf("%s", &player);
    printf("Your choice is %s\n", player);

    char* computerChoice = CompsGuess();
        printf("Computer's choice is %s\n",computerChoice);

    winner(player, computerChoice);
    return 0;

}

