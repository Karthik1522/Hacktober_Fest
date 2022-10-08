/* TIC-TAC-TOE GAME */

#include<stdio.h>
#include<stdlib.h>
char mat[3][3];
char sym[2];
void printmatrix();
void checkrow();
void checkcol();
void checkdiagonal();
void player1();
void player2();
int fail=1;
int main() {
char symbol;
int player[2]={1,2};
int k=0;
int row,col;
int colcount=0;
int fail=1;
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        mat[i][j]='_';
    }
}

printf("Welcome to Tic-Tac-Toe Game.\n");
printf("\n Rules for Placement : \n");
for (int i = 0; i < 3; i++)
{
    for (int l = 0; l < 3; l++)
    {
        printf("    ");
    }
    
    
    for (int j = 0; j < 3; j++)
    {
        printf("   (%d,%d)",i+1,j+1);
    }
    printf("\n");
}
printf("\n\n");
for (int i = 0; i < 3; i++)
{
    for (int l = 0; l < 3; l++)
    {
        printf("       ");
    }
    for (int j = 0; j < 3; j++)
    {
        printf("%3c",mat[i][j]);
    }
    printf("\n");
}
printf("\nPlayer 1 Symbol : ");
scanf(" %c",&sym[0]);
if (sym[0]=='X')
{
    sym[1]='O';
    printf("Player 2 Symbol : O\n");
}
else{
printf("Player 2 Symbol : X\n");
sym[1]='X';
}
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        printf("\nPlayer %d Turn Place %c position in :  \n",player[k],sym[k]);
        scanf("%d %d",&row,&col);
        if (mat[row-1][col-1]=='_')
        {
            mat[row-1][col-1]=sym[k];
        }
        else
        {
          printf("Cannot Place in the current position, Try-Again\n");
          j--;
          continue;
        }
        k++;
        if (k==2)
        {
            k=0;
        }
        printmatrix();
        checkrow();
        checkcol();
        checkdiagonal();
        
    }
    
}
if (fail==1)
{
    printf("It's A Tie\n");
}
printf("\nThank you for Playing.\n");



return 0;
}
void printmatrix()
{
    system("clear");
    for (int i = 0; i < 3; i++)
    {
        for (int l = 0; l < 3; l++)
        {
        printf("       ");
        }
        for (int j = 0; j < 3; j++)
        {
            printf("%3c",mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void checkrow()
{
    int rowcount=0,rowcount1=0;
    for (int i = 0; i < 3; i++)
    {
    for (int j = 0; j < 3; j++)
    {
        if (mat[i][j]=='X')
        {
            rowcount++;
        }
        else
        {
            break;
        }
        
    }
    if (rowcount==3)
    {
        player1();
        fail=0;
        printf("\nThank you for Playing.\n");
        exit(0);
    }
    rowcount=0;    
}
for (int i = 0; i < 3; i++)
    {
    for (int j = 0; j < 3; j++)
    {
        if (mat[i][j]=='O')
        {
            rowcount1++;
        }
        else
        {
            break;
        }
        
    }
    if (rowcount1==3)
    {
        player2();
        fail=0;
        printf("\nThank you for Playing.\n");
        exit(0);
    }
    rowcount1=0;    
}

}
void checkcol()
{
    int colcount=0,colcount1=0;
    for (int i = 0; i < 3; i++)
        {
           for (int j = 0; j < 3; j++)
           {
               if (mat[j][i]=='X')
               {
                   colcount++;
               }
               else
               {
                   break;
               }
           }
           if (colcount==3)
               {
                player1();
                fail=0;
                printf("\nThank you for Playing.\n");
                exit(0);
              }
            colcount=0;  
        }

         for (int i = 0; i < 3; i++)
        {
           for (int j = 0; j < 3; j++)
           {
               if (mat[j][i]=='O')
               {
                   colcount1++;
               }
               else
               {
                   break;
               }
           }
           if (colcount1==3)
               {
               player2();
               fail=0;
               printf("\nThank you for Playing.\n");
                exit(0);
              }
            colcount1=0;  
        }
}
void checkdiagonal()
{
    if (mat[1][1]=='X')
              {
                  if ((mat[0][0]=='X'&&mat[2][2]=='X') || (mat[0][2]=='X'&&mat[2][0]=='X'))
                  {
                    player1();
                    fail=0;
                    printf("\nThank you for Playing.\n");
                    exit(0);
                  }
                  
              }

     if (mat[1][1]=='O')
              {
                  if ((mat[0][0]=='O'&&mat[2][2]=='O') || (mat[0][2]=='O'&&mat[2][0]=='O'))
                  {
                    player2();
                    fail=0;
                    printf("\nThank you for Playing.\n");
                    exit(0);
                  }
                  
              }          
}
void player1(){
    for (int i = 0; i < 2; i++)
        {
            if (sym[i]=='X')
            {
                printf("Player %d Wins",i+1);
            }
            
        }
}
void player2(){
      for (int i = 0; i < 2; i++)
        {
            if (sym[i]=='O')
            {
                printf("Player %d Wins",i+1);
            }
            
        }
}