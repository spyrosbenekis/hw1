#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool square(int64_t num);
bool first(int64_t num);

int main(int argc, char **argv) {
    
    if (argc != 3) {
        printf("Program needs to be called as `./mirror low high`\n");
        return 1;
    }

    int64_t st = atoll(argv[1]);
    int64_t fn = atoll(argv[2]);
    int64_t count = 0;

    if (st < 1 || st > fn || fn > 1000000000000000) {
        printf("Wrong\n");
        return 1;
    }

    for (int64_t i = sqrt(st); i <= sqrt(fn); i++) {
        
        int64_t kat = 0, num = i*i;

        do {
            kat = (kat * 10) + (num % 10);
        } while (num /= 10);

        num = i*i;

        if (square(num) && square(kat) && kat != num)
            count += num;
    }

    printf("%ld\n", count);

    return 0;
}

bool square(int64_t num) 
{
    int64_t sqr = sqrt(num);

    return sqr * sqr == num && first(sqr);
}

bool first(int64_t num) 
{ 
    double sqr = sqrt(num); 
    
    if(num%2==0)
        return false;

    for (int64_t i = 3; i <= sqr; i+=2) { 
   
        if (num % i == 0) { 
            return false;
        } 
    }

    return true;
}