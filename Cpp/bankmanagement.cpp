#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<string.h>
struct pass {
    char username[50];
    int date, month, year;
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[80];
    char typeaccount[20];
    char password[30];
};
struct login
{
    char username[30];
    char password[30];
};


int upi,bankbalance=0;
char client[20];
void CreateAccount();
void displaycard(char []);
void carddetails(char []);
void TransactionHistory(char []);
void moneytransfer(char []);
void SetUPI(char []);
void viewbalance();
void SignIn();
void Homepage(char[]);
int customerinfo(char[]);
void deposit(char []);
void reciept(char [],char [], int);
int main() {
printf("\t   WELCOME TO BANK MANAGEMENT\n");
printf("\n\t********************************\n");
printf("\n\n\t1.CREATE A BANK ACCOUNT\n");
printf("\n\n\t2.ALREADY A USER? SIGN-IN\n");
printf("\n\n\t3.EXIT\n");
int choice;
printf("\n\n\t Enter Your Choice : ");
scanf("%d",&choice);
switch (choice)
{
case 1:
    CreateAccount();
    break;
case 2:
    SignIn();
    break;

case 3:
    exit(0);    

default:
printf("\n\t\t Invalid-Choice\n");
    break;
}

return 0;
}
void CreateAccount(){
    FILE *ptr,*p;
    struct pass u1;
    char temp[20],c1;
    ptr=fopen("Customer.txt","a+");
    p=fopen("CustomerExtra.txt","a+");
    system("clear");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
 
    printf("\n\nFIRST NAME :");
    scanf("%s", u1.fname);
 
    printf("\n\n\nLAST NAME :");
    scanf("%s", u1.lname);
 
    printf("\n\nFATHER's NAME :");
    scanf("%s", u1.fathname);
 
    printf("\n\nMOTHER's NAME :");
    scanf("%s", u1.mothname);
 
    printf("\n\nADDRESS :");
    scanf("%s", u1.address);
 
    printf("\n\nACCOUNT TYPE :");
    scanf("%s", u1.typeaccount);
 
    printf("\n\nDATE OF BIRTH :");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);
 
    printf("\n\nADHAR NUMBER :");
    scanf("%s", u1.adharnum);
 
    printf("\n\nPHONE NUMBER :");
    scanf("%s", u1.pnumber);
 
    printf("\n\nUSERNAME :");
    scanf("%s", u1.username);
    fclose(ptr);
    ptr=fopen("Customer.txt","r");		
    while((fscanf(ptr,"%s",temp))!=EOF){
    
    if(strcmp(u1.username,temp)==0)
    {
        system("clear");
    printf("*Username is Already in Use.\n");
    printf("*Please Try-Again\n\n");
    printf("\n\nUSERNAME :");
    scanf("%s", u1.username);
    }
    
    }
    fclose(ptr);
    ptr=fopen("Customer.txt","a+");
    printf("\n\nPlease include numbers and Special characters(*,&,~,%%,$,#,@,!)");
    printf("\n\nPASSWORD :");
    scanf("%s", u1.password);
    SetUPI(u1.username);
    carddetails(u1.username);
    fprintf(p,"\n%s\n%s\n%s\n%s\n%s\n%d-%d-%d\n%s\n%s\n",u1.username,u1.fathname,u1.mothname,u1.adharnum,u1.pnumber,u1.date,u1.month,u1.year,u1.address,u1.typeaccount);
    fprintf(p,"stop");
    fprintf(ptr,"\n");
    fprintf(ptr,"%s\t\t%s",u1.username,u1.password);
    fclose(ptr);
    fclose(p);
    SignIn();
    return;
}
void SignIn(){
    struct login s;
    char c;
    int flag=0;
    char checkusername[20],checkpassword[20];
    FILE *ptr;
    ptr=fopen("Customer.txt","r");
    fseek(ptr,20,SEEK_SET);
    system("clear");
    printf("\t\t\t\tACCOUNT LOGIN\n");
    printf("\t\t*****************************************************\n\n");
    printf("\n\t\t\t===SIGN-IN===\n\n");
    printf("Enter Your Username : \n");
    scanf("%s",s.username);
    printf("Enter Password : \n");
    scanf("%s",s.password);
    while ((fscanf(ptr,"%s %s",checkusername,checkpassword))!=EOF)
    {
        // printf("%s %s",checkusername,checkpassword);
        //check again for fseek if not working.
        if (strcmp(s.username,checkusername)==0 && strcmp(s.password,checkpassword)==0)
        {
            printf("\nLogin Successfull.\n");
            sleep(1);
            printf("Redirecting to Home Page.........\n");
            sleep(2);
            // carddetails(s.username);
            flag=1;
            
            break;
            
        }  
    }
    if (flag!=1)
    {
        printf("\nUsername or Password is Incorrect\n");
        printf("Try-Again\n");
        scanf("%c",&c);
        c=getc(stdin);
        system("clear");
        main();
    }
    else{
        scanf("%c",&c);
        c=getc(stdin);
    Homepage(s.username);
    }
}
void Homepage(char username[20]){
    system("clear");
    int pos;
    char data[8][70],temp[70];
    int i=0,choice;
    FILE *p;
    p=fopen("CustomerExtra.txt","r");
    pos=customerinfo(username);
    pos-=strlen(username);
    fseek(p,pos,SEEK_SET);
    // fgets(temp,70,p);
    // printf("%s",temp);
    //remove next line after stop
    while ((fgets(temp,70,p))!=NULL)
    {
        strcpy(data[i],temp);
        ++i;
        if(i==8)
        break;
    }
    FILE *bh;
    bh=fopen("Transactionhistory.txt","w");
    
    while(1){
    system("clear");
    printf("\t\t\t\tWELCOME,%s \n\n\n",data[0]);
    printf("HOME \t\t\t\t\t\t===YOUR ACCOUNT INFO===\n");
    printf("*****\t\t\t\t\t\t**************************\n");
    printf("1.Deposit\t\t\t\t\tNAME: %s\n",data[0]);
    printf("2.View Balance\t\t\t\t\tFATHER'S NAME:%s\n",data[1]);
    printf("3.Money Transfer\t\t\t\tMOTHER'S NAME:%s\n",data[2]);
    printf("4.Transaction History\t\t\t\tAADHAR CARD NUMBER:%s\n",data[3]);
    printf("5.Card Details\t\t\t\t\tMOBILE NUMBER:%s\n",data[4]);
    printf("6.Log Out\t\t\t\t\tDATE OF BIRTH:%s\n",data[5]);
    printf("7.Exit\t\t\t\t\t\tADDRESS:%s\n",data[6]);
    printf("\t\t\t\t\t\tACCOUNT TYPE:%s\n",data[7]);
    printf("\nEnter Choice : ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
    deposit(username);
        break;
    case 2:
    viewbalance();
        break;
    case 3:
    moneytransfer(username);
    break;    

    case 4:
    TransactionHistory(username);
    break;
    
    case 5:
    displaycard(username);
    break;

    case 6:
    bankbalance=0;
    system("clear");
    main();
    break;
    case 7:
    exit(0);
    default:
        break;
    }
    
    }
    fclose(p);
    fclose(bh);
}
int customerinfo(char username1[20]){
    char temp[20];
    int pos=0;
    FILE *p;
    // printf("%s",username1);
    p=fopen("CustomerExtra.txt","r");
    while((fscanf(p,"%s",temp))!=EOF)
    {
        if(strcmp(temp,username1)==0){
        pos=ftell(p);
        break;
        }
    }
    fclose(p);
    return pos;
}
void SetUPI(char username[20]){
    system("clear");
    printf("\t\t\t===SET UPI===\n");
    printf("Please Set a UPI for Security purposes.\n");
    FILE *ptr;
    ptr=fopen("UPI.txt","a+");
    printf("Enter Your UPI passcode : ");
    scanf("%d",&upi);
    fprintf(ptr,"\n");
    fprintf(ptr,"%s\n%d\n",username,upi);
    fprintf(ptr,"stop");
    fclose(ptr);
}
void deposit(char username[20]){
    FILE *bh;
    bh=fopen("Transactionhistory.txt","a+");
    system("clear");
    printf("\t\t\t===DEPOSIT===\n");
    int deposit;
    printf("Enter Amount To Deposit : ");
    scanf("%d",&deposit);
    bankbalance+=deposit;
    fprintf(bh,"%s\t\t\t\tBANK\t\t\t\t%d\t\t\t\t%d\n",username,deposit,bankbalance);
    fclose(bh);
}
void viewbalance(){
    char c;
    system("clear");
    printf("\t\t\t===BANK BALANCE===\n");
    printf("Your Bank-Balance is :  %d\n",bankbalance);
    scanf("%c",&c);
    c=getc(stdin);
}
void moneytransfer(char username[20]){
    char c,rec,enter;
    FILE *bh;
    bh=fopen("Transactionhistory.txt","a+");
    FILE *p;
    p=fopen("UPI.txt","r");
    char temp[20];
    int amount;
    int upi,pos=0,checkupi;
    system("clear");
    printf("\t\t\t===MONEY TRANSFER===\n");
    printf("Money-Transfer to :  ");
    scanf("%s",client);
    printf("Amount :  ");
    scanf("%d",&amount);
    if(amount>bankbalance){
    printf("\nInsufficient Funds\n");
    scanf("%c",&c);
    c=getc(stdin);
    return;
    }
    printf("Please, Enter Your UPI PIN :  \n");
    scanf("%d",&checkupi);
    while((fscanf(p,"%s",temp))!=EOF)
    {
        if(strcmp(temp,username)==0){
        pos=ftell(p);
        break;
        }
    }
    fscanf(p,"%d",&upi);
    // printf("%d\n",upi);
    if(upi==checkupi){
    printf("\nSuccessfully Transfered.....\n");
    bankbalance-=amount;
    //writing down transactions
        if(strlen(client)<=7)
        fprintf(bh,"%s\t\t\t\t%s\t\t\t\t%d\t\t\t\t%d\n",username,client,amount,bankbalance);
        else
        fprintf(bh,"%s\t\t\t\t%s\t\t\t%d\t\t\t\t\t%d\n",username,client,amount,bankbalance);
    
    }
    else{
    printf("\nWrong UPI-PIN Entered\n");
    printf("Try-Again\n");
    scanf("%c",&c);
    c=getc(stdin);
    moneytransfer(username);
    }

    printf("Do You Want a Reciept : ");
    scanf(" %c",&rec);
    if(rec=='y'){
        printf("\nProcessing.....\n");
        sleep(1);
        printf("Printing Reciept.....\n");
        sleep(1);
    reciept(username,client,amount);
    goto next;
    }
    else if(rec=='n'){
    printf("\nRedirecting To Home Page....\n");
    }

    next:
    scanf("%c",&enter);
    enter=getc(stdin);
    
    fclose(p);
    fclose(bh);
}
void TransactionHistory(char username[20]){
    system("clear");
    FILE *bh;
    char c;
    bh=fopen("Transactionhistory.txt","r");
    char temp[20];
    int i=1;
    printf("\t\t\t\t===TRANSACTION HISTORY===\n\n");
    printf("\t\t**********************************************\n\n");
    printf("S.No\t\tFROM\t\tTO\t\tAMOUNT\t\tBALANCE\n");
    while((fscanf(bh,"%s",temp))!=EOF)
    {
        printf("%d\t\t",i);
        printf("%s\t\t",temp);
        fscanf(bh,"%s",temp);
        if(strlen(temp)<=7){
        printf("%s\t\t",temp);
        fscanf(bh,"%s",temp);
        printf("%s\t\t",temp);
        fscanf(bh,"%s",temp);
        printf("%s\t\t",temp);
        printf("\n");
        }
        else{
            printf("%s\t",temp);
        fscanf(bh,"%s",temp);
        printf("%s\t\t",temp);
        fscanf(bh,"%s",temp);
        printf("%s\t\t",temp);
        printf("\n");
        }

        i++;
    }
    scanf("%c",&c);
    c=getc(stdin);
}
void carddetails(char username[20]){
char number[10]={'0','1','2','3','4','5','6','7','8','9'};
srand(time(0));
FILE *cd;
cd=fopen("CardDetails.txt","a+");
char cardnumber[20],x,i = 0,cnt=1;
int emnth,eyr;
int cvv;
x=rand()%9+0;
for (; i < 20; i++)
{
    if(cnt==5)
    {
        cardnumber[i]='-';
        cnt=1;
        continue;
    }
    cardnumber[i]=number[x];
    x=rand()%9+0;
    cnt++;
}
cardnumber[i-1]='\0';
emnth=rand()%12+1;
eyr=rand()%21+2022;
cvv=rand()%1000+1;
fprintf(cd,"%s\n%s\n%d/%d\n%d\n",username,cardnumber,emnth,eyr,cvv);
fprintf(cd,"stop\n");
fclose(cd);
}
void displaycard(char username[20]){
    char c;
system("clear");
char card[3][20];
int pos;
FILE *cd;
cd=fopen("CardDetails.txt","r");
char temp[20];
int i=0;
while((fscanf(cd,"%s",temp))!=EOF)
    {
        if(strcmp(temp,username)==0){
        pos=ftell(cd);
        break;
        }
    }
    fseek(cd,pos,SEEK_SET);
    while ((fscanf(cd,"%s",temp))!=EOF)
    {
        strcpy(card[i],temp);
        ++i;
        if(i==3)
        break;
    }
    
    
    printf("\t\t*** Please Don't Share Your Card Details with Anyone ***\n\n");
    printf("Username    : %s\n",username);
    printf("Card-Number : %s\n",card[0]);
    printf("Expiry Date : %s\n",card[1]);
    printf("CVV         : %s\n",card[2]);
    scanf("%c",&c);
    c=getc(stdin);
}
void reciept(char username[20],char cleint[20],int amount){
    system("clear");
    char c;
    time_t t;
    time(&t);
    printf("\t\t ***BANK RECIEPT*** \n\n");
    printf("From : %s,\t\t   Date & Day : %s\n",username,ctime(&t));
    printf("===============================================================\n");
    printf("To: \t\tAmount : \n");
    printf("%s \t\t\t%d\n",client,amount);
}