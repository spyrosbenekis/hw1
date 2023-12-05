//Εκτεταμένη ανάλυση του κώδικα γίνεται στο README
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool prime(int64_t num) //Συνάρτηση που ελέγχει αν ο αριθμός είναι πρώτος
{     
    if(num == 1) //Αν είναι 1 τότε δεν είναι πρώτος
        return false;
    else if(num == 2) //Αν είναι 2 τότε είναι πρώτος
        return true;

    if(num%2==0) //Αν είναι άρτιος τότε δεν είναι πρώτος
        return false;

    double sqr = sqrt(num); 
    /*Αν δεν ισχύει κάποια από τις παραπάνω συνθήκες, τότε ελέγχει αν διαιρείται με κάποιον άλλον αριθμό
      και εφόσον δεν είναι ζυγός τότε αν γίνεται να διαιρεθεί, θα γίνει με κάποιον περιττό αριθμό*/
    for (int64_t i = 3; i <= sqr; i+=2) { 
        if (num % i == 0) 
            return false; //Αν διαιρεθεί με κάποιον τότε δεν είναι πρώτος
    }

    return true; /*Εφόσον δεν βρέθηκε αριθμός με τον οποίο να διαιρείται
                   τότε ο αριθμός είναι πρώτος*/
}

bool square(int64_t num) //Συνάρτηση που ελέγχει αν ο αριθμός είναι τέλειο τετράγωνο ενός πρώτου αριθμού
{
    int64_t sqr = sqrt(num);

    return sqr * sqr == num && prime(sqr);
}

int main(int argc, char **argv) {
    
    //Έλεγχος ορισμάτων
    if (argc != 3) {
        printf("Program needs to be called as `./mirror low high`\n");
        return 1;
    }

    int64_t st = atoll(argv[1]);
    int64_t fn = atoll(argv[2]);
    int64_t count = 0;

    //Έλεγχος εγυρότητας δεδομένων εισόδου
    if (st < 1 || st > fn || fn > 1e+15) {
        return 1;
    }


    for (int64_t i = sqrt(st); i <= sqrt(fn); i++) {
        
        int64_t kat = 0, num = i*i;

        //Υπολογισμός κατόπτρου
        do {
            kat = (kat * 10) + (num % 10);
        } while (num /= 10);

        num = i*i;

        //Έλεγχος των τριών συνθηκών ώστε να είναι ο αριθμός κατοπτρικό πρώτο τετράγωνο
        if (kat != num && square(kat) && prime(i))
            count += num;
    }

    printf("%ld\n", count); //Εκτύπωση αποτελέσματος

    return 0;
}