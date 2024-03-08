#include <stdio.h>
#include <stdbool.h>

void printScore(int td2, int td1, int td, int fg, int safety) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d safety\n", td2, td1, td, fg, safety);
}

int main() {
    int safety = 2;
    int fg = 3;
    int td = 6;
    int td1 = 7;
    int td2 = 8;
    bool keepRunning = true;
    while (keepRunning == true) {
        int score;
        printf("Enter 0 or 1 to STOP.\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
            keepRunning = false;
        } else {
            int td2Count = 0;
            int td1Count = 0;
            int tdCount = 0;
            int fgCount = 0;
            int safetyCount = 0;
            while (((td2Count+1) * td2) <= score) {
                td2Count++;
            }
            if ((td2Count * td2) < score) {
                while (((td2Count * td2) + ((td1Count+1) * td1)) <= score) {
                    td1Count++;
                }
                if (((td2Count * td2) + (td1Count * td1)) < score) {
                    while (((td2Count * td2) + (td1Count * td1) + ((tdCount+1) * td)) <= score) {
                        tdCount ++;
                    }
                    if (((td2Count * td2) + (td1Count * td1) + (tdCount * td)) < score) {
                        while (((td2Count * td2) + (td1Count * td1) + (tdCount * td) + ((fgCount+1) * fg)) <= score) {
                            fgCount++;
                        }
                        if (((td2Count * td2) + (td1Count * td1) + (tdCount * td) + (fgCount * fg)) < score) {
                            while (((td2Count * td2) + (td1Count * td1) + (tdCount * td) + (fgCount * fg) + ((safetyCount+1) * safety)) <= score) {
                                safetyCount++;
                            }
                            if (((td2Count * td2) + (td1Count * td1) + (tdCount * td) + (fgCount * fg) + (safetyCount * safety)) == score) {
                                printScore(td2Count, td1Count, tdCount, fgCount, safetyCount);
                            }
                        } else {
                            printScore(td2Count, td1Count, tdCount, fgCount, safetyCount);
                        }
                    } else {
                        printScore(td2Count, td1Count, tdCount, fgCount, safetyCount);    
                    }
                } else {
                    printScore(td2Count, td1Count, tdCount, fgCount, safetyCount);
                }
            } else {
                printScore(td2Count, td1Count, tdCount, fgCount, safetyCount);
            }
        }
    }
    return 0;
}