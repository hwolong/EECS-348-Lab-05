#include <stdio.h>

int minimum(float array[]) {
	int min;
	int minIndex;
	for (int i = 0; i < 12; i++) {
		if (array[i] < min) {
			min = array[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int maximum(float array[]) {
	int max;
	int maxIndex;
	for (int i = 0; i < 12; i++) {
		if (array[i] > max) {
			max = array[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

float movingAverage(float array[]) {
	char months[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};	
    float averageList[7] = {0};
    for (int i = 0; i <= 6; i++) {
        float avg = 0;
        for (int j = 0; i <= 5; i++) {
            avg += array[j+i];
        }
        avg /= 6;
        averageList[i] = avg;
    }
    
    for (int i = 0; i <= 6; i++) {
		printf("%s - %s: $%.2f\n", months[i], months[i+5], averageList[i]);
	}
}

int main() {
	float sales[12] = {0};
	char months[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	for (int i=0; i<12; i++) {
		scanf("%f", &sales[i]);
	}

	printf("Monthly sales report for 2022:\n\n");
	for (int i = 0; i < 12; i++) {
		printf("%s: $%.2f\n", months[i], sales[i]);
	}
	int min = minimum(sales);
	int max = maximum(sales);
	printf("Minimum sales: $%.2f (%s)\n", sales[min], months[min]);
	printf("Maximum sales: $%.2f (%s)\n", sales[max], months[max]);
	float avg = 0.0;
	for (int i = 0; i < 12; i++) {
		avg += sales[i];
	}
	avg /= 12;
	printf("Average sales: %f\n", avg);
	printf("Six-Month Moving Average Report:\n");
	movingAverage(sales);
}