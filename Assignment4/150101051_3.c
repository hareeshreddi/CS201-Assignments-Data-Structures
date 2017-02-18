/* Submitted by
      Name:REDDI HAREESH & Roll Number:150101051
      Question3:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//structure to store data
  struct node {
        int row, col, val;
        struct node *right, *down;
  };

//structure of column head
  struct chead {
        int col;
        struct chead *next;
        struct node *down;
  };

//structure of row head
  struct rhead {
        int row;
        struct rhead *next;
        struct node *right;
  };

//structure of additional head
  struct sparsehead {
        int rowCount, colCount;
        struct rhead *frow;
        struct chead *fcol;
  };

//main node
  struct sparse {
        int row, *data;
        struct node *nodePtr;
        struct sparsehead *smatrix;
        struct rhead **rowPtr;
        struct chead **colPtr;
  };

//Build the row and column links
  void initialize(struct sparse *sPtr, int row, int col) {
        int i;
        //memory allocation
        sPtr->rowPtr = (struct rhead **) calloc(1, (sizeof (struct rhead) * row));
        sPtr->colPtr = (struct chead **) calloc(1, (sizeof (struct chead) * col));
        for (i = 0; i < row; i++)
                sPtr->rowPtr[i] = (struct rhead *) calloc(1, sizeof (struct rhead));

        for (i = 0; i < row - 1; i++) {
                sPtr->rowPtr[i]->row = i;
                sPtr->rowPtr[i]->next = sPtr->rowPtr[i + 1];
        }

        for (i = 0; i < col; i++)
                sPtr->colPtr[i] = (struct chead *) calloc(1, sizeof (struct chead));

        for (i = 0; i < col - 1; i++) {
                sPtr->colPtr[i]->col = i;
                sPtr->colPtr[i]->next = sPtr->colPtr[i + 1];
        }

//update additional head information
        sPtr->smatrix = (struct sparsehead *) calloc(1, sizeof (struct sparsehead));
        sPtr->smatrix->rowCount = row;//assigning rowCount as no.of rows of matrix
        sPtr->smatrix->colCount = col;//assigning colCount as no.of columns of matrix
        sPtr->smatrix->frow = sPtr->rowPtr[0];
        sPtr->smatrix->fcol = sPtr->colPtr[0];
        return;
  }

//input sparse matrix
  void InputMatrix(struct sparse *sPtr, int row, int col,int k)
  {
        int t=time(NULL);
        srand(t);
        int i, j, n;
        int h=0,c=1;//starting counter c as 1
        n = row * col;//n=no.of elements of the matrix
        sPtr->data = (int *) malloc(sizeof (int) * n);//allocate sufficient memory
        for(h=0;h<n;h++)
        {
        (sPtr->data[h])=0;//initialize all elements to 0 initially
        }
//while loop will run if value of c is less than or equal to value of k
        while(c<=k)
      {
        i=rand()%row;//i will be randomly generated
        j=rand()%col;//j will be randomly generated
        if((sPtr->data[col*i+ j])==0)
        {
            (sPtr->data[col*i+ j])=rand()%1000;//replace 0 with randomly generated values for the randomly generated indexes
            c++;
        }
      }
  }

//displaying of randomly generated matrix
  void displayInputMatrix(struct sparse s, int row, int col)
  {
        int i;
        for (i = 0; i < row * col; i++)
            {
                if (i % col == 0)
                        printf("\n\n");
                printf("%d\t", s.data[i]);
            }
        printf("\n");
        return;
  }

//create 3-tuple array from randomly generated matrix
  void createThreeTuple(struct sparse *sPtr, struct sparse s, int row, int col,int k)
  {
        int i, j = 0, x = 0, y = 0, l = 0;
        sPtr->row = k;
        sPtr->data = (int *) malloc(sizeof(int)*(sPtr->row * 3));

        for (i = 0; i < row * col; i++) {
                if (y % col == 0 && y != 0) {
                        x++;
                        y = 0;
                }
                if (s.data[i] != 0) {
                        sPtr->data[l++] = x;//we are doing this assignment for indexes of l=0,3,6,9,12......
                        sPtr->data[l++] = y;//we are doing this assignment for indexes of l=1,4,7,10,13......
                        sPtr->data[l++] = s.data[i];//we are giving non zero values of the matrix for indexes of l=2,5,8,11,14.....
                }
                y++;
        }
        return;
  }
//insert element to the list
  void insert(struct sparse *sPtr, int row, int col, int value) {
        struct rhead *rPtr;
        struct chead *cPtr;
        struct node *n1, *n2;
        struct sparsehead *smat = sPtr->smatrix;
        int i, j;

//update node values
        sPtr->nodePtr = (struct node *) malloc(sizeof (struct node));
        sPtr->nodePtr->row = row;
        sPtr->nodePtr->col = col;
        sPtr->nodePtr->val = value;

//get the row head node
        rPtr = smat->frow;

//move to corresponding row
        for (i = 0; i < row; i++)
                rPtr = rPtr->next;

//traverse the nodes in current and locate new node
        n1 = rPtr->right;
        if (!n1) {
                rPtr->right = sPtr->nodePtr;
                sPtr->nodePtr->right = NULL;
        } else {
                while (n1 && n1->col < col) {
                        n2 = n1;
                        n1 = n1->right;
                }
                n2->right = sPtr->nodePtr;
                sPtr->nodePtr->right = NULL;
        }

//get the column head node
        cPtr = sPtr->smatrix->fcol;

//move to corresponding column
        for (i = 0; i < col; i++)
                cPtr = cPtr->next;

//traverse the node in current column and locate new node in appropriate position
        n1 = cPtr->down;
        if (!n1) {
                cPtr->down = sPtr->nodePtr;
                sPtr->nodePtr->down = NULL;
        } else {
                while (n1 && n1->row < row) {
                        n2 = n1;
                        n1 = n1->down;
                }
                n2->down = sPtr->nodePtr;
                sPtr->nodePtr->down = NULL;
        }
        return;
  }

//create list for 3-Tuple representation
  void createList(struct sparse *sPtr) {
        int i, j = 0;
        for (i = 0; i < sPtr->row; i++) {
                insert(sPtr, sPtr->data[j], sPtr->data[j + 1], sPtr->data[j + 2]);
                j = j + 3;
        }
        return;
  }

//this function returns highest value of the matrix
//in Highest function k is 3 times the no.of non zero elements of the matrix
int Highest(struct sparse s,int k)
{     if(k==0)//if number of non zero elements are 0 then highest number is 0 itself
       {
        return 0;
       }
      int i,maximum;
      maximum=s.data[2];//as indexes of l varies as 2,5,8,11,14......,k-4,k-1 for non zero values of the matrix
      //loop repeats for k/3 times as index i is increasing with speed 3 each time
      for(i=2;i<k;i++)
      {
          if(s.data[i]>=maximum)
          {
               maximum=s.data[i];
          }
          i=i+2;//increase index by 3 each time
      }
      return maximum;
}
  int main()
  {
        struct sparse s1,s2;
        int rows, cols,k;
        printf("\nPlease enter positive integer values for number of rows and columns of the matrix\n\n");
        printf("Enter the number of rows of the matrix:");
        scanf("%d",&rows);
        printf("\n");
        printf("Enter the number of columns of the matrix:");
        scanf("%d",&cols);
        printf("\n");
        printf("Enter number of non zero elements of the matrix:");
        scanf("%d",&k);
        printf("\n");
        initialize(&s1, rows, cols);
        initialize(&s2, rows, cols);

        InputMatrix(&s1, rows, cols,k);
        printf("Randomly generated Matrix with %d rows and %d columns is:\n",rows,cols);
        displayInputMatrix(s1, rows, cols);
        printf("\n\n");
//s2 contains final output i.e. non zero elements with their indexes of the randomly generated matrix
        createThreeTuple(&s2,s1, rows, cols,k);
        createList(&s2);
//in main function k is no.of non zero elements of the matrix
        printf("The Highest element in the sparse matrix is: %d\n\n",Highest(s2,3*k));//we are passing 3*k as argument because we have to check for indexes 2,5,8,.....3*k-4,3*k-1
        return 0;
  }
//Submitted by REDDI HAREESH-150101051-CSE Branch-Phone No:7664817751
