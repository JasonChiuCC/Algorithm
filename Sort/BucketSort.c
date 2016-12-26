/*
問題: 
班上只有 5 個同學，這 5 個同學分別考了 5分，3分，5分，2分，8分（滿分是10分）
接下來將分數進行從大到小排序，排序後是 8 5 5 3 2

算法模型:
桶排序假設待排序的一組數統一的分佈在一個範圍中(都在 0 ~ 10 分支中 )
並將這一範圍劃分成幾個子範圍，也就是桶 ( 可以分為 0 分 1 分 ... 10 分個桶子)

結論:
每個桶就是標示每個數出現的次數

作者: E.J.Issac , R.C.Singleton 
*/
int main()
{
    int i = 0;
    int j = 0;
    int input[5]    = {5,3,5,2,8};
    int result[11]  = {0};

    for( i = 0; i < (sizeof(input)/sizeof(int)); i++ )
    {
        result[ input[i] ]++;
    }

    // 由小到大
    for( i = 0; i < (sizeof(result)/sizeof(int)); i++ )
    {
        if( result[i]==0 ) continue;
        for( j = 0; j < result[i]; j++ )
        {
            printf("%d ",i);
        }
    }
    printf("\n");

    // 由大到小
    for( i = (sizeof(result)/sizeof(int))-1 ; i >= 0 ; i-- )
    {
        if( result[i]==0 ) continue;
        for( j = 0; j < result[i]; j++ )
        {
            printf("%d ",i);
        }
    }
}
