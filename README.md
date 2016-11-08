# Quicksort implementation 
QS algorithm is implemented in three different ways of selecting a pivot:

* first element as a pivot(firstqs.c)
* randomly selected element as a pivot(secondqs.c)
* second biggest of the first, middle, and last element as a pivot(thirdqs.c)

So timing can be observed based on pivot position. In qs.c file all the three
ways are included. In order to run one of them pivot selection part should be
modified. 

```c
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
```

Of course I could think of taking it as an argument to decide which way is going
be used.
