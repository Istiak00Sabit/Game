#include<stdio.h>
#include<stdbool.h>
void Win(int n,int a[][4],int who)
{
    for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++)
        {
         if(a[i][j]== who)
         {
          if(a[i][j] == 1)
          printf("X");
          if(a[i][j] == 2)
          printf("O");
         }
         else
         {
             printf(" ");
         }
         if(j<n)
          printf("\t|\t");
        }
         printf("\n");
        if(i<3)
         printf("-----------------------------------");
         printf("\n");
    }
}
int whoWin(int n,int a[][4])
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][1] == a[i][2] && a[i][2] == a[i][3] &&     a[i][1] != -1)
        {
            return a[i][1];
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(a[1][j] == a[2][j] && a[2][j] == a[3][j] &&     a[1][j] != -1)
        {
            return a[1][j];
        }
    }
    if(a[1][1] == a[2][2] && a[2][2] == a[3][3] &&     a[1][1] != -1)
    {
        return a[1][1];
    }
    if(a[1][3] == a[2][2] && a[3][1] == a[2][2] && a[2][2] != -1)
    {
        return a[2][2];
    }
    return -1;
}

void printCell(int n,int a[][4])
{
for(int i=1;i<=n;i++)
    {
    for(int j=1;j<=n;j++)
        {
         if(a[i][j]== -1)
          printf(" ");
          if(a[i][j] == 1)
            printf("X");
          if(a[i][j] == 2)
        printf("O");
         if(j<n)
          printf("\t|\t");
        }
         printf("\n");
        if(i<3)
         printf("-----------------------------------");
         printf("\n");
    }
}
int main()
{
    int n=3;
    int a[4][4];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=-1;
        }
    }
    bool player1 = true;
    bool player2 = false;
    while(true)
    {
          printCell(n,a);
         int r,c;
        //man 1 = 1
        if(player1)
        {
            Flag1:
            printf("Player 1 turn (X) , Enter the row and coloumn : ");
            scanf("%d %d",&r,&c);
            if(a[r][c] != -1)
            {
                printf("Invalid cell, Enter again\t");
                goto Flag1;
            }
            a[r][c] = 1;
            player1 = false;
            player2 = true;
        }
        //man2 = 2
        else
        {
            Flag2:
            printf("Player 2 turn (O) , Enter the row and coloumn : ");
            scanf("%d %d",&r,&c);
              if(a[r][c] != -1)
            {
                printf("Invalid cell, Enter again\t");
                goto Flag2;
            }
            a[r][c] = 2;
            player2 = false;
            player1 = true;
        }
        //Checking
        if(whoWin(n,a) == 1)
        {
            printf("Player 1 Win Congratulation (-_-)\n");
            Win(n,a,1);
            break;
        }
        else if(whoWin(n,a) == 2)
        {
            printf("Player 2 Win Congratulation (-_-)\n");
            Win(n,a,2);
            break;
        }


    }
}
