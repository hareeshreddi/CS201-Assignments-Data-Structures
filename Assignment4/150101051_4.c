/*Submitted by
       Name:REDDI HAREESH  & Roll Number:150101051
       Question Number:4
*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
 struct output
{
    int in;
    int check;
};

int checkthepath(int n,int m,struct output a[][m],int row,int col)
{  int i,j;
  if(row==n-1 || col==m-1 || row==0 || col==0)
    if(a[row][col].check==0)
     {
     printf("Submitted");
     return 0;
      }
  a[row][col].check=1;

  if(row+1<n && a[row+1][col].in==1 && a[row+1][col].check==0)
       if(checkthepath(n,m,a,row+1,col)==0)
         return 0;

  if(row>0 && a[row-1][col].in==1 && a[row-1][col].check==0)
        if(checkthepath(n,m,a,row-1,col)==0)
         return 0;

  if(col+1<m && a[row][col+1].in==1 && a[row][col+1].check==0)
        if(checkthepath(n,m,a,row,col+1)==0)
            return 0;

  if(col>0 && a[row][col-1].in==1 && a[row][col-1].check==0)
        if(checkthepath(n,m,a,row,col-1)==0)
            return 0;
return 1;

}
int findoutput(int n,int m,struct output a[][m])
{  int i;
   i=0;
    while(i<n)
    {
    if(a[i][0].in==1 && a[i][0].check==0)
       {a[i][0].check=1;
        if(checkthepath(n,m,a,i,0)==0)
            return 0;
       }
       i++;
    }
    i=0;
    while(i<n)
    {
    if(a[i][m-1].in==1 && a[i][m-1].check==0)
       {a[i][m-1].check=1;
         if(checkthepath(n,m,a,i,m-1)==0)
            return 0;
       }
       i++;
    }
     i=0;
    while(i<m)
    {
    if(a[0][i].in==1 && a[0][i].check==0)
        {a[0][i].check=1;
         if(checkthepath(n,m,a,0,i)==0)
            return 0;
        }
    i++;
     }
    i=0;
    while(i<m)
    {
    if(a[n-1][i].in==1 && a[n-1][i].check==0)
        {a[n-1][i].check=1;
         if(checkthepath(n,m,a,n-1,i)==0)
            return 0;
        }
    i++;
    }
 printf("Bad Luck\n");
}

int checktheboundry(int n,int m,struct output a[][m])
{  int i=0,count=0;

  while(i<n)
    {
    if(a[i][0].in==1&&a[i][0].check==0)
      {
     a[i][0].check=1;
     count++;
       }
     i++;
     }

 for(i=0;i<n;i++)
    if(a[i][m-1].in==1&&a[i][m-1].check==0)
    {
     a[i][m-1].check=1;
     count++;
     }
  i=0;
  while(i<m)
    {
    if(a[0][i].in==1&&a[0][i].check==0)
     {
     a[0][i].check=1;
     count++;
     }
     i++;
    }

 for(i=0;i<n;i++)
    if(a[n-1][i].in==1&&a[n-1][i].check==0)
     {
      a[n-1][i].check=1;
      count++;
     }
 return count;
}
int main()
{
    static int p=0;
    while(1)
    {
    int n,m,i,j;// n and m are no.of rows and columns respectively of the map
    p++;
    printf("Case:%d\n",p);
    printf("Enter the number of rows and columns of the map:");
    scanf("%d %d",&n,&m);
    if(m==0&&n==0)
        break;//come out of the loop
    printf("\nEnter the way of jungle:");
    char pathvariable;
    struct output a[n][m];
    printf("\n");
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
      scanf(" %c",&pathvariable);
       if(pathvariable=='t'||pathvariable=='T')
            a[i][j].in=0;
       else
            a[i][j].in=1;

       a[i][j].check=0;
      }
      printf("\n");
    }
  int  x=checktheboundry(n,m,a);
  for(i=0;i<n;i++)
     for(j=0;j<m;j++)
        a[i][j].check=0;

    if(x==2)
        findoutput(n,m,a);
    else
        printf("Bad Luck\n");
    printf("\n\n");
    }
    return 0;
}
