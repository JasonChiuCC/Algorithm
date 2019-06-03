#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_ELEMENT 7
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

void Combine(int* array, int* tmpAry, int Low, int Mid, int Hight)
{
    printf("C : Low = %d Mid = %d Hight = %d\n", Low, Mid, Hight);
    //print_array(array, 0 , NUMBER_OF_ELEMENT-1);
    int tmpAryIdx       = 0;
    int AryIdx          = Low;    
    int LeftCurrent     = Low;
    int RightCurrent    = Mid+1;
    
    // 依序比較 Left & Right Array 中把最小值 Copy 到 TmpArray
    while(  LeftCurrent  < Mid+1 && 
            RightCurrent < Hight+1 )
    {
        if( array[RightCurrent] <= array[LeftCurrent] )
        {
            tmpAry[tmpAryIdx++] = array[RightCurrent++];
        }
        else
        {
            tmpAry[tmpAryIdx++] = array[LeftCurrent++];
        }
    }    
    
    // Copy 剩下的 Left or Right Array 到 TmpAry
    while( RightCurrent < Hight+1 )
    {        
        tmpAry[tmpAryIdx++] = array[RightCurrent++];
    }
    while( LeftCurrent < Mid+1 )
    {        
        tmpAry[tmpAryIdx++] = array[LeftCurrent++];
    }

    // 把 tmpAry 中的值 assign 給 array 
    for(int idx = 0; idx < tmpAryIdx; idx++)
    {
        array[AryIdx++] = tmpAry[idx];
    }
    //print_array(array, 0 , NUMBER_OF_ELEMENT-1);
}

void MergeSort(int* array, int* tmpAry, int Low, int Hight)
{
    printf("M : Low = %d Hight = %d\n", Low, Hight);
    if( Low < Hight)
    {
        int Mid = Low + (Hight - Low)/2;
        MergeSort(array, tmpAry, Low,  Mid);
        MergeSort(array, tmpAry, Mid+1,Hight);
        Combine(array,  tmpAry, Low, Mid, Hight);        
    }
}

int main() {
	//int i;
    //int num[NUMBER_OF_ELEMENT]; 
	//for (int i = 0; i < NUMBER_OF_ELEMENT; i++ ) {
	//	num[i] = rand();
	//}
    
    //int num[]   = {10, 7, 12, 8, 3, 2, 6, 10};
    int num[]   = {4, 0, 6, 1, 5, 2, 3};           
    int numLen  = sizeof(num)/sizeof(int);
    int *tmpAry = malloc( numLen * sizeof(int) );
    print_array(num, 0 , numLen-1);
    MergeSort(num, tmpAry, 0, numLen-1);    
    print_array(num, 0 , numLen-1);    
    //Combine(num, 4, 4, 5);
}
