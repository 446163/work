#include <stdio.h>

int main() {
	int c, blank, tab, newline;

	blank = tab = newline = 0;

	while ((c = getchar()) != EOF){
		if (c == ' '){
		putchar(c);
			while ((c = getchar()) == ' '){
				;
			}
		}
		putchar(c);
	}
}
