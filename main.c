#include <stdio.h>
#include <string.h>
#include "employee.h"
#include "heap.h"

int main(int argc, char *argv[])
{
	//TODO
	Employee E[5];
	strcpy(E[0].name,"1");
	strcpy(E[1].name,"2");
	strcpy(E[2].name,"3");
	strcpy(E[3].name,"4");
	strcpy(E[4].name,"5");

	E[0].salary = 5;
	E[1].salary = 4;
	E[2].salary = 3;
	E[3].salary = 2;
	E[4].salary = 1;

	swap(&E[0],&E[1]);
	printf("hi");
	//heapSort(&E[0],5);
	printList(&E[0],5);

	
	return 0;
}
