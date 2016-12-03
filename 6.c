/* Submitted by
    Name:REDDI HAREESH & Roll Number:150101051
 Question 6: Describe O (n log n) time algorithm for determining if there is an integer a in A and b in B such that m = a + b
 where A and B be two sequences of n integers each.
*/
#include <stdio.h>
#include <stdlib.h>
int binarysearch(int *a, int l, int r, int x)//each binary search takes O(log n) time
{      if(l<=r)//if first location is less than or equal to final location
	{
	     int mid;
	     mid =(l+r)/2;//take mid as average of first and last location

	     if(a[mid] == x)
              return mid;//return the position of the array if required number is found at that location

	     else if(a[mid] > x)
	          return binarysearch(a,l,mid-1,x);//search right half if a[mid] is greater than required number to be searched

	     else
		      return binarysearch(a,mid+1,r,x);//search left half if a[mid] is less than required number to be searched
	 }
	return -1;//return -1 if required number is not found
}
void merge(int a[],int p,int q,int r)
{
    int temparray[r-p+1];       //array used for merging which has size=(index of last element-index of first element+1)
    int i,j,k;
    i=p;    //beginning of the first list
    j=q+1;    //beginning of the second list
    k=0;

    while(i<=q&& j<=r)    //while loop for elements in both lists
    {
        if(a[i]<=a[j])
            temparray[k++]=a[i++];
        else
            temparray[k++]=a[j++];
    }

    while(i<=q)    //copy remaining elements of the first list to temp array
        temparray[k++]=a[i++];

    while(j<=r)    //copy remaining elements of the second list to temp array
        temparray[k++]=a[j++];

    //copying  back the sorted list to a[] from temp[]
    for(i=r;i>=p;i--)
        a[i]=temparray[--k];
}
void mergesort(int a[],int p,int r)//merge sort takes O(n*log n) time
{
    int mid;
    if(p<r)
    {
        mid=(p+r)/2;         //taking mid as average of first and last indexes of given array
        mergesort(a,p,mid);  //left recursion //sorting left array using merge sort
        mergesort(a,mid+1,r);//right recursion  //sorting right array using merge sort
        merge(a,p,mid,r);    //merging of two sorted sub-arrays
    }
}
int main()
{
	int n,m;
	printf("Enter the value of Number of elements of the two sequences:");//n is the no.of elements of both the sequences
	scanf("%d", &n);
	printf("Enter the value of number m:");//m is the given integer which should be expressed as sum of one element in A and other element in B(m=a+b)
	scanf("%d", &m);
    int *a1,*a2,i;
    a1=(int*)malloc(sizeof(int)*n);//giving sufficient memory to a1 sequence
    a2=(int*)malloc(sizeof(int)*n);//giving sufficient memory to a2 sequence

    printf("Enter %d elements of first sequence A:",n);
        for(i = 0; i < n; i++)//for loop
	       scanf("%d",&a1[i]);

    printf("\nEnter %d elements of second sequence B:",n);
        for(i=0;i<n;i++)//for loop
           scanf("%d",&a2[i]);

    mergesort(a2,0,n-1);// sorting second sequence by merge sort which takes O(n*log n) running time
	printf("\n");

    int found=0,c=0;//initialize c as 0
    for(i=0;i<n;i++)
    {
        found= binarysearch(a2,0,n-1,m-a1[i]);//searching m-a[i] in second sequence a2[n] by binary search as second sequence is already sorted
        if(found!=-1)
            {
              c=c+1;//increment no.of possibilities
              printf("\nFound possibility,number %d in first sequence A and number %d in second sequence B whose sum is required number m: %d\n",a1[i],a2[found],m);
            }
    }

    if(c>0)//if number of possibilities are greater than 0
             printf("\nHence there are chances that there is an integer a in A and b in B such that m = a + b.\n");
    else if(found == -1&&c==0)//if number of possibilities are  0 and found is -1
             printf("No possibility Found\n");//if m cannot be expressed as (a+b) where a belongs to sequence A and b belongs to sequence B
	return 0;
}
//Submitted by REDDI HAREESH-150101051-CSE Branch
