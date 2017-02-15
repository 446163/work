#include <stdio.h>
#include <math.h>

int main () {
	int testingNumber = 3;
	double sqrtTestingNumber;
	int countUp;
	int flag;
	long counter = 2;
	double test;
	int notUsed;
	while (1 && counter < 1000){
		testingNumber = testingNumber + 2;
		countUp = 1;
		flag = 1;
		sqrtTestingNumber = sqrt(testingNumber);
		while (countUp <= sqrt(sqrtTestingNumber)+1) {
			countUp = countUp + 2;
			test = testingNumber % countUp;
			if (test == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			counter = counter + 1;
			printf("%ld:\t%d\n", counter, testingNumber);
			if (counter % 10000 == 0) {
				printf("%ld:\t%d\n", counter, testingNumber);
			}
		}
	}
}
