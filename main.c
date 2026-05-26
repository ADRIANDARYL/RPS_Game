#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char user[20];
    char play_again[10];

    char *choices[] = {"rock", "paper", "scissors"};

    srand(time(0));

    while (1) {

        printf("\n=== Rock Paper Scissors ===\n");
        printf("Choose rock, paper, or scissors: ");
        scanf("%19s", user);

        // Convert input to lowercase manually
        for (int i = 0; user[i]; i++) {
            if (user[i] >= 'A' && user[i] <= 'Z') {
                user[i] = user[i] + 32;
            }
        }

        // Validate input
        if (
            strcmp(user, "rock") != 0 &&
            strcmp(user, "paper") != 0 &&
            strcmp(user, "scissors") != 0
        ) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        int random_index = rand() % 3;
        char *computer = choices[random_index];

        printf("\nYou chose: %s\n", user);
        printf("Computer chose: %s\n", computer);

        // Determine winner
        if (strcmp(user, computer) == 0) {
            printf("It's a tie!\n");
        }
        else if (
            (strcmp(user, "rock") == 0 && strcmp(computer, "scissors") == 0) ||
            (strcmp(user, "paper") == 0 && strcmp(computer, "rock") == 0) ||
            (strcmp(user, "scissors") == 0 && strcmp(computer, "paper") == 0)
        ) {
            printf("You win!\n");
        }
        else {
            printf("Computer wins!\n");
        }

        // Replay validation loop
        while (1) {
            printf("\nPlay again? (yes/no): ");
            scanf("%9s", play_again);

            // Convert replay input to lowercase
            for (int i = 0; play_again[i]; i++) {
                if (play_again[i] >= 'A' && play_again[i] <= 'Z') {
                    play_again[i] = play_again[i] + 32;
                }
            }

            if (strcmp(play_again, "yes") == 0) {
                break;
            }
            else if (strcmp(play_again, "no") == 0) {
                printf("\nThanks for playing!\n");
                return 0;
            }
            else {
                printf("Invalid input. Please type yes or no.\n");
            }
        }
    }

    return 0;
}
