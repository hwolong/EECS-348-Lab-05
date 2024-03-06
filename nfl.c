#include <stdio.h>
#include <stdbool.h>

int main() {
    bool keepRunning = true;
    while (keepRunning == true) {
        int score;
        printf("Enter 0 or 1 to STOP.\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            keepRunning = false;
        }
    }
    return 0;
}