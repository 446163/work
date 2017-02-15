#include <stdio.h>

int main() {
	int c, wl, i, x, y;
	int wordA[100];
	for (i = 0; i < 100; ++i) {
		wordA[i] = 0;
	}

	wl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
				++wordA[wl];
			wl = 0;
		} else {
			++wl;
		}
	}

	for (y = 1; y < 100; ++y){
		if( wordA[y] != 0){
			printf("%d\t |", y);
			for (x = 0; x < wordA[y]; x++){
				printf("-");
			}
		printf("\n");
		}
	}
}
