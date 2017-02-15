// gcc -o localesupport -lX11 localesupport.c
#include <stdio.h>
#include <locale.h>
#include <X11/Xlib.h>

int main(int c, char **args) {
    printf("locale %s\n", setlocale(LC_CTYPE, "") ? "yup" : "nay");
    printf("Xorg %s\n", XSupportsLocale() ? "yup" : "nay");
}
