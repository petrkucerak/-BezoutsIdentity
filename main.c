#include <stdio.h>

#define REPS 1000

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

int main(int argc, char *argv[])
{   
    for(int i = 0; i < REPS; ++ i){
        if(is_prime_num(i) == 1){
            printf("%d\n", i);
        }
    }

    return 0;
}

/* =============

ToDo:
- je prvocislo
- rozklad cisla na prvocisla
- gcd a gca
- bezoutova identita

============= */