#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delete1(int a[],int key,int m,int i)
{  

   int l=(((key%m)+i+3*i*i)%m);
  if(i!=m)
 {
   if(a[l]==key)
     {
     a[l]=-2;
     printf("Index  of insertion  of %d is %d\n",key,l); 
     printf("Number of collisions of %d is %d\n",key,i);
     printf("The element %d is deleted\n\n",key);
     }
   else
     {
     i=i+1;
     delete1(a,key,m,i);
     }
  }
  else
     printf("The element cannot be found::\n\n");
}
 
void delete(int a[],int key,int m,int i)
{
  
  int l=(((key%m)+i)%m);
  if(i!=m)
 {
   if(a[l]==key)
     {
     a[l]=-2;
     printf("Index  of insertion  of %d is %d\n",key,l); 
     printf("Number of collisions of %d is %d\n",key,i);
     printf("The element %d is deleted\n\n",key);
     }
   else
     {
     i=i+1;
     delete(a,key,m,i);
     }
  }
  else
     printf("The element cannot be found::\n\n"); 
}
void delete2(int a[],int key,int m,int i)
{  

  int l1=(key%m);
  int l2=i*(1+key%(m-1));
  int p=(l1+l2)%m;
  if(i!=m)
 {
   if(a[p]==key)
     {
     a[p]=-2;
     printf("Index  of insertion  of %d is %d\n",key,p); 
     printf("Number of collisions of %d is %d\n",key,i);
     printf("The element %d is deleted\n\n",key);
     }
   else
     {
     i=i+1;
     delete2(a,key,m,i);
     }
  }
  else
     printf("The element cannot be found::\n\n"); 
}
 

  
int insert2(int a[],int key,int m,int i,int count)
{  

  int l1=(key%m);
  int l2=i*(1+key%(m-1));
  int p=(l1+l2)%m;
  if(i!=m)
 {
   if(a[p]==-1)
     {
     a[p]=key;
     printf("Index  of insertion  of %d is %d\n",key,p); 
     printf("Number of collisions of %d is %d\n\n",key,i);
     count=count+i;
     }
   else
     {
     i=i+1;
     insert2(a,key,m,i);
     }
  }
  else
     printf("There is overflow in the insertion\n\n");
  return count;
}
 

void insert1(int a[],int key,int m,int i)
{  

   int l=(((key%m)+i+3*i*i)%m);
  if(i!=m)
 {
   if(a[l]==-1)
     {
     a[l]=key;
     printf("Index  of insertion  of %d is %d\n",key,l); 
     printf("Number of collisions of %d is %d\n\n",key,i);
     }
   else
     {
     i=i+1;
     insert1(a,key,m,i);
     }
  }
  else
     printf("There is overflow in the insertion\n\n");
}
 

void insert(int a[],int key,int m,int i)
{  

   int l=(((key%m)+i)%m);
  if(i!=m)
 {
   if(a[l]==-1)
     {
     a[l]=key;
     printf("Index  of insertion  of %d is %d\n",key,l); 
     printf("Number of collisions of %d is %d\n\n",key,i);
     }
   else
     {
     i=i+1;
     insert(a,key,m,i);
     }
  }
  else
     printf("There is overflow in the insertion\n\n");
}
 
void print(int a[],int m)
{
  int i;
  printf("The elements are::\n");
  for(i=0;i<m;i++)
  { printf("%d\t",a[i]);}
  printf("\n\n");
} 
int main()
{
  int count=0;
  srand(time(NULL));
  int m,n,i;
  int d;
  printf("Enter the value of m::");
  scanf("%d",&m);
  int a1[m],a2[m],a3[m];
  for(i=0;i<m;i++)
    {
     a1[i]=-1;
     a2[i]=-1;
     a3[i]=-1;
    }
  printf("number of values to be inserted are(which is randomly generated is)::");
  //scanf("%d",&n);
  n=rand()%m+1;
  printf("%d\n\n",n);
  int k1[n],k2[n],k3[n];
  //printf("Enter %d values which are to be inserted::",n);
  for(i=0;i<n;i++)
   {
    //scanf("%d",&k[i]);
    k1[i]=rand()%1000;
   }
  printf("The randomly generated elements are::\n\n");
  for(i=0;i<n;i++)
  { 
    printf("Element %d is %d\n",i+1,k1[i]);
  }   
  for(i=0;i<n;i++)
   {
     k2[i]=k1[i];
     k3[i]=k1[i];
   }


   printf("\ncase 0::linear probing\n\n");
   for(i=0;i<n;i++)
     insert(a1,k1[i],m,0);
   printf("Enter the element to be deleted::");
   scanf("%d",&d);
   delete(a1,d,m,0);
   print(a1,m);

   printf("\ncase 1::quadratic probing\n\n");
   for(i=0;i<n;i++)
     insert1(a2,k2[i],m,0);
   printf("Enter the element to be deleted::");
   scanf("%d",&d);
   delete1(a2,d,m,0);
   print(a2,m);
    

  printf("\ncase 2::double hashing\n\n");
   for(i=0;i<n;i++)
     count=insert2(a3,k3[i],m,0,count);
   printf("Enter the element to be deleted::");
   scanf("%d",&d);
   delete2(a3,d,m,0);
   print(a3,m);
   printf("Total::%d",count);

}
 
