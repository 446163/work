#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t')
			putchar('\n');
		else 
			putchar(c);
		}
	}
