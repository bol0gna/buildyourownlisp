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

void scanValues() {
	int i;
	float f;
	char s[256];

	printf("integer: ");
	scanf("%d", &i);
	printf("floating point value: ");
	scanf("%f", &f);
	printf("string 255 chars or less: ");
	scanf("%s", s);

	printf("integer was %d\nfloating point was %f\nstring was %s\n", i, f, s);
}

int main(int argc, char* argv[]) {
	printf("print this many stars: ");
	int stars;
	scanf("%d", &stars);
	printStars(stars);

	printf("convert fahrenheit to kelvin: ");
	double fahrenheit;
	scanf("%lf", &fahrenheit);
	printf("%.2lf\n", toKelvin(fahrenheit));

	scanValues();
}
