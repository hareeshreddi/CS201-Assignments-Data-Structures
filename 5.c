/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question5:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// A binary search function to find the position where item should be inserted
int binarysearch(int a[],int item,int low, int high)
{
     if(high<=low&&item<a[low])
           return low;

     if(high<=low&&item>=a[low])
           return low+1;

     int mid = (low + high)/2;//taking mid as average of low and high

     if(item == a[mid])
           return mid+1;

     if(item > a[mid])
           return binarysearch(a, item, mid+1, high);

     return binarysearch(a, item, low, mid-1);
}
void binaryinsertionsort(int a[],int p,int r)// binary insertion sort Function to sort an array a[] of size  r-p+1
{
    int i,j,k;
    int location, selected;
    for (i=p+1;i<r+1;++i) //looping from first index to last index of the sub array
    {
        j=i-1;
        selected=a[i];
        // finding location where selected should be inserted
        location=binarysearch(a, selected, p, j);
        // Moving all elements after location
        while (j>=location)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=selected;
    }
}
void merge(int a[],int p,int q,int r)
{
    int temp[r-p+1];//size of this array is (last index-first index+1)
    int i,j,k;
    i=p;            //beginning of the first list
    j=q+1;          //beginning of the second list
    k=0;            //first index of temp array is 0
    while(i<=q&& j<=r)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=q)    //copy the remaining elements of the first list to temp array
        temp[k++]=a[i++];

    while(j<=r)    //copy the remaining elements of the second list to temp array
        temp[k++]=a[j++];

    //copying  back the sorted list to a[] from temp[]
    for(i=r;i>=p;i--)
        a[i]=temp[--k];

}
void mergesort(int a[],int p,int r)//merge sort function
{
     int mid;
     if(r-p+1>=55)               //threshold value is 55 that is if any sub array has more than or equal to 55 elements
    {
        mid=(p+r)/2;             //finding the middle position
        mergesort(a,p,mid);      //left recursion //sorting left half using merge sort
        mergesort(a,mid+1,r);    //right recursion  //sorting right half using merge sort
        merge(a,p,mid,r);        //merging of two halves
    }
    else if(r-p>0)               //do binary insertion sort for size less than 55
    {
        binaryinsertionsort(a,p,r);
    }
}
void sort(int a[],int n)
{
    if(n>=55)//55 is the threshold value
        mergesort(a,0,n-1);//we will use binary insertion sort condition inside merge sort condition again if size of some sublist is less than 55
    else
        binaryinsertionsort(a,0,n-1);//if initially less than 55 elements are given,sort it by binary insertion sort
}
int main()
{
    int n,i;
    printf("Enter the number of elements to be sorted:");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);//allotting sufficient memory space
    int t=time(NULL);
    srand(t);
    for(i=0;i<n;i++)
        a[i]=rand()%1000;//obtaining elements randomly
    printf("The random elements generated are:\n");
    for(i=0;i<n;i++)    //printing those random numbers
       printf("%d\t",a[i]);
    sort(a,n);
    printf("\nFinal output after sorting is:\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);//printing the final result
    return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch

