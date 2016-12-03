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
