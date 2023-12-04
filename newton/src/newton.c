#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;
double arr[6];

double f(double xn) //Υπολογισμός συνάρτησης στο σημείο
{
    double num = 0;

    for (int i = 0; i < 6; i++) {
        num += arr[i] * pow(xn, i);
    }

    return num;
}

double factor(double xn) //Υπολογισμός παραγώγου στο σημείο
{
    double fac=arr[1];

    for(int i=2;i<6;i++){
        fac+=arr[i]*i*pow(xn,i-1); 
    }

    if (fabs(fac) < 0.0001) //Έλεγχος αν η παράγωγος συγκλίνει στο μηδέν
        return 0.0;
    else 
        return fac;
}

void newton(double xn) //Αναδρομή
{
    double xn1;
    double fac = factor(xn);

    if (fac == 0.0) //Έλεγχος αν ο αλγόριθμος αποκλίνει (διαίρεση με 0)
        printf("nan\n");
    else if (count > 1000) //Έλεγχος αν έχουν γίνει περισσότερες από 1000 επαναλήψεις
        printf("incomplete\n");
    else{
        count++;
        xn1 = xn - f(xn) / fac;
        if (fabs(xn1 - xn) < 0.000001) //Έλεγχος αν ο αλγόριθμος συγκλίνει και ισχύει  |xn+1 − xn| < 10^−6
            printf("%.2f\n", xn1); //Εκτύπωση του αποτελέσματος 
        else
            newton(xn1); // Αφού δεν έχει βρεθεί ξανά καλεί την συνάρτηση
    }
}

int main(int argc, char **argv) {
    
    //Έλεγχος ορισμάτων
    if (argc != 8) {
        printf("Program needs to be called as `./newton a_0 a_1 a_2 a_3 a_4 a_5 x_0`\n");
        return 1;
    }

    //Αποθήκευση δεδομένων εισόδου
    for (int i = 1; i <= 6; i++)
        arr[i-1] = strtod(argv[i], NULL);

    double x_0 = strtod(argv[7], NULL);

    newton(x_0); //Κλήση αναδρομής

    return 0;
}