/* CALENDAR OF ANY YEAR */

#include<stdio.h>
#include<stdlib.h>
char *string[]= {
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
int days_of_month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
void month_by_month( );
void selection();
void premonthdays(int);
int determineday(int);
int m=0,lastday,firstday,i=0,prevfirstday[12];
int year;
int main() {
    printf("Enter Year :  ");
    scanf("%d",&year);
    firstday=determineday(year);
    if(year%4!=0) {
        days_of_month[1]=28;
    }
    else days_of_month[1]=29;
    premonthdays(firstday);
    printf("\n\n\tYear - %d\n\n",year);
    month_by_month();
    selection();

    return 0;
}
void month_by_month() {
    int day,x;
    printf("\n\t %s\n",string[i]);
    day=firstday;
    int spacecount=4*(firstday-1);
    printf("\nS   M   T   W   T   F   S\n");
    for (int j = 1; j <= spacecount; j++)
    {
        printf(" ");
    }
    for(int n=1; n<=days_of_month[m]; n++)
    {
        x=n;
        x/=10;
        if(x==0)
            printf("%d   ",n);
        else
            printf("%d  ",n);
        if(day==7) {
            printf("\n");
            day=0;
        }

        day++;
        if(n==days_of_month[m])
            lastday=day;
    }
    printf("\n-----------------------\n");
    return;
}
int determineday(int year) {
    int day_one,jan,div,divcode,div1,div2,div3,div2code,div4,div5,div6;
    if(year%4==0)
        jan=5;
    else
        jan=6;
    div=year%400;
    divcode=0;
    div1=year-div;
    div2=div/100;
    div2=div2*100;
    div3=div%100;
    switch (div2)
    {
    case 100:
        div2code=5;
        break;
    case 200:
        div2code=3;
        break;

    case 300:
        div2code=1;
        break;

    case 400:
        div2code=0;
        break;

    default:
        div2code=0;
        break;
    }
    div4=div3/4;
    div5=div3-div4;
    div6=((div4*2)+div5)%7;
    day_one=1+jan+div6+div2code+divcode;
    day_one = day_one % 7+1;
    return day_one;
}
void premonthdays(int fd) {
    int day=0,months=0,ld;
    for (int j = 0; j < 12; j++)
    {
        if(j==0)
            day=fd;
        else {
            day=ld;
            fd=ld;
        }
        for(int n=1; n<=days_of_month[months]; n++)
        {
            if (day==7)
            {
                day=0;
            }
            day++;
            if(n==days_of_month[months]) {
                ld=day;
            }
        }
        months++;
        prevfirstday[j]=fd;
    }
}
void selection() {
    int choice;
    int n;
    char enter;
    while(1) {
        printf("\n\tSelection : ");
        printf("\n\n\t1.Next Month\n\t2.Previous Month\n\t3.Next Year\n\t4.Previous Year\n\t5.Display Whole Year\n\t6.Custom Month\n\t7.Custom Year\n\t8.Exit\n");
        printf("\tEnter Choice : ");
        scanf("%d",&choice);
        system("clear");
        switch (choice)
        {
        case 1:
            if(m==11) printf("No next-month\n");
            else {
                ++i;
                ++m;
                firstday=prevfirstday[i];
                printf("\n\n\tYear - %d\n\n",year);
                month_by_month();

            }
            break;
        case 2:
            if(m==0) printf("No prev-month\n");
            else {
                --i;
                --m;
                firstday=prevfirstday[i];
                printf("\n\n\tYear - %d\n\n",year);
                month_by_month();

            }
            break;
        case 3:
            year++;
            i=0,m=0;
            if(year%4!=0) {
                days_of_month[1]=28;
            }
            else days_of_month[1]=29;
            printf("\n\n\tYear - %d\n\n",year);
            firstday=determineday(year);
            premonthdays(firstday);
            month_by_month();
            break;
        case 4:
            i=0,m=0;
            year--;
            if(year%4!=0) {
                days_of_month[1]=28;
            }
            else days_of_month[1]=29;
            printf("\n\n\tYear - %d\n\n",year);
            firstday=determineday(year);
            premonthdays(firstday);
            month_by_month();
            break;
        case 5:
            i=0,m=0;
            system("clear");
            printf("--------------------------\n");
            printf("\n\n\tYear - %d\n\n",year);
            for(int j=0; j<12; j++) {
                firstday=prevfirstday[j];
                month_by_month();
                ++i;
                ++m;
            }
            i=0,m=0;
            firstday=determineday(year);
            scanf("%c",&enter);;
            enter=getc(stdin);
            system("clear");
            printf("\n\n    First Month of Year - %d\n",year);
            month_by_month();
            break;
        case 6:
            printf("Enter Month Number : ");
            scanf("%d",&n);
            i=n-1;
            m=n-1;
            firstday=prevfirstday[i];
            printf("\n\tYear - %d\n",year);
            month_by_month();
            break;
        case 7:
            i=0,m=0;
            main();
            break;

        case 8:
            exit(0);
            break;
        default:
            printf("Invalid Option");
            break;
        }
    }
}