/*
 * heapsort.c
 *
 *  Created on: Jan 29, 2023
 *      Author: lgover
 */
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "heap.h"

/**
 * Gets the index of the left child of a given index
 * 
 * @param i index you want the left child of
 * @return the index of the left child
*/
int left(int i){
	return i*2 + 1;
}
/**
 * Gets the index of the right child of a given index
 * 
 * @param i index you want the right child of
 * @return the index of the right child
*/
int right(int i){
	return i*2 + 2;
}

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(Employee *A, int n)
{
	// BuildHeap on the heap
	printf("hi");
	buildHeap(&A[0],n);

	int m = n;
	while (m > 0){
		//swap A[n-1] with A[0], since A[0] is the smallest number.
		swap(&A[n-1],&A[0]);
		m--;
		heapify(&A[0],0,m);
	// TODO - A[n-1] now sorted in place, so decrement n
	// TODO - Heapify the elements from A[0] up to A[n-1] (which leaves the newly sorted element alone)
	}
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(Employee *A, int n)
{
	// heapify() every element from A[n/2] down-to A[0]
	for(int i = n/2; i >= 0; i--){
		heapify(&A[0],i,n);
	}
}

/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
/**
 * We want to start with A[i] and percolate it downward
 * if it is greater than either left or right child.
 *
 * @param	*A	Pointer to the list of employees
 * @param	i	Index of current element to heapify
 * @param	n	Size of the heap
 */
void heapify(Employee *A, int i, int n)
{
	// Determine which child has a smaller salary. We'll call the index of this
	// element: "smaller"
	int smaller;
	if (right(i) < n && A[right(i)].salary < A[left(i)].salary){
		smaller = right(i);
	}else{
		smaller = left(i);
	}

	// Recursively check if the salary at A[i] > the salary at A[smaller]. If it is, swap the two.
	// Then recursively heapify A[smaller].
	if (i < n && A[i].salary > A[smaller].salary) {
		Employee temp = A[i];
		A[i] = A[smaller];
		A[smaller] = temp;
		heapify(A, smaller, n);
	}
}

/**
 * Swaps the locations of two Employees
 * @param *e1 An Employee
 * @param *e2 Another Employee to swap with
 */
void swap(Employee *e1, Employee *e2){
	// Store e1's data in a temp struct
    Employee temp = *e1;
    // Copy e2's data into e1
    *e1 = *e2;
    // Copy temp (e1's original data) into e2
    *e2 = temp;
}

/**
 * Outputs an array of Employees
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the list
 */
void printList(Employee *A, int n)
{
	for(int i = 0; i < n-1; i++){
		printf("[id=%s sal=%u], ",A[i].name,A[i].salary);
	}
	printf("[id=%s sal=%u]\n",A[n-1].name,A[n-1].salary);
}
