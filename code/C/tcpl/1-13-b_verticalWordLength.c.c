#include <stdio.h>

#define MAX_LENGTH 100

int main() {
	int c, wl, i, x, y, ml,ml2, val;
	int wordA[MAX_LENGTH];
	int wordV[MAX_LENGTH];

	for (i = 0; i < MAX_LENGTH; ++i) {
		wordA[i] = 0;
		wordV[i] = 0;
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
	wordA[0] = 0;

	/* horizontal graph */
	val = 0;
	for (y = 0; y < MAX_LENGTH; ++y) {
		if (wordA[y] != 0) {
			wordV[val] = y;
			++val;
			printf("%d\t |", y);
			for (x = 0; x < wordA[y]; x++) {
				printf("-");
			}
		printf("\n");
		}
	}
	
	/* vertical graph */
	printf("\n");
	ml = 0;
	for (y = 0; y < MAX_LENGTH; ++y) {
		if (wordA[y] > ml) {
			ml = wordA[y];
		}
	}
	ml2 = ml;
	for (i = 0; i < ml2; i++) {

		for (y = 0; y < val; y++) {
			if (wordA[wordV[y]] >= ml) {
				printf(" | ");
			} else {
				printf("   ");
			}
		}
		--ml;
		printf("\n");
	}
	for (i = 0; i < val; ++i) {
		printf("---");
	}
	printf("\n");
	for (i = 0; i < val; ++i) {
		if (wordV[i] > 9) {
			printf(" %d", wordV[i]);
		} else {
			printf(" %d ", wordV[i]);
		}
	}
	printf("\n");
}
