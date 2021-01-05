#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("enter a temperature in Fahrenheit: ");
	double degF;
	scanf("%lf", &degF);

	double kelvin = (degF + 459.67) * (5.0 / 9.0);

	printf("%.2lf degrees F is %.2lf K\n", degF, kelvin);
}
