#include <stdio.h>

main ()
{
				float number = 1;
				int count = 1;
				while (1) {
								count = count + 1;
//								printf("----%d\n", count);
								number = number + (1.0/count);
								if (count%1000000==0) {
												printf("%.50f\n", number);
								}
				}
}
