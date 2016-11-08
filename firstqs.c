/*
 * first element as a pivot(firstqs.c)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// defined globally to be able to print the whole array in qs function for debugging
// could be passed as a parameter, used global variable for easiness because whole program works on one array
int n; // size of an array

int* allocateArray(int n); // allocates memory for an integer array having n elements

void swap(int *a, int *b); // swaps given two parameters

void printArray(int *arr, int n, char *msg); // prints the array with given message

void randomizeArray(int *arr, int n); // populates the given array with random integers smaller than 1000

int partition(int *arr, int left, int right);

void qs(int *arr, int left, int right);

int main(){
    int *arr;

    printf("\n\n Quick Sort implementation selecting the first element of the array as pivot.");

    printf("\n\n Enter the size of the array > ");
    scanf("%d", &n);

    arr = allocateArray(n);
    randomizeArray(arr,n);
    printArray(arr,n,"Array created with random numbers :");

    qs(arr,0,n-1);
    printArray(arr,n, "Sorted Array : ");

    qs(arr,0,n-1);
    printArray(arr,n, "Sorted Array : ");

    free(arr);

    return 0;
}

int* allocateArray(int n){
    int *arr = 0;

    arr = (int*) malloc( n * sizeof(*arr) );

    if ( arr == 0 ){
        printf("an error occurred!!");
    }

    return arr;
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int n, char *msg){
    int i=0;

    printf("\n\n%s\n", msg);
    for( i=0; i<n; i++ ){
        printf(" %d ", arr[i]);
    }
}

void randomizeArray(int *arr, int n){
    int i=0;

    srand(time(0)); // seeding the generator

    for( i=0; i<n; i++ ){
        arr[i] = rand() % 1000;
    }
}

int partition(int *arr, int left, int right){
    int pivot=0;
    int i=0;
    int j=0;

    // select the first element as pivot
    pivot = left;
    printf("\nDEBUG > selected current pivot : %d", arr[pivot]);

    i = left;
    j = right+1;

    do {

        do{
            ++i;
        }while(i<j && arr[i]<=arr[pivot]);

        do{
            --j;
        }while(arr[j]>arr[pivot]);

        swap(&arr[i],&arr[j]);
    }while( i<j );

    // undoing the last unnecessary swap
    swap(&arr[i],&arr[j]);

    // putting the pivot in the position that it will have when the array is finally sorted
    swap(&arr[pivot],&arr[j]);

    return j;
}

void qs(int *arr, int left, int right){
    int s=0;

    if( left < right ){
        printArray(arr,n,"DEBUG > the current order of the elements :");
        printf("\nDEBUG > left : %d, right : %d", left,right);
        s = partition(arr, left, right);
        printf("\nDEBUG > s value returned from partition function : %d", s);
        qs(arr, left, s-1);
        qs(arr, s+1, right);
    }
}

