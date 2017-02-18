/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
    Question4:Write Merge Sort Algorithm
*/
#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int p,int q,int r)
{
    int temp[r-p+1];    //array used for merging which has size=(index of last element-index of first element+1)
    int i,j,k;
    i=p;    //beginning of the first list
    j=q+1;  //beginning of the second list
    k=0;    //initializing k to zero
    while(i<=q&&j<=r)    //while loop for both the lists
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=q)            //while loop for first list
        temp[k++]=a[i++]; //copy remaining elements of the first list to temp array

    while(j<=r)            //while loop for second list
        temp[k++]=a[j++]; //copy remaining elements of the second list to temp array

    //copying  back the sorted list to a[] from temp[]
    for(i=r;i>=p;i--)
        a[i]=temp[--k];
}
void mergesort(int a[],int p,int r)//p is index of first element and r is the index of last element of the array
{
    int mid;
    if(p<r)//if the array have more than 1 element
    {
        mid=(p+r)/2;         //taking mid as average of first and last indexes of the sub-lists
        mergesort(a,p,mid);  //left recursion  //sorting left sublist using merge sort
        mergesort(a,mid+1,r);//right recursion //sorting right sublist using merge sort
        merge(a,p,mid,r);    //merging of two sorted sub-lists
    }
}

int main()
{
    int n,i;
    printf("Enter no of elements which are to be sorted using merge sort:");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);//giving sufficient memory
    printf("Enter the %d elements to be sorted:",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergesort(a,0,n-1);//sorting the given array by merge sort
    printf("\nFinal output obtained after merge sort is:");
    for(i=0;i<n;i++)
        printf("\t%d",a[i]);//printing the final result
    return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch
