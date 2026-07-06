#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user_choice, computer_choice;
    
    // Using a string array to cleanly map numbers (0, 1, 2) to words
    char *choices[] = {"Rock", "Paper", "Scissors"};

    // Seed the random number generator
    srand(time(NULL));

    // 1. Get and validate user input
    printf("=== Rock, Paper, Scissors ===\n");
    printf("Enter 0 for Rock, 1 for Paper, 2 for Scissors: ");
    
    if (scanf("%d", &user_choice) != 1 || user_choice < 0 || user_choice > 2) {
        printf("Error: Invalid choice. Please enter 0, 1, or 2.\n");
        return 1; 
    }

    // 2. Generate computer choice (0, 1, or 2)
    computer_choice = rand() % 3;

    // 3. Display choices using the array
    printf("\nYou chose: %s\n", choices[user_choice]);
    printf("Computer chose: %s\n", choices[computer_choice]);
    printf("-------------------------\n");

    // 4. Determine the winner with readable, human-like logic
    if (user_choice == computer_choice) {
        printf("It's a tie game!\n");
    } 
    // Clear check for all user winning conditions
    else if ((user_choice == 0 && computer_choice == 2) ||  // Rock beats Scissors
             (user_choice == 1 && computer_choice == 0) ||  // Paper beats Rock
             (user_choice == 2 && computer_choice == 1)) {  // Scissors beats Paper
        printf("You win! Congratulations!\n");
    } 
    // If it's not a tie and you didn't win, the computer did
    else {
        printf("Computer wins! Better luck next time.\n");
    }

    return 0;
}