/*
二分搜尋法 - Binary Search
資料要先排序

例如: 1,2,3,4,5,6,7，找 5
1. 1 2 3 [4] 5 6 7
2. 1 2 3 4 | 5 [6] 7
3. 1 2 3 4 | [5] 6 7

*/
#define JC_A_LEN( array, typeOfArray)          (sizeof(array) / sizeof(typeOfArray))
int BinarySearch(int data[], int search, int len)
{
    int low     = 0;
    int high    = len - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (data[mid] == search)
        {
            return mid;
        }
        else if (data[mid] > search)
        {
            high = mid - 1;
        }
        else if (data[mid] < search)
        {
            low = mid + 1;
        }
    }

    return -1;
}
int main(void)
{
    int ans     = 0;
    int s1      = 3;
    int d1[]    = {1};

    int s2      = 4;
    int d2[]    = {1,2,4};

    int s3      = 57;
    int d3[]    = {3, 7, 14, 20, 23, 32, 41, 44, 56, 57, 73, 89, 93};

    ans = BinarySearch(d1, s1, JC_A_LEN(d1,int) );
    printf("Pos:%d\n", (ans < 0) ? -1 : ans);

    ans = BinarySearch(d2, s2, JC_A_LEN(d2,int) );
    printf("Pos:%d\n", (ans < 0) ? -1 : ans);

    ans = BinarySearch(d3, s3, JC_A_LEN(d3,int) );
    printf("Pos:%d\n", (ans < 0) ? -1 : ans);

}
