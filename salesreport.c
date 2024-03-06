#include <stdio.h>

int main() {
	int sales[12];
	char months[][9] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	for (int i=0; i<12; i++) {
		scanf("%d\n", &sales[i]);
	}

	printf("Monthly sales report for 2022:\n");
	printf("January\t%d", sales[0])
}