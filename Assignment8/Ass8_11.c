#include<stdio.h>
#include<stdlib.h>

void decrease_key(int a[],int i,int key)
{
   a[i]=key;
   if(i%2!=0)

   while(i>0 && a[i/2]>a[i])
   {
     //swap(&a[i],&a[i/2]);
      int m=a[i];
      a[i]=a[i/2];
      a[i/2]=m;
          i=i/2;
   }

   else

   while(i>1 && a[(i/2)-1]>a[i])
   {
     //swap(&a[i],&a[(i/2)-1]);
      int m=a[i];
      a[i]=a[(i/2)-1];
      a[(i/2)-1]=m;
          i=(i/2)-1;
   }

}
void insert(int a[],int *size,int element_to_be)
{  
   *size=*size+1;
   a[*size-1]=2222;
//*size-1 will be i th position to be inserted
   decrease_key(a,*size-1,element_to_be);

}

void main()
{ 

  int a[6]={34,45,2,3,123,5};
  int  i;
  int size=0;
  
  for(i=0;i<6;i++)
  {
   scanf("%d",&a[i]);
   insert(a,&size,a[i]); 
  }
  
  printf("\n%d\n",size);
 
  for(i=0;i<6;i++)
     printf("%d\t",a[i]);
}
