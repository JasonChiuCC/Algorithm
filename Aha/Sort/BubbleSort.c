/*
問題: 
排序 12,35,99,18,76 由小排到大

算法模型:
每次比較兩個相鄰的元素，如果它們的順序錯誤就把它們交換過來

缺點:
O(n^2) 太高,執行效率差
input 數量大時,桶排序還比較快(但耗空間)

優點:
解決一些桶排序無法解決的問題
1. 小數點
2. 範圍太大會浪費空間的問題
*/
int main()
{

    int i = 0;
    int j = 0;
    int input[5]    = {12,35,99,18,76};
    int inputLen    = (sizeof(input)/sizeof(int));
    int countTime   = inputLen-1;

    for( i = 0; i < inputLen; i++ )
    {
        for( j = 0; j < countTime; j++ )
        {
            if(input[j] < input[j+1] )
            {
                int tmp     = input[j+1];
                input[j+1]  = input[j];
                input[j]    = tmp;
            }
        }
        countTime--;
    }

    for( i = 0; i < (sizeof(input)/sizeof(int)); i++ )
    {
        printf("%d ",input[i]);
    }
