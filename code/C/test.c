#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
				int tmp = *a;
				*a = *b;
				*b = tmp;
}

int main () {
				int n = 44;
				printf("%d \n", n);
				printf("%d \n", &n);

				printf("%d \n", sizeof(int));
				int *num = malloc(sizeof(int));
				*num = 12;

				printf("%d\n%d/n", num, *num);

				free(num);

				int c = 5;
				int d = 4;

				swap(&c, &d);

				printf("c = %d\nd = %d", c, d);

				
				return 0;

}
