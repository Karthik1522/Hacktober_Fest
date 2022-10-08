/* HOSPITAL MANAGEMENT 

A Small Project */

#include <stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<unistd.h>
void database();
float randfees();
void serious(int);
char id[30],pass[30],id1[30],pass1[30];
int main()
{
int weight,totalfee,notserious_bill;
int bodytemp,advance;
int bp;
char pid,ch1;
char symp[50];
int doctor,number,bed;

printf("\t***** ANURAG HOSPITALS *****\n");
printf("Hello! I am Anuragian and I am here to to Guide you.\n");
printf("Do you have a Patient's ID (y/n) :");
scanf(" %c",&pid);
printf("-----------------------------------------------\n");
//Login
if(pid=='y')
{
    printf("\n\tLOG-IN\n");
printf("\n Enter Your Patient's ID : \n");
scanf("%s",id);
printf("Password : \n");
scanf("%s",pass);

}
//SIGN-UP
else if(pid=='n')
{
    printf("\n\tSIGN-UP\n");
printf("\n Enter Your Patient's ID : \n");
scanf("%s",id);
printf("Password : \n");
scanf("%s",pass);
printf("\nSuccessfull Signed-up\n");
printf("-----------------------------\n");
printf("\nThank You\n");
sleep(2);
printf("\nEntering into Database ...");

printf("\nEnter any key.");
database();
}
//weight,bodytemp,bp
printf("\nWelcome %s , Please Enter the Following \n",id);
printf("Enter Your Weight :");
scanf("%d",&weight);
printf("Enter Your Body-Temperature (In Fahrenheit) :");
scanf("%d",&bodytemp);
printf("Enter Your Blood-Pressure :");
scanf("%d",&bp);
printf("\nThank You\n");
printf("----------------------------\n");
scanf("%c",&ch1);
getchar();
system("clear");

srand(time(0));
number=rand()%5 +1;//Generates  a random number in between 1 to 5.
//Doctor allocatement from 1 to 5.
switch (number)
{
case 1:
    printf("Doctor Allocatment : \n");
    sleep(1);
    printf("Name : Dr.Ashsih Sabharwal \n");
    sleep(1);
    printf("Surgeon Type : General Surgeon \n");
    sleep(1);
    printf("17 Year of experience and MBBS,M.S.(General Surgery),DNB \n");
    sleep(1);
    break;

case 2:
printf("Doctor Allocatment : \n");
sleep(1);
    printf("Name : Dr.Sanjay Sachdeva \n");
    sleep(1);
    printf("Surgeon Type : Otolaryngologist\n");
    sleep(1);
    printf("14 Year of experience and MBBS,DCH,MS \n");
    sleep(1);
    break;

case 3:
 printf("Doctor Allocatment : \n");
 sleep(1);
    printf("Name : Dr.Aditya Gupta \n");
    sleep(1);
    printf("Surgeon Type : Neurosurgeon \n");
    sleep(1);
    printf("20 Year of experience and MBBS,M.S.(Surgery). \n");
    sleep(1);
    break;

case 4:
 printf("Doctor Allocatment : \n");
 sleep(1);
    printf("Name : Dr.SKS Marya \n");
    sleep(1);
    printf("Surgeon Type : Orthopaedic Surgeon \n");
    sleep(1);
    printf("17 Year of experience and M.B.B.S ,M.S.,DNB , FICS\n");
    sleep(1);
    break;

case 5:
printf("Doctor Allocatment : \n");
sleep(1);
    printf("Name : Dr.Surbhi Anand \n");
    sleep(1);
    printf("Surgeon Type : Senior Consultant and Dentist \n");
    sleep(1);
    printf("17 Year of experience and B.D.S and M.D.S\n");
    sleep(1);
    break;
}
//serious condition
 if (bodytemp>100 || bp > 180)
{
    int tests;
    printf("\n\n");
    printf("Condition : SERIOUS \n");
    srand(time(0));
    bed=rand()%20+1;
    printf("Bed Room Number : %d\n",bed);
    tests=rand()%5+2;
    printf("Tests : %d",tests);
    totalfee=randfees();
    serious(totalfee);

    printf("\n----- THANK YOU -----\n");
       
}

else
{

    printf("\nCondition : NOT SERIOUS \n");
    srand(time(0));
    notserious_bill=rand()%25000 + 1000;
    printf("Total Bill : %d\n",notserious_bill);
    printf("----- THANK YOU ----- \n");
}

//last 
sleep(2);
printf("\n Your Health is our Concern ...\n");
 printf(" ****** ANURAG HOSPITALS ***** \n");
 
    return 0;
}



//database user-defined function
void database()
{
    char ch,ch1;
    scanf("%c",&ch);
getchar();
system("clear");
printf("\nPlease enter your Login Details \n");
printf("\n Enter Your Patient's ID : \n");
scanf("%s",id1);
printf("Password : \n");
scanf("%s",pass1);
//Compare 2 strings
if(strcmp(id,id1)==0 && strcmp(pass,pass1)==0)
{
printf("Succesfully Logged-in\n");
printf("\n Enter any key .");
scanf("%c",&ch1);
getchar();
system("clear");
}
else
{
    printf("Wrong ID (or) pass , please try-again\n");
    database();
}

}
//generate random bill
float randfees()
{
    int fees;
   srand(time(0));
   fees=rand()%200000+10000;
 
 return fees;
}
//serious condition
void serious(int totalfee)
{
    int advance;
    if (totalfee>100000)
    {
        printf("\n\n");
        printf("Total Fees : %d\n",totalfee);
        printf("Advance Fees : \n");
    scanf("%d",&advance);
    printf("Remaining Balance : %d\n",totalfee-advance);
    
    }
    else{
       totalfee=randfees();
       serious(totalfee);
    }
}