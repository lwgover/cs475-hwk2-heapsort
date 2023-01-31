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
 * reverses the order of an employee array
 * 
 * @param *A Pointer to the list of employees
 * @param start the index to start at
 * @param end the index to end at 
*/
void reverse(struct Employee *A, int start, int end){
	for(int i = 0; i < (end+1)/2; i++){
		swap(&A[i],&A[end-i]);
	}

}

/**
 * Sorts a list of n employees in descending order
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void heapSort(struct Employee *A, int n)
{
	buildHeap(A, n); // build the heap
	for(int i = n-1; i >=0; i--){ // from n-1 to 0
		swap(&A[0],&A[i]); // put the smallest at the end, protected
		heapify(&A[0],i); // build heap with smallest protected
	}
	reverse(&A[0],0,n-1); // reverse the list
}

/**
 * Given an array A[], we want to get A[] into min-heap property
 * We only need to run heapify() on internal nodes (there are floor(n/2) of them)
 * and we need to run it bottom up (top-down cannot build a heap)
 *
 * @param	*A	Pointer to the list of employees
 * @param	n	Size of the heap
 */
void buildHeap(struct Employee *A, int n)
{
	for(int i = n / 2; i >= 0; i--){  
		heapify(A,i,n); // heapify A[i]
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
void heapify(struct Employee *A, int i, int n)
{
	if (i >= n || left(i) >= n){ // stop recursion when i or children get out of bounds. Fixes segmentation fault issue I think
		return;
	}

	int smaller; // index of child with smaller salary
	if (left(i) < n && right(i) == n){ // when there's no right child
		smaller = left(i);
	}
	else if (A[left(i)].salary < A[right(i)].salary){ // determine which child is smaller
		smaller = left(i); 
	}
	else{
		smaller = right(i);
	}

	if (A[i].salary > A[smaller].salary){ // do i and smaller violate min heap property?
		swap(&A[i], &A[smaller]); // if so, swap the two
		heapify(A, smaller, n); // recursively push down A[smaller]
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
