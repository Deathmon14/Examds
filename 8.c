#include <stdio.h>
int binarySearch(int arr[], int low, int high, int key) {
 if (low > high) {
 return -1;
 }
 int mid = (low + high) / 2;
 if (arr[mid] == key) {
 return mid;
 } else if (arr[mid] > key) {
 return binarySearch(arr, low, mid - 1, key);
 } else {
 return binarySearch(arr, mid + 1, high, key);
 }
}
int main() {
 int n = 5;
 int arr[50];
 printf("Enter the values in sorted order \n");
 for(int i=0;i<n;i++){
 scanf("%d",&arr[i]);
 }
 int key = 4;
 int result = binarySearch(arr, 0, n-1, key);
 if (result == -1) {
 printf("Element not found\n");
 } else {
 printf("Element found at index %d\n", result);
 }
 return 0;
}
/*#include <stdio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
 if (n == 1){
 printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
 return;
 }
 towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
 printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
 towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main(){
 int n = 4; // Number of disks
 towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
 return 0;
}*/