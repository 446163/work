#include <stdio.h>

int main(){

	float fahr, celcius;
	float fahr2, celcius2;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 2;

	fahr = lower;
	celcius2 = lower;

	printf(" fahrenheit | celcius \t celcius | fahrenheit \n");
	printf(" -----------|--------\t  --------|-----------\n");

	while(fahr <= upper) {
		celcius = (5.0/9.0) * (fahr-32.0);
		fahr2 = (celcius2 / (5.0/9.0)) + 32.0;
		printf("%11.0f | %5.1f \t| %8.0f | %5.1f \n", fahr, celcius, fahr2, celcius2);
		fahr = fahr + step;
		celcius2 = celcius2 + step;
	}
}



