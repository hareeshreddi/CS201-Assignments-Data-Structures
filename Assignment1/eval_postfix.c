//Evaluation of Postfix expression by stack in C
#include <stdio.h>
#include <ctype.h>
#define SIZE 50 /* Size of Stack */

int s[SIZE];
int top=-1; /* Global declarations */
int flag=0;
int pop()
{                      /* Function for POP operation */
  return(s[top--]);
}

void push(int elem)
{ /* Function for PUSH operation */
  if(flag==1){
    int num;
    num=pop();
    s[++top]=elem+10*num;
  }
  else if(flag==0){
    s[++top]=elem;
    flag=1;
  }

}
int main()
{                         /* Main Program */
  char pofx[50],ch;
  int i=0,op1,op2;
  printf("Enter the Postfix Expression:");
  fgets(pofx,100,stdin);
  while( (ch=pofx[i++]) != '\n')
  {
    if(isdigit(ch)) push(ch-'0'); /* Push the operand */
    else if(ch==' ')
      flag=0;
    else
    {        /* Operator,pop two  operands */
      flag=0;
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':push(op1+op2);break;
        case '-':push(op1-op2);break;
        case '*':push(op1*op2);break;
        case '/':push(op1/op2);break;
        default:
                 printf("Input invalid ... give proper input\n");
                 return 0;
      }
    }
  }
  printf("Result: %d\n",s[top]);
  return 0;
}
