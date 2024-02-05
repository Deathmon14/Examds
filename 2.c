#include <stdio.h>
void multiplyMatrices(int *a, int *b, int *result, int rows1, int cols1, int rows2, int cols2) {
 for (int i = 0; i < rows1; ++i) {
 for (int j = 0; j < cols2; ++j) {
 *(result + i * cols2 + j) = 0;
 for (int k = 0; k < cols1; ++k) {
 *(result + i * cols2 + j) += *(a + i * cols1 + k) * *(b + k * cols2 + j);
 }
 }
 }
}
void displayMatrix(int *matrix, int rows, int cols) {
 for (int i = 0; i < rows; ++i) {
 for (int j = 0; j < cols; ++j) {
 printf("%d\t", *(matrix + i * cols + j));
 }
 printf("\n");
 }
}
int main() {
 int rows1, cols1, rows2, cols2;
 printf("Enter the number of rows and columns for matrix A: ");
 scanf("%d %d", &rows1, &cols1);
 printf("Enter the number of rows and columns for matrix B: ");
 scanf("%d %d", &rows2, &cols2);
 if (cols1 != rows2) {
 printf("Matrix multiplication not possible. Number of columns in matrix A must be equal to  the number of rows in matrix B.\n");
 return 1;
 }
 int A[rows1][cols1], B[rows2][cols2], result[rows1][cols2];
 printf("Enter elements of matrix A:\n");
 for (int i = 0; i < rows1; ++i) {
 for (int j = 0; j < cols1; ++j) {
 printf("Enter element at position (%d, %d): ", i + 1, j + 1);
 scanf("%d", &A[i][j]);
 }
 }
 printf("Enter elements of matrix B:\n");
 for (int i = 0; i < rows2; ++i) {
 for (int j = 0; j < cols2; ++j) {
 printf("Enter element at position (%d, %d): ", i + 1, j + 1);
 scanf("%d", &B[i][j]);
 }
 }
 multiplyMatrices(&A[0][0], &B[0][0], &result[0][0], rows1, cols1, rows2, cols2);
 printf("\nResultant Matrix:\n");
 displayMatrix(&result[0][0], rows1, cols2);
 return 0;
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reorder(char *arr[], int n) {
 int i, j;
 char *temp;
 for (i = 0; i < n; i++) {
 for (j = i + 1; j < n; j++) {
 if (strcmp(arr[i], arr[j]) > 0) {
 temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 }
}
int main() {
 int N;
 printf("Enter the number of names: ");
 scanf("%d", &N);
 char **arr = (char **)malloc(N * sizeof(char *));
 for (int i = 0; i < N; ++i) {
 arr[i] = (char *)malloc(100 * sizeof(char));
 printf("Enter name %d: ", i + 1);
 scanf("%s", arr[i]);
 }
 reorder(arr, N);
 printf("\nSorted names:\n");
 for (int i = 0; i < N; ++i) {
 printf("%s\n", arr[i]);
 }
 for (int i = 0; i < N; ++i) {
 free(arr[i]);
 }
 free(arr);
 return 0;
}*/