#include <stdio.h>

int main(){
	int c;

	while (1){
		c = (getchar() != EOF);
		putchar(c);
		printf("%1d", c);
	}
}
