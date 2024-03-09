#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

// Function prototypes
void displayMenu();
void playBlackjack();
void playRoulette();
void playSlots();
void playDiceGame();
void playPoker();
void playBaccarat();
void playCraps();
void playKeno();
void playBingo();
void playWheelOfFortune();

int main() {
    int choice;

    printf("Welcome to the Casino!\n");

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playBlackjack();
                break;
            case 2:
                playRoulette();
                break;
            case 3:
                playSlots();
                break;
            case 4:
                playDiceGame();
                break;
            case 5:
                playPoker();
                break;
            case 6:
                playBaccarat();
                break;
            case 7:
                playCraps();
                break;
            case 8:
                playKeno();
                break;
            case 9:
                playBingo();
                break;
            case 10:
                playWheelOfFortune();
                break;
            case 11:
                printf("Thanks for playing! Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}

void displayMenu() {
    printf("\n1. Blackjack\n");
    printf("2. Roulette\n");
    printf("3. Slot Machine\n");
    printf("4. Dice Game\n");
    printf("5. Poker\n");
    printf("6. Baccarat\n");
    printf("7. Craps\n");
    printf("8. Keno\n");
    printf("9. Bingo\n");
    printf("10. Wheel of Fortune\n");
    printf("11. Quit\n");
}
int drawCard() {
    return rand() % 10 + 1; // Random card value between 1 and 10
}
int calculateHandValue(int hand[], int cardCount) {
    int total = 0;
    int aceCount = 0;

    for (int i = 0; i < cardCount; i++) {
        total += hand[i];
        if (hand[i] == 1) { // Ace
            aceCount++;
        }
    }

    // If there are aces, adjust total to maximize it without busting
    while (total <= 11 && aceCount > 0) {
        total += 10;
        aceCount--;
    }

    return total;
}

void playBlackjack() {
    
    printf("Playing Blackjack...\n");

    
    int playerHand[10]; // Array to store player's hand
    int dealerHand[10]; // Array to store dealer's hand
    int playerTotal = 0;
    int dealerTotal = 0;
    int playerCardCount = 0;
    int dealerCardCount = 0;
    char choice;
    srand(time(NULL));

    // Deal initial cards
    playerHand[playerCardCount++] = drawCard();
    dealerHand[dealerCardCount++] = drawCard();
    playerHand[playerCardCount++] = drawCard();
    dealerHand[dealerCardCount++] = drawCard();

    // Calculate initial totals
    playerTotal = calculateHandValue(playerHand, playerCardCount);
    dealerTotal = calculateHandValue(dealerHand, dealerCardCount);

    // Display initial hands
    printf("\nYour hand: %d\n", playerTotal);
    printf("Dealer's hand: %d\n", dealerHand[0]);

    // Player's turn
    while (playerTotal < 21) {
        printf("Do you want to hit (h) or stand (s)? ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            playerHand[playerCardCount++] = drawCard();
            playerTotal = calculateHandValue(playerHand, playerCardCount);
            printf("Your hand: %d\n", playerTotal);

            if (playerTotal > 21) {
                printf("Busted! You lose.\n");
                return;
            }
        } else if (choice == 's') {
            break;
        } else {
            printf("Invalid choice. Please enter 'h' to hit or 's' to stand.\n");
        }
    }

    // Dealer's turn
    while (dealerTotal < 17) {
        dealerHand[dealerCardCount++] = drawCard();
        dealerTotal = calculateHandValue(dealerHand, dealerCardCount);
    }

    printf("Dealer's hand: %d\n", dealerTotal);

    // Determine the winner
    if (dealerTotal > 21 || playerTotal > dealerTotal) {
        printf("Congratulations! You win!\n");
    } else if (dealerTotal > playerTotal) {
        printf("Dealer wins. Better luck next time!\n");
    } else {
        printf("It's a tie!\n");
    }
}





int spinRoulette() {
    return rand() % 37; // Generate a random number between 0 and 36
}

void playRoulette() {

    printf("Playing  Roulette...\n");

    int bet;
    int number;
    int result;
    srand(time(NULL));

    printf("Enter your bet amount: ");
    scanf("%d", &bet);

    printf("Enter your bet number (0-36): ");
    scanf("%d", &number);

    if (number < 0 || number > 36) {
        printf("Invalid bet number. Please bet between 0 and 36.\n");
        return;
    }

    result = spinRoulette();

    printf("The ball landed on: %d\n", result);

    if (number == result) {
        printf("Congratulations! You win %d times your bet!\n", bet * 35);
    } else {
        printf("Sorry, you lose. Better luck next time!\n");
    }
}



void playSlots() {

    printf("Playing Slots...\n");
    int bet;
    char symbols[6] = {'$', '#', '*', '@', '&', '%'};
    char reel1, reel2, reel3;
    srand(time(NULL));

    printf("Enter your bet amount: ");
    scanf("%d", &bet);

    if (bet <= 0) {
        printf("Invalid bet amount. Please enter a positive value.\n");
        return;
    }

    printf("Spinning the reels...\n");

    // Generate random symbols for the three reels
    reel1 = symbols[rand() % 6];
    reel2 = symbols[rand() % 6];
    reel3 = symbols[rand() % 6];

    printf("Result: [%c] [%c] [%c]\n", reel1, reel2, reel3);

    // Check for win conditions
    if (reel1 == reel2 && reel2 == reel3) {
        printf("Congratulations! You win %d times your bet!\n", bet * 2);
    } else {
        printf("Better luck next time!\n");
    }
}

void playDiceGame() {

    printf("Playing Dice game...\n");
    int bet, guess, roll;
    srand(time(NULL));

    printf("Enter your bet amount: ");
    scanf("%d", &bet);

    printf("Guess the sum of two dice (2-12): ");
    scanf("%d", &guess);

    if (guess < 2 || guess > 12) {
        printf("Invalid guess. Please enter a number between 2 and 12.\n");
        return;
    }

    roll = (rand() % 6 + 1) + (rand() % 6 + 1); // Roll two dice and sum the result

    printf("The dice are rolled: %d and %d, sum is %d\n", roll - (rand() % 6 + 1), roll + (rand() % 6 + 1), roll);

    // Check if the guess matches the roll
    if (guess == roll) {
        printf("Congratulations! You win %d times your bet!\n", bet * 5);
    } else {
        printf("Sorry, you lose. Better luck next time!\n");
    }
}


void playPoker() {
    printf("Playing Poker.....\n");
    const int NUM_CARDS = 5;
    const int NUM_RANKS = 13;
    const int NUM_SUITS = 4;

    char *ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    char deck[NUM_RANKS * NUM_SUITS][20];
    char hand[NUM_CARDS][20];

    srand(time(NULL));

    // Initialize the deck
    int card = 0;
    for (int rank = 0; rank < NUM_RANKS; rank++) {
        for (int suit = 0; suit < NUM_SUITS; suit++) {
            sprintf(deck[card], "%s of %s", ranks[rank], suits[suit]);
            card++;
        }
    }

    // Shuffle the deck
    for (int i = 0; i < NUM_RANKS * NUM_SUITS; i++) {
        int j = rand() % (NUM_RANKS * NUM_SUITS);
        char temp[20];
        strcpy(temp, deck[i]);
        strcpy(deck[i], deck[j]);
        strcpy(deck[j], temp);
    }

    // Deal the initial hand
    printf("Your hand:\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        strcpy(hand[i], deck[i]);
        printf("%d. %s\n", i + 1, hand[i]);
    }

    // Allow the player to discard and draw cards
    printf("\nEnter the numbers of cards you want to discard (e.g., '1 3' for first and third cards): ");
    int discard[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        discard[i] = 0;
    }
    int numDiscard = 0;
    do {
        scanf("%d", &discard[numDiscard]);
        numDiscard++;
    } while (getchar() != '\n');

    // Replace discarded cards
    for (int i = 0; i < numDiscard; i++) {
        strcpy(hand[discard[i] - 1], deck[i + NUM_CARDS]);
    }

    // Display the final hand
    printf("\nYour final hand:\n");
    for (int i = 0; i < NUM_CARDS; i++) {
        printf("%d. %s\n", i + 1, hand[i]);
    }

    // Determine hand ranking (not implemented in this simplified version)
    printf("\nHand ranking: (Not implemented in this simplified version)\n");
}



void playBaccarat() {

    printf("Playing Baccarat.....\n");
    int player, banker;
    srand(time(NULL));

    // Deal cards for player and banker
    player = rand() % 10 + 1;
    banker = rand() % 10 + 1;

    printf("Player: %d\n", player);
    printf("Banker: %d\n", banker);

    // Determine the winner based on the sum of their cards
    if (player > banker) {
        printf("Player wins!\n");
    } else if (banker > player) {
        printf("Banker wins!\n");
    } else {
        printf("It's a tie!\n");
    }
}
    
void playCraps() {
    printf("Playing  Craps......\n");
    int point;
    int roll1, roll2, sum;
    srand(time(NULL));

    // Roll two dice
    roll1 = rand() % 6 + 1;
    roll2 = rand() % 6 + 1;
    sum = roll1 + roll2;

    printf("First roll: %d + %d = %d\n", roll1, roll2, sum);

    // Determine game state
    if (sum == 7 || sum == 11) {
        printf("You win!\n");
    } else if (sum == 2 || sum == 3 || sum == 12) {
        printf("You lose!\n");
    } else {
        point = sum;
        printf("Point is set to %d\n", point);
        
        do {
            roll1 = rand() % 6 + 1;
            roll2 = rand() % 6 + 1;
            sum = roll1 + roll2;
            printf("Next roll: %d + %d = %d\n", roll1, roll2, sum);
        } while (sum != 7 && sum != point);

        if (sum == point) {
            printf("You win!\n");
        } else {
            printf("You lose!\n");
        }
    }
}  

void playKeno() {

    printf("Playing Keno........\n");
    int selectedNumbers[10];
    int drawnNumbers[20];
    int matches = 0;
    srand(time(NULL));

    // Player selects 10 numbers
    printf("Select 10 numbers (1-80):\n");
    for (int i = 0; i < 10; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &selectedNumbers[i]);
    }

    // Drawing 20 random numbers
    printf("Drawing 20 numbers:\n");
    for (int i = 0; i < 20; i++) {
        drawnNumbers[i] = rand() % 80 + 1;
        printf("%d ", drawnNumbers[i]);
    }
    printf("\n");

    // Checking for matches
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (selectedNumbers[i] == drawnNumbers[j]) {
                matches++;
                break;
            }
        }
    }

    // Determining the outcome
    printf("You matched %d numbers.\n", matches);
    switch (matches) {
        case 0:
            printf("Sorry, you didn't match any numbers.\n");
            break;
        case 1:
        case 2:
            printf("Sorry, you didn't win anything.\n");
            break;
        default:
            printf("Congratulations! You won!\n");
            break;
    }
}

