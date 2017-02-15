#include <stdio.h>

int main(){
	int c;

	while (1){
		c = (getchar() != EOF);
		printf("%d\n", c);
	}
}
