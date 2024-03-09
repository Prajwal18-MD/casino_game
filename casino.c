#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void playGame(int *balance);
void displayMenu();

int main() {
    int balance; // Starting balance
    int choice;
    

    printf("Welcome to the Casino!\n");

    printf("Enter your Deposit\n");
    scanf( "%d", &balance); 

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame(&balance);
                break;
            case 2:
                printf("Your current balance is: $%d\n", balance);
                break;
            case 3:
                printf("Thanks for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\n1. Play Game\n");
    printf("2. Check Balance\n");
    printf("3. Quit\n");
}

void playGame(int *balance) {
    int bet;
    char symbols[3] = {'$', '#', '*'};
    srand(time(NULL));

    printf("Enter your bet: ");
    scanf("%d", &bet);

    if (bet > *balance) {
        printf("Insufficient balance. Please place a smaller bet.\n");
        return;
    }

    *balance -= bet;

    printf("Spinning the reels...\n");

    
    char reel1 = symbols[rand() % 3];
    char reel2 = symbols[rand() % 3];
    char reel3 = symbols[rand() % 3];

    printf("Result: [%c] [%c] [%c]\n", reel1, reel2, reel3);

   
    if (reel1 == reel2 && reel2 == reel3) {
        printf("Congratulations! You win!\n");
        *balance += bet * 2; 
    } else {
        printf("Better luck next time!\n");
    }

    printf("Your current balance is: $%d\n", *balance);
}
