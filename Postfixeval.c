#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 100
// char stack[max];
int top=-1;
void push(int ele)
{
if(top>=max-1)
{
printf("the stack is full");
}
else{
stack[++top]=ele;
}
}
char pop()
{
if(top<0)
{
printf("the stack is empty");
}
else{
return stack[top--];
}
}
int evalpostfix(char* postfix)
{
char op;int i=0;
while((op=postfix[i++])!='\0')
{
if(isdigit(op))
{
push(op-'0');
}
else{
int op2=pop();
int op1=pop();
switch(op)
{
case '+':push(op1+op2);
break;
case '-':push(op1-op2);
break;
case '*':push(op1*op2);
break;
case '/':
if(op2!=0)
push(op1/op2);
break;
case '^':push(op1^op2);
break;
case '%':push(op1%op2);
break;
default:
printf("invalid choice\n");
return 0;
}
}
}
return pop();
}
int main()
{
char postfix[max];
printf("enter the postfix expression\n");
scanf("%s",postfix);
int res=evalpostfix(postfix);
printf("value is:%d\n",res);
return 0;
}





