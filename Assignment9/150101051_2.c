/* Submitted by
    Name:REDDI HAREESH 
    Roll Number:150101051
    Assignment:9
    Question Number:2
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<math.h>
#include<limits.h>

struct node* MAKE_FIB_HEAP();
struct node* Create_node(int);
struct node* FIB_HEAP_INSERT(struct node*,struct node*);
struct node* FIB_HEAP_UNION(struct node*,struct node*,int);
void DISPLAY(struct node*,int,int);
int check(struct node*);
int FIBONACCI_LINK(struct node*,struct node*,struct node*,int);
struct node* FIB_HEAP_EXTRACT_MINIMUM(struct node*,int*,int*);
struct node* Consolidate(struct node*,int);
struct node* HEAP_LINK(struct node*,struct node*,int);
struct node* Create_Child(struct node*, struct node*,int); 
int Num_Nodes(struct node*);    
           
struct node
{
    struct node* parent;
    struct node* child;
    struct node* left;
    struct node* right;
    char mark;
    char C;
    int key;
    int degree;
};

struct variable                     
{
    struct node *ptr;
};

struct node* MAKE_FIB_HEAP()
{
    struct node* variable=NULL;
    return variable;
}

struct node* Create_node(int value)
{
    struct node* x =malloc(sizeof(struct node));
    x->key = value;
    return x;
}

struct node* FIB_HEAP_INSERT(struct node* H,struct node* x)
{
    x->degree = 0;
    x->parent = NULL;
    x->child = NULL;
    x->left = x;
    x->right = x;
    x->mark = 'F';
    x->C = 'N';

    if (H != NULL)
    {

        (H->left)->right = x;
        x->right = H;
        x->left = H->left;
        H->left = x;
        
        if (x->key < H->key)
            H = x;
    }
    else
        H = x;
        
    return H;
}

struct node* FIB_HEAP_Union(struct node* H1,struct node* H2,int total)
{
    struct node* var;
    struct node* H =NULL;
    H = H1;
    (H->left)->right = H2;
    (H2->left)->right = H;
    
    var = H->left;
    H->left = H2->left;
    H2->left = var;
    
    return H;
}

int check(struct node* head)
{ 
  if(head==NULL)
     return 1;
     
}
void DISPLAY(struct node* variable,int depth,int total)                       
{
    if(variable==NULL)
        printf("Fibonacci Heap is empty\n\n");
        
    struct node *Temporary=variable;
    int i,j,k;
    i=0;
    j=0;
    k=Num_Nodes(Temporary);                            
    while(i<k)
    {
        while(j< 9*depth)     
        {
            printf(" ");
            j++;
        }
        printf("   %d",variable->key);
        if(variable->child!=NULL)            
        {
            printf("\n");
            DISPLAY(variable->child,depth+1,total); 
        }
        else
        {
            printf("\n\n");
        }
        variable=variable->right; 
        
      i++;                    
    }
}

int main(void)
{

    printf("\nFollowing are the options::\n");
    printf("\t\t\tMAKE_FIB_HEAP         :: c\n");
    printf("\t\t\tFIB_HEAP_UNION        :: u\n");
    printf("\t\t\tFIB_HEAP_INSERT       :: i\n");
    printf("\t\t\tDisplay_the_Heap                    :: s/S\n");
    printf("\t\t\tTurn off Print after extract min    :: -\n");
    printf("\t\t\tTurn on print after extract min     :: +\n");
    printf("\t\t\tFIB-HEAP-EXTRACT-MINIMUM            ::d\n");
    printf("\t\t\tQUIT                                ::q/Q\n");
    printf("Start entering your choices(c/i/S/-/+/d)::\n");
    
//The first input must be c as we are first creating empty heap before performing any other operation
     int i,m;
     int total=0;
     struct node* H=NULL;
     int l=0;
     int flag=0;
     char ch;
     int var1=0;
      do
      { 
         scanf("%c",&ch);
         switch(ch)
         {
        
           case 'c':        
              H =MAKE_FIB_HEAP();
              break;
              
           case 'i':          
              scanf("%d",&m);
              struct node* mvar=Create_node(m);
              H =FIB_HEAP_INSERT(H,mvar);
              total=total+1;
              break; 
              
           case 'd': 
               l=check(H);
               if(l!=0)           	
                 H=FIB_HEAP_EXTRACT_MINIMUM(H,&total,&flag);
               else
                 printf("Heap is empty\n");
               break;
               
           case '+':
               flag=1;
               break;
               
           case '-':
               flag=0;
               break;
               
           case 's':
           case 'S':
           //Root_List(column:01)
                 printf("Structure Of Fibonacci Heap(Rotated 90 Degree) is : \n\n");
                 DISPLAY(H,0,total);
                break;
                
           case 'q':
           case 'Q':
                var1=1;
          }
               
           if(l==1)
                {
                  break;
                }
                
      } while(var1!=1);
      
      return 0;
}


struct node* Consolidate(struct node *head,int total)
{
    int i,d;
    int m=0;
    struct variable *Array[1000];  
    for(i=0;i<1000;i++)
    {
        Array[i]=(struct variable*)malloc(sizeof(struct variable));       
        Array[i]->ptr=NULL;                                       
    }
    struct node *x=head;                         
    struct node *y;
    struct node *dummy;                           
    while(m!=1)
    {
        d=x->degree;                              
        while(Array[d]->ptr!=NULL)                  
        {
            y=Array[d]->ptr;                         
            if(y==x)
            {
                m=1;
                break;
            }
            if(x->key > y->key)
            {
                dummy=x;
                x=y;
                y=dummy;
            }
            x=HEAP_LINK(y,x,total);          
            Array[d]->ptr=NULL;         
            d=d+1;                  
        }
        Array[d]->ptr=x;              
        x=x->right;              
    }
    struct node *min=x;             
    struct node *var2=x;
    while(x->left!=var2)               
    {
        if(x->key <= min->key)       
             min=x;
        x=x->left;
    }
    if(x->key <= min->key)             
             min=x;
         
     return min;                   
}

int FIBONACCI_LINK(struct node* H1,struct node* y,struct node* z,int total)
{

    (y->left)->right = y->right;
    (y->right)->left = y->left;
    if (z->right == z)
        H1 = z;
    y->left = y;
    y->right = y;
    y->parent = z;
    if (z->child == NULL)
        z->child = y;
    y->right = z->child;
    y->left = (z->child)->left;
    ((z->child)->left)->right = y;
    (z->child)->left = y;

    if (y->key < (z->child)->key)
        z->child = y;
        
    z->degree++;
}

int Num_Nodes(struct node *head)               
{
	struct node *Temporary = head;
	int key=1;
	if(head == NULL)                             
    return 0;
    while(Temporary->right != head)                     
    {
        key++;
        Temporary = Temporary->right;
    }
	return key;
}

struct node* HEAP_LINK(struct node *head2,struct node *head1,int total)   
{
    int k;
    k=head1->degree;            
    head2->left->right=head2->right;   
    head2->right->left=head2->left;
    head2->left=head2;              
    head2->right=head2;
    head1=Create_Child(head1,head2,total);   
    head1->degree=k+1;      
    return head1;
}

struct node* Create_Child(struct node *head1, struct node *head2,int total)      
{
    head2->parent=head1;
    struct node *Temporary=head2->right;
    while(Temporary!=head2)                                                      
    {
        Temporary->parent=head1;
        Temporary=Temporary->right;
    }
    if(head1->child==NULL)                                 
    {
        head1->child=head2;

    }
    else
    {
        head1->child=FIB_HEAP_Union(head1->child,head2,total);         
    }
    int l=Num_Nodes(head2);
    int k=head1->degree;
    int r=k+l;
    head1->degree=r;
           
    return head1;
}

struct node* FIB_HEAP_EXTRACT_MINIMUM(struct node* head,int* total,int* flag)
{

        struct node* z=head;         
        if(z==NULL)                   
        {
            return head;
        }
        if(Num_Nodes(z)==1)              
        {   
          if((*flag)==1)    
            {
                printf("Minimum Extracted from the Fibonacci Heap is : %d\n",z->key);
            }
            
            head=z->child;
                     
            if(z->child!=NULL)       
            {
                struct node *Temporary=z->child->right;
                while(Temporary!=z->child)     
                {
                    Temporary->parent=NULL;
                    Temporary=Temporary->right;
                }
                head=Consolidate(head,*total);         
            }
            *total=0;
            return head;             
        }
        else         
        {   
            *total=(*total)-1;
            z->left->right=z->right;             
            z->right->left=z->left;
            if(z->child!=NULL)
            {
                struct node *Temporary=z->child->right;
                while(Temporary!=z->child)                   
                {
                    Temporary->parent=NULL;
                    Temporary=Temporary->right;
                }
                head=FIB_HEAP_Union(head->right,z->child,*total);     
            }
            head=z->right;              
            z->left=z;                  
            z->right=z;
            head=Consolidate(head,*total);     
        }

         if((*flag)==1)    
    {
        printf("Minimum Extracted from the Fibonacci Heap is : %d\n",z->key);
    }
    return head;
}

//Code For implementation of Fibonacci Heap

