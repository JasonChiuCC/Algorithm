#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_ELEMENT 6
void print_array(int x[], unsigned int p, unsigned int q) {
	unsigned int i;
	printf("array[%d..%d]: ", p, q);
	for(i = p; i <= q; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a      = *b;
    *b      = tmp;
}

int partition(int* array, int start, int end, int pivotLoc)
{
    int border  = 0;
    int current = 0;        
    int pivot   = array[pivotLoc];
    
    /* Set border = start */
    border = start;
    
    /* First swap pivot to array End Loction */
    swap(&array[pivotLoc], &array[end]);
    
    /* Find Border, Let Border left <= pivot and Border right > pivot */
    for( current = start; current < end; current++ )
    {
        if( array[current] <= pivot )
        {
            swap(&array[current], &array[border]);
            border++;
        }            
    }
    
    /* Swap pivot to Border */
    swap(&array[end], &array[border]);
    return border;
}

void QuickSort(int* array, int start, int end)
{
    /* Pick pivot Loction */
    int pivotLoc = end;
    
    if( start < end )
    {
        int r = partition(array, start, end, pivotLoc);    
        /* Pivot Left */
        if( r > start )
        {
            QuickSort(array, start, r-1);
        }
        
        /* Pivot Right */
        QuickSort(array, r+1, end);
    }
}

int main() {
	//int i;
    /*
	for ( i = 0; i < NUMBER_OF_ELEMENT; i++ ) {
		numbers[i] = rand()%10;
	}
    */
    int num[]   = {10, 7, 12, 8, 3, 2, 6, 10};
    int numLen  = sizeof(num)/sizeof(int);
    print_array(num, 0 , numLen-1);
    QuickSort(num, 0, numLen-1);    
    print_array(num, 0 , numLen-1);    
}
