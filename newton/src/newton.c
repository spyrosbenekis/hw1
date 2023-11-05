#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void newton(double xn);
double f(double xn);
double factor(double xn);

int count = 0;
double arr[6];

int main(int argc, char **argv) {
    
    if (argc != 8) {
        printf("Program needs to be called as `./nt a_0 a_1 a_2 a_3 a_4 a_5 x_0`\n");
        return 1;
    }

    for (int i = 1; i <= 6; i++)
        arr[i-1] = strtod(argv[i], NULL);

    double x_0 = strtod(argv[7], NULL);

    newton(x_0);

    return 0;
}

void newton(double xn)
{
    double xn1;
    double fac = factor(xn);

    if (fac == 0.0)
        printf("nan\n");
    else if (count > 1000)
        printf("incomplete\n");
    else{
        count++;
        xn1 = xn - f(xn) / fac;
        if (fabs(xn1 - xn) < 0.000001)
            printf("%.2f\n", xn1);
        else
            newton(xn1);
    }
}

double f(double xn)
{
    double num = 0;

    for (int i = 0; i < 6; i++) {
        num += arr[i] * pow(xn, i);
    }

    return num;
}

double factor(double xn)
{
    double h = 0.000001;
    double fac = (f(xn + h) - f(xn)) / h;
    
    if (fabs(fac) < 0.0001) {
        return 0.0;
    }
    else 
        return fac;
}
