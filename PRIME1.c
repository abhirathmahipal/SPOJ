#include <stdio.h>

int main()
{

    int cases, start, finish;
    scanf("%d", &cases);
    int isPrime;

    for (int ccase = 0; ccase < cases; ccase++)
    {
        scanf("%d %d", &start, &finish);

        for (int i = start; i <= finish; i++) {

            isPrime = 1;
            for (int j = 2; j * j <= i; j++) {
                
                if (i % j == 0)
                {
                    isPrime = 0;
                    break;
                }
            }

            if(isPrime && i != 1) printf("%d\n", i);

        }
        
        printf("\n");
    }


    return 0;
}
