#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int betNumber, winningNumber, balance = 1000, betAmount;
    char playAgain;

    srand(time(0)); // Seed for random number

    printf("Welcome to Roulette! You have $%d\n", balance);

    do {
        // Ask for bet amount
        printf("Enter your bet amount: ");
        scanf("%d", &betAmount);

        if (betAmount > balance) {
            printf("Insufficient balance!\n");
            continue;
        }

        // Ask for bet number
        printf("Enter a number between 0 and 36: ");
        scanf("%d", &betNumber);

        if (betNumber < 0 || betNumber > 36) {
            printf("Invalid number! Choose between 0 and 36.\n");
            continue;
        }

        // Spin the wheel
        winningNumber = rand() % 37;
        printf("The roulette wheel spins... \n And lands on %d!\n", winningNumber);

        // Check result
        if (betNumber == winningNumber) {
            printf("Congratulations! You won $%d!\n", betAmount * 35);
            balance += betAmount * 35;
        } else {
            printf("You lost $%d. Better luck next time!\n", betAmount);
            balance -= betAmount;
        }

        // Check if player has money left
        if (balance <= 0) {
            printf("You're out of money! Game over.\n");
            break;
        }

        // Ask if player wants to continue
        printf("Your current balance is $%d. Do you want to play again? (y/n): ", balance);
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing! Your final balance is $%d\n", balance);
    return 0;
}