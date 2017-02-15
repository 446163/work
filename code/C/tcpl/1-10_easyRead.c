#include <stdio.h>

int main() {
	int c, blank, tab, newline;

	blank = tab = newline = 0;

	while ((c = getchar()) != EOF){
		if (c == '\t'){
			printf("\\t");
		}else{
		if (c == '\b'){
			printf("\\b");
		}else{
		if (c == "\\"){
			printf("\\");
		}else{
		putchar(c);
		}
		}
		}
	}
}
