#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(int argc, char **argv)
{
    if(argc != 3){
        printf("The program needs to be called as ./flawless low high");
    }

    int64_t low = atol(argv[1]);
    int64_t high = atol(argv[2]);
    int64_t i, sum=0;

    if(low < 0 || high > 10000000000LL || low > high){
        return 1;
    }

    if(low<10)
        low=10;

    for (i = low; i <= high; i++) {
        printf("%ld\n",i);
        if(findWays(i, sqrt(i)) == 1){
            sum += i;
        }
    }

    printf("%ld\n", sum);

    return 0;
}