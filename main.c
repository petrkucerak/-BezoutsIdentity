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

int gcd(int numH, int numL)
{
    

    while(numA != 0){
        
    }

    return 0;
}

int find_optimal_q(int numH, int numL)
/** numH - number higher
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

int main(int argc, char *argv[])
{   
    /*for(int i = 0; i < REPS; ++ i){
        if(is_prime_num(i) == 1){
            printf("%d\n", i);
        }
    }*/

    int a = 358;
    int b = 374;

    int q = find_optimal_q(a,b);
    fprintf(stdout,"%d\n",q);


    return 0;
}

/* =============

ToDo:
- je prvocislo
- euklidovsky alogoritmus -> gcd - nejvetsi spolecny delitel
- rozklad cisla na prvocisla
- gcd a gca
- bezoutova identita

============= */
