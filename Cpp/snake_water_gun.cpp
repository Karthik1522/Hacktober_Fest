/*
SNAKE WATER GUN GAME
*/

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main() {
int gen;
gen=rand()%3+0;
char you,comp,c;
system("clear");
printf("Enter S/W/G : \n");
scanf(" %c",&you);
char op[3]={'s','w','g'};
comp=op[gen];
system("clear");
sleep(1);
printf("You : %c\n",you);
printf("Computer : %c\n",comp);
if (you=='s')
{
    if(comp=='g')
    printf("Computer Wins\n");
    else if(comp=='w')
    printf("You Win\n");
    else
    printf("Tie\n");
}
if (you=='w')
{
    if(comp=='s')
    printf("Computer Wins\n");
    else if(comp=='g')
    printf("You Win\n");
    else
    printf("Tie\n");
}
 if (you=='g')
{
    if(comp=='w')
    printf("Computer Wins\n");
    else if(comp=='s')
    printf("You Win\n");
    else
    printf("Tie\n");
}
printf("Do You Want to Play Again(y/n) : \n");
scanf(" %c",&c);
if (c=='y')
{
    main();
    
}
else
exit(0);



return 0;
}