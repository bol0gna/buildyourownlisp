#include <stdio.h>

void printStars(int n) {
	for (int i = 0; i < n; i++) {
		printf("*");
	}
	printf("\n");
}

double toKelvin(double degF) {
	return (degF + 459.67) * (5.0 / 9.0);
}

int main(int argc, char* argv[]) {
	printf("print this many stars: ");
	int stars;
	scanf("%d", &stars);
	printStars(stars);

	printf("\nconvert fahrenheit to kelvin: ");
	double fahrenheit;
	scanf("%lf", &fahrenheit);
	printf("%.2lf", toKelvin(fahrenheit));
}
