#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct EMPLOYEE {
 char Emp_name[50];
 int Emp_id;
 char Dept_name[50];
 float Salary;
};
float totalSalaryByDepartment(struct EMPLOYEE *employees, int numEmployees, const char 
*department) {
 float totalSalary = 0.0;
 for (int i = 0; i < numEmployees; ++i) {
 if (strcmp(employees[i].Dept_name, department) == 0) {
 totalSalary += employees[i].Salary;
 }
 }
 return totalSalary;
}
int main() {
 int N;
 printf("Enter the number of employees: ");
 scanf("%d", &N);
 struct EMPLOYEE *employees = (struct EMPLOYEE *)malloc(N * sizeof(struct EMPLOYEE));
 for (int i = 0; i < N; ++i) {
 printf("\nEnter details for employee %d:\n", i + 1);
 printf("Employee Name: ");
 scanf("%s", employees[i].Emp_name);
 printf("Employee ID: ");
 scanf("%d", &employees[i].Emp_id);
 printf("Department Name: ");
 scanf("%s", employees[i].Dept_name);
 printf("Salary: ");
 scanf("%f", &employees[i].Salary);
 }
 printf("\nEmployee Data:\n");
 for (int i = 0; i < N; ++i) {
 printf("Employee %d\n", i + 1);
 printf("Name: %s\n", employees[i].Emp_name);
 printf("ID: %d\n", employees[i].Emp_id);
 printf("Department: %s\n", employees[i].Dept_name);
 printf("Salary: %.2f\n\n", employees[i].Salary);
 }
 char searchDepartment[50];
 printf("Enter the department name to find total salary: ");
 scanf("%s", searchDepartment);
 float totalSalary = totalSalaryByDepartment(employees, N, searchDepartment);
 printf("\nTotal Salary for %s department: %.2f\n", searchDepartment, totalSalary);
 free(employees);
 return 0;
}