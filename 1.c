#include <stdio.h> 
#include <stdlib.h> 
int main() {
int i; 
int count; 
int *arr; 
int sum = 0; 
printf("Enter the total number of elements you want to enter : "); 
scanf("%d", &count); 
arr = (int *)malloc(count * sizeof(int)); 
for (i = 0; i < count; i++) {
printf("Enter element %d : ", (i + 1)); 
scanf("%d", arr + i); 
sum += *(arr + i); 
} printf("sum of %d numbers is %d \n", count, sum); 
free(arr); 
return 0; 
}
/*#include <stdio.h>
int main() {
 int rows, cols;
 printf("Enter the number of rows: ");
 scanf("%d", &rows);
 printf("Enter the number of columns: ");
 scanf("%d", &cols);
 int matrix[rows][cols];
 printf("Enter the matrix elements:\n");
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 printf("Enter element at position (%d, %d): ", i + 1, j + 1);
 scanf("%d", &matrix[i][j]);
 } }
 int sumPrincipalDiagonal = 0;
 for (int i = 0; i < rows && i < cols; i++) {
 sumPrincipalDiagonal += matrix[i][i];
 }
 printf("Sum of principal diagonal elements: %d\n", sumPrincipalDiagonal);
 int sumSecondaryDiagonal = 0;
 for (int i = 0; i < rows && i < cols; i++) {
 sumSecondaryDiagonal += matrix[i][cols - 1 - i]; }
 printf("Sum of secondary diagonal elements: %d\n", sumSecondaryDiagonal);
 int sumAllElements = 0;
 for (int i = 0; i < rows; i++) {
 for (int j = 0; j < cols; j++) {
 sumAllElements += matrix[i][j]; }
 }
 printf("Sum of all elements in the matrix: %d\n", sumAllElements);
 return 0;}
*/