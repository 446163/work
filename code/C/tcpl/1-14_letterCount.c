#include <stdio.h>

#define MAX_LENGTH 36

int main() {
	int c, wl, i, x, y, ml,ml2, val;
	int wordA[MAX_LENGTH];
	int wordV[MAX_LENGTH];

	wordA[1] = ' ';
	wordA[2] = 'a';
	wordA[3] = 'b';
	wordA[4] = 'c';
	wordA[5] = 'd';
	wordA[6] = 'e';
	wordA[7] = 'f';
	wordA[8] = 'g';
	wordA[9] = 'h';
	wordA[10] = 'i';
	wordA[11] = 'j';
	wordA[12] = 'k';
	wordA[13] = 'l';
	wordA[14] = 'm';
	wordA[15] = 'n';
	wordA[16] = 'o';
	wordA[17] = 'p';
	wordA[18] = 'q';
	wordA[19] = 'r';
	wordA[20] = 's';
	wordA[21] = 't';
	wordA[22] = 'u';
	wordA[23] = 'v';
	wordA[24] = 'w';
	wordA[25] = 'x';
	wordA[26] = 'y';
	wordA[27] = 'z';

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
