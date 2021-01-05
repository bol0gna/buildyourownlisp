#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("enter a temperature in Fahrenheit: ");
	double degF;
	scanf("%lf", &degF);

	if (degF <= 32) {
		puts("That's freezing!");
	} else if (degF >= 212) {
		puts("That's boiling!");
	} else {
		puts("That's nice.");
	}

	double kelvin = (degF + 459.67) * (5.0 / 9.0);

	printf("%.2lf degrees F is %.2lf K\n", degF, kelvin);
}
