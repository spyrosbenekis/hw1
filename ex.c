#include <stdio.h>

#define N 10 

int main()
{
    int st = 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N-i; j++)
            printf(" ");

        for(int j=0; i<st; j++)
            printf("*");

        for(int j=0; j<N-i; j++)
            printf(" ");

        st+=2;
        printf("\n");
    }
}