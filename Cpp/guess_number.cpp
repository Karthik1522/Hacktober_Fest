/*GUESSING RANDOM NUMBER GAME*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num , guess , nguesses = 1;
    srand(time(0));
    num = rand()%100+1;
    do{
    printf("Guess a number in between 1 and 100: \n");
    scanf("%d",&guess);
    
    if(guess>num)
    printf("Lower the number please!\n");
    
    
    else if(guess<num)
    printf("Higher the number please!\n");
    
    
    else
    printf("You guessed it in %d attempts",nguesses);
    
    nguesses++;
    
    }while (guess!=num);
    
    return 0;
}