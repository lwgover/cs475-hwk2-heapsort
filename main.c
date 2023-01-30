#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

#define MAX_EMPLOYEES 5

//removes the annoying new line character from the fgets input
void removeNewLine(char str[]){
	str[strlen(str)-1] = '\0';
}

/**
 * Gets an employee from user
 * 
*/
Employee employee_input(){
	printf("Enter an employee name: ");
	Employee e;
	fgets(e.name,MAX_NAME_LEN,stdin);
	removeNewLine(e.name); // removes annoying new line
	char input[10];
	printf("Enter an employee salary: ");
	fgets(input,10,stdin);
	e.salary = atoi(input); // string to int
	return e;
}

int main(int argc, char *argv[]){
	struct Employee E[MAX_EMPLOYEES];
	for(int i = 0; i < MAX_EMPLOYEES; i++){
		E[i] = employee_input();
	}
	printf("before: ");
	printList(&E[0],MAX_EMPLOYEES);
	heapSort(&E[0],MAX_EMPLOYEES);
	printf("after: ");
	printList(&E[0],MAX_EMPLOYEES);
}