void playBingo() {
    printf("Playing Bingo.....\n");
    int bingoCard[5][5];
    int drawnNumbers[75] = {0}; // 0 means the number hasn't been drawn yet
    int rows[5] = {0}; // Count of filled cells in each row
    int cols[5] = {0}; // Count of filled cells in each column
    int diagonal1 = 0; // Count of filled cells in the primary diagonal
    int diagonal2 = 0; // Count of filled cells in the secondary diagonal
    int i, j, number;
    srand(time(NULL));

    // Initialize bingo card
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            bingoCard[i][j] = 0;
        }
    }

    // Fill bingo card with random numbers
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { // Center cell is always marked
                bingoCard[i][j] = -1; // Marked cell
                continue;
            }
            do {
                number = rand() % 15 + 1 + (15 * j); // Generate number within range for each column
            } while (drawnNumbers[number] != 0); // Ensure the number hasn't been drawn before
            bingoCard[i][j] = number;
            drawnNumbers[number] = 1; // Mark the number as drawn
        }
    }

    // Display bingo card
    printf("Here is your bingo card:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (bingoCard[i][j] == -1) {
                printf("  X "); // Marked cell
            } else {
                printf("%3d ", bingoCard[i][j]);
            }
        }
        printf("\n");
    }

    // Play bingo
    printf("\nLet's play bingo!\n");
    while (1) {
        do {
            number = rand() % 75 + 1; // Generate random number between 1 and 75
        } while (drawnNumbers[number] != 0); // Ensure the number hasn't been drawn before
        printf("The drawn number is: %d\n", number);
        drawnNumbers[number] = 1; // Mark the number as drawn

        // Check if the number matches any on the bingo card
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (bingoCard[i][j] == number) {
                    bingoCard[i][j] = -1; // Mark the matched cell
                    rows[i]++;
                    cols[j]++;
                    if (i == j) diagonal1++;
                    if (i + j == 4) diagonal2++;
                }
            }
        }

        // Check for bingo
        for (i = 0; i < 5; i++) {
            if (rows[i] == 5 || cols[i] == 5) {
                printf("BINGO! You win!\n");
                return;
            }
        }
        if (diagonal1 == 5 || diagonal2 == 5) {
            printf("BINGO! You win!\n");
            return;
        }
    }
}

void playWheelOfFortune() {
    printf("Playing  Wheel of Fortune.....\n");
    const char* prizes[] = {"$50", "$100", "$200", "$500", "$1000", "Bankrupt"};
    int numPrizes = sizeof(prizes) / sizeof(prizes[0]);
    srand(time(NULL));

    // Spin the wheel
    int spin = rand() % numPrizes;

    // Display the result
    printf("You spun the wheel and landed on: %s\n", prizes[spin]);

    if (spin == numPrizes - 1) {
        printf("Oh no! You landed on Bankrupt.\n");
    } else {
        printf("Congratulations! You won %s!\n", prizes[spin]);
    }
}
