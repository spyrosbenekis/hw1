#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool square(int64_t num);
bool psp(int64_t num);
bool pal(int64_t num);
bool first(int64_t num);

int main(int argc, char **argv) {
    
    if (argc != 3) {
        printf("Program needs to be called as `./mirror low high`\n");
        return 1;
    }

    int64_t st = atoll(argv[1]);
    int64_t fn = atoll(argv[2]);
    int64_t count = 0;

    if (st < 1 || st > fn || fn > 1000000000000LL) {
        printf("Wrong\n");
        return 1;
    }

    for (int64_t i = st; i <= fn; i++) {
        if (square(i) && psp(i) && pal(i)) {
            count += i;
        }
    }

    printf("%ld\n", count);

    return 0;
}

bool square(int64_t num) 
{
    int64_t sqr = sqrt(num);

    return sqr * sqr == num && first(sqr);
}

bool psp(int64_t num) 
{
    int64_t kat = 0;

    do {
        kat = (kat * 10) + (num % 10);
    } while (num /= 10);

    int64_t sqr = sqrt(kat);

    return sqr * sqr == kat && first(sqr);
}

bool pal(int64_t num) {
    int64_t kat = 0;
    int64_t n = num;

    do {
        kat = (kat * 10) + (num % 10);
    } while (num /= 10);

    return kat != n;
}

bool first(int64_t num) 
{ 
    double sqroot = sqrt(num); 
  
    for (int64_t i = 2; i <= sqroot; i++) { 
   
        if (num % i == 0) { 
            return false;
        } 
    }

    return true;
}