#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int square(long long int num);
int psp(long long int num);
int pal(long long int num);
int first(long long int num);

int main(int argc, char **argv) {
    
    if (argc != 3) {
        printf("Program needs to be called as `./mirror low high`\n");
        return 1;
    }

    int64_t st = atoi(argv[1]);
    int64_t fn = atoi(argv[2]);
    int64_t count=0;

    if(st<1 || st>fn || fn>1000000000000LL){
        printf("Wrong\n");
        return 1;
    }

    for(int64_t i=st; i<=fn; i++){
        if((square(i)+psp(i)+pal(i))==3){
            count+=i;
        }
    }

    printf("%ld\n",count);

    return 0;
}

int square(long long int num)
{
    int64_t sqr;

    sqr = sqrt(num);

    if(sqr*sqr==num && first(sqr)==TRUE)
        return TRUE;
    else 
        return FALSE;
}

int psp(long long int num)
{
    int64_t kat=0;

    do{
        kat = (kat * 10) + (num % 10);
    }while(num/=10);

    int64_t sqr = sqrt(kat);

    if(sqr*sqr==kat && first(sqr)==TRUE)
        return TRUE;
    else 
        return FALSE;
}

int pal(long long int num)
{
    int64_t kat=0;
    int64_t n=num;

    do{
        kat = (kat * 10) + (num % 10);
    }while(num/=10);

    if(kat!=n)
        return TRUE;
    else 
        return FALSE;
}

int first(long long int num) 
{
    if (num <= 1) {
        return FALSE;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return FALSE;
        }
    }

    return TRUE;
}