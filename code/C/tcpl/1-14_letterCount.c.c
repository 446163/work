#include <stdio.h>

#define MAX_LENGTH 36

int main() {
	int c, wl, i, x, y, ml, ml2, val;
	int wordA[MAX_LENGTH];
	int wordV[MAX_LENGTH];
	int wordN[MAX_LENGTH];

	for (i = 1; i < 36; ++i) {
		wordN[i] = 0;
	}

	wordA[1] = 'a';
	wordA[2] = 'b';
	wordA[3] = 'c';
	wordA[4] = 'd';
	wordA[5] = 'e';
	wordA[6] = 'f';
	wordA[7] = 'g';
	wordA[8] = 'h';
	wordA[9] = 'i';
	wordA[10] = 'j';
	wordA[11] = 'k';
	wordA[12] = 'l';
	wordA[13] = 'm';
	wordA[14] = 'n';
	wordA[15] = 'o';
	wordA[16] = 'p';
	wordA[17] = 'q';
	wordA[18] = 'r';
	wordA[19] = 's';
	wordA[20] = 't';
	wordA[21] = 'u';
	wordA[22] = 'v';
	wordA[23] = 'w';
	wordA[24] = 'x';
	wordA[25] = 'y';
	wordA[26] = 'z';
	
	while ((c = getchar()) != EOF) {
		for (i = 0; i < 36; ++i) {
			if (c == wordA[i]) {
				++wordN[i];
				printf("%d\t%d\n", i, wordN[i]);
			}
		}
	}

	/* horizontal graph */
	val = 0;
	for (y = 1; y < MAX_LENGTH; ++y) {
		if (wordN[y] != 0) {
			wordV[val] = y;
			++val;
			printf("%c\t |", wordA[y]);
			for (x = 0; x < wordN[y]; x++) {
				printf("-");
			}
		printf("\n");
		}
	}
	
	/* vertical graph */
	printf("\n");
	ml = 0;
	for (y = 0; y < MAX_LENGTH; ++y) {
		if (wordN[y] > ml) {
			ml = wordN[y];
		}
	}
	ml2 = ml;
	for (i = 0; i < ml2; i++) {

		for (y = 0; y < val; y++) {
			if (wordN[wordV[y]] >= ml) {
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
			printf(" %c", wordA[i]);
		} else {
			printf(" %c ", wordA[i]);
		}
	}
	printf("\n");
}
