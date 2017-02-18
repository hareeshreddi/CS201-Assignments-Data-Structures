/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question7:Write an algorithm running in O(n*log n) for determining no.of inversions in given sequence of n elements
*/
#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int p,int q,int r,int* p2)
{
    int temp[r-p+1];   //array used for merging which has size=(index of last element-index of first element+1)
    int i,j,k;
    i=p;    //beginning of the first list
    j=q+1;    //beginning of the second list
    k=0;
    while(i<=q&&j<=r)    //while elements in both lists
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];//both k and i are incremented
        else
            {temp[k++]=a[j++];//both k and j are incremented
            *p2 =*p2 +q-i+1;//increase the count for number of inversions
            }
    }
    while(i<=q)    //copy remaining elements of the first list to temp array
        temp[k++]=a[i++];

    while(j<=r)    //copy remaining elements of the second list to temp array
        temp[k++]=a[j++];

    //copying  back the sorted list to a[] from temp[]
    for(i=r;i>=p;i--)
        a[i]=temp[--k];
}
void mergesort(int a[],int p,int r,int* p2)//O(n*log n) Algorithm to find Number of inversions
{
    int mid;
    if(p<r)
    {
        mid=(p+r)/2;             // taking mid as average of first index and last index
        mergesort(a,p,mid,p2);  //left recursion //sorting left array using merge sort
        mergesort(a,mid+1,r,p2);//right recursion  //sorting right array using merge sort
        merge(a,p,mid,r,p2);    //merging of two sorted sub-arrays
    }
}
int main()
{   int inversions=0;//start the count for no.of inversions
    int n,i;
    printf("Enter no of elements of sequence :");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);//allotting sufficient memory space
    printf("Enter %d elements of the sequence:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    //sorting using merge sort
    mergesort(a,0,n-1,&inversions);//passing no.of inversions as argument along with merge sort
    printf("\nNumber of inversions in Sequence obtained using merge sort algorithm which takes O(n*log n) running time is:  %d\n",inversions);//total inversions obtained
    return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch

/* A typical recursive C/C++ implementation of QuickSort */

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right 
of pivot */
//Quick Sort with pivot as middle element instead of last element of the array
/*
#include<stdio.h>
#include<stdlib.h>
void swap(int *p1,int *p2)
{
    int x=*p1;
    *p1=*p2;
    *p2=x;
}
int partition (int arr[], int l, int h)
{
    int randomchoose=(l+h)/2;//choosing mid element as pivot
    swap(&arr[randomchoose],&arr[h]);//swapping last element and pivot so that pivot will be at the end of the array
    int x = arr[h];//now arr[h] has actually value arr[(l+h)/2] as it is actually swapped;
    ///////////////////int x=arr[h]; we are writing above 3 lines instead of this line so that 
    ////////we are choosing middle element as pivot instead of last element of the array
    int i = l,j;//x is the pivot
        
    for (j=l;j<=h-1;j++)
    {
        if (arr[j]<=x)
        {
            swap (&arr[i], &arr[j]);
            i++;
        }
    }
    swap (&arr[i ], &arr[h]);
    return (i );//we are returning new position of the pivot
}

 //A[] --> Array to be sorted, 
//l --> Starting index, 
//h --> Ending index 
void quickSort(int A[], int l, int h)//l and h are starting and ending indexes of the array
{
    if (l < h)
    {    
        // Partitioning index 
        //all the elements to the right side of the A[p] are greater than it and elements to the left of it are less than or equal to it
        int p = partition(A, l, h); //p is the partitioning index
        quickSort(A, l, p - 1); //sort the elements to the left side of the A[p]
        quickSort(A, p + 1, h);//sort the elements to the right side of the A[p]
    }
}
/* A typical recursive C/C++ implementation of QuickSort */

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right 
of pivot */
//Quick Sort with pivot as middle element instead of last element of the array
#include<stdio.h>
#include<stdlib.h>
void swap(int *p1,int *p2)
{
    int x=*p1;
    *p1=*p2;
    *p2=x;
}
int partition (int arr[], int l, int h)
{

    int x=arr[h];
    int i = l,j;//x is the pivot    
    for (j=l;j<=h-1;j++)
    {
        if (arr[j]<=x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap (&arr[i], &arr[h]);
    return i;//we are returning new position of the pivot
}

 //A[] --> Array to be sorted, 
//l --> Starting index, 
//h --> Ending index 
void quickSort(int array[],int A[], int l, int h,int k)//l and h are starting and ending indexes of the array
{
    int i;
    for(i=0;i<k;i++)
       {
            printf("%d ",array[i]);
       }
    if (l < h)
    {    
        // Partitioning index 
        //all the elements to the right side of the A[p] are greater than it and elements to the left of it are less than or equal to it
        int p = partition(A,l,h); //p is the partitioning index
       
        printf("har");
        quickSort(array,A, l, p - 1,k); //sort the elements to the left side of the A[p]
        quickSort(array,A, p + 1, h,k);//sort the elements to the right side of the A[p]
    }
}
int main()
{
    int i,n;
    scanf("%d",&n);
    int a[n];
    int k=n;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    quickSort(a,a,0,n-1,k);//passing 0 and 9 to the quickSort as they are start and end indexes respectively
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
int main()
{
    int i;
    int a[10]={32,5,71,6,1,2,11,23,44,4};
    int b[]={4,2,1,3,4};
    quickSort(a,0,9);//passing 0 and 9 to the quickSort as they are start and end indexes respectively
    for(i=0;i<10;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
*/