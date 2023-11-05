#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double xn,double arr[]);
double factor(double xn);
double pow(double base,int power)

int count=0;

int main(int argc, char **argv) {
    
    if (argc != 7) {
        printf("Program needs to be called as `./newton a_0 a_1 a_2 a_3 a_4 a_5 x_0`\n");
        return 1;
    }

    double arr[6];
    double xn

    for(int i=0;i<=6;i++){
        arr[i] = strtod(argv[i], NULL);
    }

    newton(arr[6]);

    return 0;
}

void newton(double xn)
{
    double xn1;
    double fac=factor(xn);

    if(fac==0){
        printf("nan");
    }
    else if(count>1000)
        printf("incomplete");
    else{
        count++;
        xn1=xn-f(xn)/fac;
        if(abs(xn1-xn)<0.000001)
            printf("%.2f\n",xn1);
        else
            return newton(xn1);
    }

}

double f(double xn,double arr[])
{
    double num=0;

    for(int i=0;i<6;i++){
        num+=arr[i]*xn;
    }

    return xn;
}

double factor(double xn)
{
    double h=1e-5;

    return (f(xn+h)-f(xn))/h;

}

double pow(double base,int power)
{
    int num=1;

    for(int i=0;i<power;i++){
        num=num*num;
    }

    return num;
}