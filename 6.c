#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
int isOperator(char ch) {
 return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int getPrecedence(char ch) {
 if (ch == '+' || ch == '-')
 return 1;
 else if (ch == '*' || ch == '/')
 return 2;
 else
 return 0; // for '(' and ')'
}
void infixToPostfix(char *infix, char *postfix) {
 char stack[MAX_SIZE];
 int top = -1;
 int i, j;
 for (i = 0, j = 0; infix[i] != '\0'; ++i) {
 char currentChar = infix[i];
 if (isalnum(currentChar)) {
 postfix[j++] = currentChar;
 } else if (currentChar == '(') {
 stack[++top] = currentChar;
 } else if (currentChar == ')') {
 while (top != -1 && stack[top] != '(') {
 postfix[j++] = stack[top--];
 }
 if (top != -1 && stack[top] == '(') {
 top--; // Discard the '('
 }
 } else if (isOperator(currentChar)) {
 while (top != -1 && getPrecedence(stack[top]) >= getPrecedence(currentChar)) {
 postfix[j++] = stack[top--];
 }
 stack[++top] = currentChar;
 }
 }
 while (top != -1) {
 postfix[j++] = stack[top--];
 }
 postfix[j] = '\0'; // Null-terminate the postfix expression
}
int main() {
 char infix[MAX_SIZE], postfix[MAX_SIZE];
 printf("Enter infix expression: ");
 scanf("%s", infix);
 infixToPostfix(infix, postfix);
 printf("Postfix expression: %s\n", postfix);
 return 0;
}