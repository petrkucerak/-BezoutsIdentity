#include <stdio.h>

#define REPS 100

int is_prime_num(int number)
{
    // osetrime minimum
    if(number < 2) return 0;
    if(number == 2) return 1;
    if(number % 2 == 0) return 0; 

    for(int i = 3; i < number; ++i){
        
        if(number % i == 0){
            return 0;
        }
    }

    return 1;
}

int find_optimal_q(int numH, int numL)
/**
 * numH - number higher
 * numL - number lower
 * metoda hleda nejblizsiho nasobitele v N
 **/
{
    int q = 1;

    while((numH / ( (q+1) * numL)) != 0){
        ++ q;
    }

    return q;
}

int find_gcd(int numH, int numL)
/**
 * vraci gcd pro kladna cisla
 * treba drzet poradi zadavani
 * tj. numH - vyssi cislo
 * numL nizsi cislo
 **/
{
    int q;
    int numL_new;

    while(numL != 0){
        q = find_optimal_q(numH, numL);
        //fprintf(stdout,"q = %d; numH = %d; numL = %d\n", q, numH, numL);
        numL_new = numH - (q * numL);
        numH = numL;
        numL = numL_new;
    }

    return numH;
}

void the_bezout_identity(int numH, int numL)
{

    int a = numH;
    int b = numL;

    int q;
    int value_help;
    
    int x_H = 1;
    int x_L = 0;

    int y_H = 0;
    int y_L = 1;

    fprintf(stdout,"EUKLIDUV ALGORITMUS\n");

    fprintf(stdout,"|%10d | %10d | %10d |\n", numH, x_H, y_H);
    fprintf(stdout,"|%10d | %10d | %10d |\n", numL, x_L, y_L);
    fprintf(stdout,"=======================================\n");

    while(numL != 0){
        q = find_optimal_q(numH, numL);
        value_help = numH - (q * numL);
        numH = numL;
        numL = value_help;

        value_help = x_H - (x_L * q);
        x_H = x_L;
        x_L = value_help;

        value_help = y_H - (y_L * q);
        y_H = y_L;
        y_L = value_help;

        //fprintf(stdout,"%d | %d | %d\n", numH, x_H, y_H);
        fprintf(stdout,"|%10d | %10d | %10d |\n", numL, x_L, y_L);
    }

    int gcd = numH;

    fprintf(stdout,"\ngcd(%d,%d) = %d\n\n", a, b, gcd);
    fprintf(stdout,"Bezoutova identita:\n");
    fprintf(stdout,"%d * (%d) + %d * (%d) = %d\n", a, x_H, b, y_H, gcd);
}

int main(int argc, char *argv[])
{   
    int a, b;

    if(scanf("%d%d", &a, &b) != 2){
        fprintf(stderr,"Error: Spatne zadane hodnoty!\n");
        return 100;
    }
    if(a < 0 || b < 0){
        fprintf(stderr,"Error: Cisla nesmeji byti zaporna!\n");
        return 101;
    }
    if(a < b){
        fprintf(stderr,"Error: Prvni hodnota musi byt mensi nez druha!\n");
        return 102;
    }

    the_bezout_identity(a, b);

    return 0;
}

/* =============

ToDo:
- doselchtit code!!!

============= */

ToDo:
- je prvocislo
- euklidovsky alogoritmus -> gcd - nejvetsi spolecny delitel
- rozklad cisla na prvocisla
- gcd a gca
- bezoutova identita
- doselchtit code!!!

============= */
