#include<stdio.h>
#include<stdlib.h>
void heapify(int a[],int n,int i)
{
  int lar=i;
  int l=2*i+1;
  int r=2*i+2;
  if(l<n && a[l]<a[lar])
  { lar=l;}
  if(r<n &&a[r]<a[lar])
  { lar=r;}
  if(lar!=i)
  {
    // swap(&a[i],&a[lar]);
     int g=a[i];
     a[i]=a[lar];
     a[lar]=g;
     heapify(a,n,lar);
  }
}
int extract_min(int a[],int size)
{    
   int min=a[0];
   a[0]=a[size-1];
   a[size-1]=min;
   heapify(a,size,0);
   return min;
}   
void heapsort(int a[],int n)
{  
   int i;
   for(i=n/2-1;i>=0;i--)
   {
      heapify(a,n,i);
   }
}
void main()
{ 
  int max;
  scanf("%d",&max);
  int a[max];
  int  i;
  int size=max;
for (i=0;i<max;i++)
scanf("%d",&a[i]);
  heapsort(a,max);
  int k=56;
  int  b[k];
    for(i=0;i<k;i++)
       b[i]=extract_min(a,max-i);

    printf("The least k elements are::\n");
    for(i=0;i<k;i++)
       printf("%d\t",b[i]);
}