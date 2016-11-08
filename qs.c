/**
 * timing based on the way pivot being selected.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocateArray(int n);

void swap(int *a, int *b);

void initializeArray(int *arr, int n);

void printArray(int *arr, int n, char *msg);

void randomizeArray(int *arr, int n);

int randWithRange(int start, int end);

int findSecondMax(int *arr,int left,int right);

int partition(int *arr, int left, int right);

void qs(int *arr, int left, int right);


int main(){
    int *arr;
    int n;

    clock_t begin, end;
    double time_spent;
    printf("\nProgram runs for selecting first element as pivot\n");
    printf("Enter the size of the array > ");
    scanf("%d", &n);

    arr = allocateArray(n);
    randomizeArray(arr,n);
    //printArray(arr,n, "Random array : ");
    begin = clock();
    qs(arr,0,n-1);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printArray(arr,n, "Sorted array : ");
    printf("\nTime spent for sorting randomized array : %f", time_spent);

    // timing for sorted array
    initializeArray(arr,n);

    begin = clock();
    qs(arr,0,n-1);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime spent for sorting sorted array : %f\n\n", time_spent);

    free(arr);

    return 0;
}

int* allocateArray(int n){
    int *arr = 0;

    arr = (int*) malloc( n * sizeof(*arr) );

    if ( arr == 0 ){
        printf("an error occured!!");
    }

    return arr;
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void initializeArray(int *arr, int n){
    int i=0;

    for( i=0; i<n; i++ ){
        arr[i] = i;
    }
}

void printArray(int *arr, int n, char *msg){
    int i=0;

    printf("\n%s\n", msg);
    for( i=0; i<n; i++ ){
        printf(" %d ", arr[i]);
    }
}

void randomizeArray(int *arr, int n){
    int i=0;

    srand(time(0)); // seeding the generator

    for( i=0; i<n; i++ ){
        arr[i] = rand();
    }
}

int randWithRange(int start, int end){
    int i = 0;

    i = rand() % (end-start) + start;

    return i;
}

int findSecondMax(int *arr,int left,int right){
    int middle = (left+right) / 2;
    int firstMax = left;
    int secondMax = middle;
    int thirdMax = right;

    if( arr[firstMax] < arr[secondMax] ){
        swap(&firstMax,&secondMax);
    }

    if( arr[firstMax] < arr[thirdMax] ){
        swap(&firstMax,&thirdMax);
    }

    if( arr[secondMax] > arr[thirdMax] ){
        return secondMax;
    }

    return thirdMax;

}

int partition(int *arr, int left, int right){
    int pivot=0;
    int i=0;
    int j=0;

    // first element as a pivot
    pivot = left;

    /* randomly selected element as a pivot
    int randIndex = randWithRange(left,right);
    swap(&arr[left], &arr[randIndex]);
    pivot = left;
    */

    /* second biggest of the first, middle, and last element as a pivot
    int SecondMaxPivotIndex = findSecondMax(arr,left,right);
    swap(&arr[left], &arr[SecondMaxPivotIndex]);
    pivot = left;
    */
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

    swap(&arr[i],&arr[j]);

    swap(&arr[pivot],&arr[j]);

    return j;
}

void qs(int *arr, int left, int right){
    int s;

    if( left < right ){
        s = partition(arr, left, right);
        qs(arr, left, s-1);
        qs(arr, s+1, right);
    }
}
