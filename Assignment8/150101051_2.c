/* Submitted by
    Name:REDDI HAREESH 
    Roll Number:150101051
    Assignment:8 
    Question Number:2
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<math.h>
#include<limits.h>

    struct node* MAKE_BINOMIAL_HEAP();

    void LINK_2(struct node*, struct node*);
     
    int DISPLAY(struct node*);
    
    void showHeap(struct node*,int,int);
    
    int check(struct node*);

    struct node* BINOMIAL_HEAP_UNION(struct node*, struct node*);

    struct node* BINOMIAL_HEAP_INSERT(struct node*,int);

    struct node* BINOMIAL_HEAP_MERGE(struct node*, struct node*);
    
    struct new BINOMIAL_HEAP_EXTRACT_MINIMUM(struct node*);
    
    void ReverseList(struct node*,struct node**);
        
struct new
{
   struct node* n1;
   struct node* n2;
      
}new1;

struct node 
{

    int key;
    int degree;//no.of children of the node
    struct node* parent;//parent of the node
    struct node* lchild;//leftmost child of the node
    struct node* sibling;//sibling of the node
};

//if H is NULL, value returned will be 1 
int check(struct node* H)
{
    if(H == NULL)
    {  
       return 1;
    }
}

struct node* MAKE_BINOMIAL_HEAP()
{
        struct node* variable=NULL;
        return variable;
}

//This function links the 2 nodes in proper manner
void LINK_2(struct node* y, struct node* z) 
{
        y->parent = z;
        y->sibling = z->lchild;
        z->lchild = y;
        z->degree = z->degree + 1;
}

//This function is used to insert an element into the Binomial Heap
struct node* BINOMIAL_HEAP_INSERT(struct node* H, int k) 
{
       
        struct node* x = (struct node*) malloc(sizeof(struct node));
        x->key = k;
        x->parent = NULL;
        x->lchild = NULL;
        x->sibling = NULL;
        x->degree = 0;
        H = BINOMIAL_HEAP_UNION(H, x);
        return H;
}

//This function is used to unite the two binomial heaps H1 and H2  into single binomial heap H
struct node* BINOMIAL_HEAP_UNION(struct node* H1, struct node* H2) 
{

        struct node* prev_x;
        struct node* next_x;
        struct node* x;
        struct node* H =NULL;
        
        H = BINOMIAL_HEAP_MERGE(H1,H2);
        if (H == NULL)
            return H;
            
        prev_x = NULL;
        x = H;
        next_x = x->sibling;

        while (next_x != NULL)
         {

            if ((x->degree != next_x->degree) || ((next_x->sibling != NULL) && (next_x->sibling)->degree == x->degree))
             {
                prev_x = x;
                x = next_x;
             }
             else 
             {

                     if (x->key <= next_x->key)
                     {
                 
                      x->sibling = next_x->sibling;
                      LINK_2(next_x, x);
                     }
                  
                    else 
                     {

                      if (prev_x == NULL)
                           H = next_x;
                        
                      else                       
                           prev_x->sibling = next_x;
                           
                      LINK_2(x, next_x);
                      x = next_x;
                         
                     }
               }

            next_x = x->sibling;
            
        }
        return H;  
}


void showHeap(struct node *x,int count,int depth)                      
{
    if( x->sibling != NULL )
    {
        showHeap(x->sibling,count,depth);
    }
    if(x->parent==NULL)
    {
        printf("\n");
    }
    
    if ( ( x->lchild != NULL ) || ( x->parent == NULL ) )
    {
        int i;
        for(i=1 ; i <= 5*(depth)+5+count; i++)
        {
            printf(" ");
        }
        printf("%d",x->key);

        if ( x->lchild == NULL )
        {
            printf("\n\n");
        }
    }
    else
    {
        printf("     %d\n\n",x->key);
    }
    
    if ( x->lchild != NULL )
    {
        count++;
        showHeap( x->lchild,count,depth+1);
    }
}

int DISPLAY(struct node* H) 
{
        struct node* p;
        p=H;
        printf("Structure of binomial heap (rotated 90 degrees counterclockwise)::\n");
        if (H == NULL)
        {
            printf("Heap Empty\n");
            return 0;
        }
//passing 0 and 0 as inputs for count and depth for the function         
        else
            showHeap(H,0,0);
}

struct node* BINOMIAL_HEAP_MERGE(struct node* H1, struct node* H2)
{

        struct node* H = NULL;
        struct node* y= H1;
        struct node* z= H2;
          
        if(y == NULL)
            H =z;  
                        
        else if(z== NULL)    
            H = y;
            
        else
        {

            if ( y->degree <= z->degree)
                H = y;

            else
                H = z;
        } 
        
        if(H == z)
        {   
          y=H2;
          z=H1;
          H=y;    
        }
        
      struct node *temp1;
      struct node* temp2;
      while( z!= NULL)
       {
        if(y->sibling!=NULL&&y->degree<= z->degree && (y->sibling)->degree>= z->degree)
              { 
                 
                 temp1=y->sibling;
                 temp2=z->sibling;
                 y->sibling=z;
                 z->sibling=temp1;
                 y=y->sibling;
                 z=temp2;
               }
               
         else if(y->sibling!=NULL&&y->sibling->degree < z->degree )
               
               {  y=y->sibling;}
               
         else if(y->sibling==NULL)
                {
                  y->sibling=z;
                  break;
                }
         }
        return H;
}     
  
int main(void)
{

    new1.n1=NULL;
    new1.n2=NULL;
    printf("\nFollowing are the options::\n");
    printf("\t\t\tMAKE_BINOMIAL_HEAP         :: c\n");
    printf("\t\t\tBINOMIAL_HEAP_UNION        :: u\n");
    printf("\t\t\tBINOMIAL_HEAP_INSERT       :: i\n");
    printf("\t\t\tshowHeap                   :: s/S\n");
    printf("\t\t\tTurn off Print after extract min    :: -\n");
    printf("\t\t\tTurn on print after extract min     :: +\n");
    printf("\t\t\tBINOMIAL-HEAP-EXTRACT-MINIMUM       ::d\n");
    printf("Start entering your choices(c/i/S/-/+/d)::\n");
    
//The first input must be c as we are first creating empty heap before performing any other operation
     int i,m;
     struct node* H ;
     int l=0,p1=0;
     int flag=0;
     char ch;
     struct node* p =NULL;
     H=NULL;
      do
      { 
         scanf("%c",&ch);
         switch(ch)
         {
        
           case 'c':        
              H =MAKE_BINOMIAL_HEAP();
              break;
              
           case 'i':          
              scanf("%d",&m);
              H =BINOMIAL_HEAP_INSERT(H,m);
              break; 
              
           case 'd':             	
               new1=BINOMIAL_HEAP_EXTRACT_MINIMUM(H);
               H=new1.n1;
               p=new1.n2;
               l=check(H);
               if(p!=NULL && flag==1)
                     printf("Minimum extracted :: %d\n",p->key);
               else if(p==NULL)
                     printf("Heap is empty\n\n"); 
               break;
               
           case '+':
               flag=1;
               break;
               
           case '-':
               flag=0;
               break;
               
           case 's':
           case 'S':
                DISPLAY(H);
                break;
          }
               
           if(l==1)
                {
                  p1=1;
                  break;
                }
                
      } while(1);
      
      return 0;
}

struct new BINOMIAL_HEAP_EXTRACT_MINIMUM(struct node* H1)
{       
        int min;
        struct node* var = NULL;
        struct node* x = H1;
        struct node *H2 =NULL;
        struct node* p;
        struct node* q;
        p=x;
        q=H1;
        if (x == NULL) 
        {    
            printf("Nothing is there to extract in the binomial heap\n");
             new1.n1=NULL;
             new1.n2=NULL;
            return new1;
        }
        
        min=q->key;
        while (p->sibling != NULL)
        {
            if ((p->sibling)->key < min)
             {
                min = (p->sibling)->key;
                var = p;
                x = p->sibling;

              }
              
            p = p->sibling;
        }
        
        if(min==q->key)
            H1=(H1)->sibling;
                  
        else
        {
        if (var == NULL && x->sibling == NULL)
            H1 = NULL;
            
        else if (var == NULL)
            H1 = x->sibling;
            
        else if (var->sibling == NULL)
            var = NULL;
        else
            var->sibling = x->sibling;
         }
        if (x->lchild != NULL) 
        {
            ReverseList(x->lchild,&H2);
            (x->lchild)->sibling = NULL;
        }
       
        H1 = BINOMIAL_HEAP_UNION(H1,H2);
        new1.n1=H1;
        new1.n2=x;
        
        return new1;

}
void ReverseList(struct node* y,struct node** H2)
{
        if (y->sibling != NULL) 
        {
            ReverseList(y->sibling,H2);
            (y->sibling)->sibling=y ;

        } 
        else 
        {
            *H2 = y;
        }
}
//Code for Binomial Heap
