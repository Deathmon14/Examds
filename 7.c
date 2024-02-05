#include<stdio.h>
#include <ctype.h>
#include<math.h>
void push(float);
float pop();
void evaluate(char[]);
float stack[20];
int top=-1;
void main() {
 char postfix[100];
 printf("enter valid postfix expression\n");
 scanf("%s", postfix);
 evaluate(postfix);
}
void push(float item) {
 top++;
 stack[top]=item;
}
float pop() {
 return stack[top--];
}
void evaluate(char postfix[100]) {
 int i;
 float opl, op2, res;
 char symbol;
 for (i=0; postfix[i]!='\0'; i++) {
 symbol=postfix[i];
 if (isdigit(symbol)) {
 push(symbol-'0');
 }
 else {
 switch(symbol) {
 case '+':
 op2=pop();
 opl=pop();
 res=opl+op2;
 push(res);
 break;
 case '-':
 op2=pop();
 opl=pop();
 res=opl-op2;
 push(res);
 break;
 case '*':
 op2=pop();
 opl=pop();
 res=opl*op2;
 push(res);
 break;
 case '/':
 op2=pop();
 opl=pop();
 if (op2==0) {
 printf("Division by zero error\n");
 return;
 }
 res=opl/op2;
 push(res);
 break;
 case '%':
 op2=pop();
 opl=pop();
 if (op2==0) {
 printf("Division by zero error\n");
 return;
 }
 res=(int)opl%(int)op2;
 push(res);
 break;
 case '^':
 op2=pop();
 opl=pop();
 res=pow(opl,op2);
 push(res);
 break;
 }
 }
 }
 res = pop();
 if(top==-1){
 printf("\n result is %.2f\n",res);
 } 
 else {
 printf("\n invalid expression\n");
 top=-1;
 }}