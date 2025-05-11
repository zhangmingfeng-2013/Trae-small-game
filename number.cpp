#include <stdio.h>
#include <random>
using namespace std;

#define MAX_NUMBER 100
#define MIN_NUMBER 1
int main(){
    // Initialize game variables
    int guess;
    int remaining_attempts = 5;

    // Random number generation setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(MIN_NUMBER, MAX_NUMBER);
    int target_number = dist(gen);

    // Game loop
    while (remaining_attempts > 0) {
        printf("Attempts remaining: %d\nEnter your guess (%d-%d): ", remaining_attempts, MIN_NUMBER, MAX_NUMBER);
        scanf("%d", &guess);

        if (guess == target_number) {
            printf("Congratulations! You guessed correctly!\n");
            return 0;
        }
        
        printf("%s\n", (guess > target_number) ? "Too high!" : "Too low!");
        remaining_attempts--;
    }

    // Game over message
    printf("\nGame Over! The correct number was: %d\n", target_number);
    return 0;
}