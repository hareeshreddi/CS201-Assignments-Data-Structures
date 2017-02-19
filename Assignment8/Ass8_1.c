#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
//alert::if indexes of heap starts from 0;parent of i(if i is odd) is  (i-1)/2 and not (i/2)-1
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

void decrease_key(int a[],int i,int key)
{
   a[i]=key;
   if(i%2!=0)
   {
     while(i>0 && a[i/2]>a[i])
     {
     //swap(&a[i],&a[i/2]);
      int m=a[i];
      a[i]=a[i/2];
      a[i/2]=m;
           i=i/2;
     }
   }
   else
   {
     while(i>0 && a[(i-1)/2]>a[i])
     {
     //swap(&a[i],&a[(i/2)-1]);
      int m=a[i];
      a[i]=a[(i-1)/2];
      a[(i-1)/2]=m;
          i=(i-1)/2;
     }
   }

}
void insert(int a[],int *size,int element_to_be)
{  
   *size=*size+1;
   a[*size-1]=INT_MAX;
//*size-1 will be i th position to be inserted
   decrease_key(a,*size-1,element_to_be);
}

void main()
{ 

  int max;
  printf("Enter the no of elements::");
  scanf("%d",&max);
  int  i;
  int size=0;
  int a[max];
  printf("\nEnter the elements::");
  for(i=0;i<max;i++)
  {
   scanf("%d",&a[i]);
   insert(a,&size,a[i]); 
  }
  
  printf("\n%d\n",size);
  for(i=0;i<6;i++)
     printf("%d\t",a[i]);
  printf("\n\n");
  
  
   int k=3;
  int  b[k];
    for(i=0;i<k;i++)
       b[i]=extract_min(a,max-i);

    printf("The least k elements are::\n");
    for(i=0;i<k;i++)
       printf("%d\t",b[i]);
}
