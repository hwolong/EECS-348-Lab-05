#include <stdio.h>

int minimum(float array[]) {
	int min = array[0];
	int minIndex = 0;
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

void movingAverage(float array[]) {
	char months[][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};	
    float averageList[7] = {0};
    for (int i = 0; i <= 6; i++) {
        float avg = 0;
        for (int j = 0; j <= 5; j++) {
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
	printf("\n\nSales summary:\n");
	int min = minimum(sales);
	int max = maximum(sales);
	printf("Minimum sales: $%.2f (%s)\n", sales[min], months[min]);
	printf("Maximum sales: $%.2f (%s)\n", sales[max], months[max]);
	float avg = 0.0;
	for (int i = 0; i < 12; i++) {
		avg += sales[i];
	}
	avg /= 12;
	printf("Average sales: %.2f\n", avg);
	printf("\nSix-Month Moving Average Report:\n");
	movingAverage(sales);
	printf("\nSales Report (Highest to Lowest):\n");
	int maxList[12];
	float tempSales[12] = {0};
	for (int i = 0; i < 12; i++){
		tempSales[i] = sales[i];
	}
	for (int i = 0; i < 12; i++){
		int tempMax = maximum(tempSales);
		maxList[i] = tempMax;
		//printf("%d\n", tempMax);
		tempSales[tempMax] = 0.0;
		printf("%s: $%.2f\n", months[tempMax], sales[tempMax]);
		//printf("\n");
	}
	return 0;
}