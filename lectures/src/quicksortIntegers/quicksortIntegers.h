/************************************************************************/
/*                                                                      */
/* Interface file for QuickSort of an array of integers                 */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 29/1/2019                                                            */
/*                                                                      */
/************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define ARRAY_SIZE 100
#define FALSE 0
#define TRUE  1

/*** simple quick sort ***/
int quicksort(int a[], int l, int r); 

/*** exchange two integers ***/
int exchange_int(int a[], int i, int j); 

/*** print a list ***/
int print_list_int(int a[], int l, int r);  