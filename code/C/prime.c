#include <stdio.h>
#include <math.h>

#define MAX_NUM 1000000

FILE *fp;

int arrlength;

int main(int argc, char **argv)
{

    fp = fopen("./prime.txt", "w+");
    fprintf(fp, "2\n3\n");
    int t = 5;
    int x, y;
    int a[1000000] = {3};

    //while(arrlength < MAX_NUM)
		while (1) 
    {
        y = 0;
        x = 1;

        while(x==1 && (a[y] <= sqrt(t)))
        {
            if((t % a[y]) == 0)
            {
                x = 0;
            }
            y += 1;
        }

        if(x)
        {
            arrlength += 1;
            a[arrlength] = t;
           fprintf(fp, "%i\n", t);
        }

        t += 2;
    }
    fclose(fp);
    return 0;
}

