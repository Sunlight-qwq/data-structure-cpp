#include <iostream>

int main()
{
    int nrow, ncol;
    scanf("%d %d", &nrow, &ncol);
    
    int **a = new int*[nrow]; // 连续的指针
    a[0] = new int[nrow * ncol]; // 申请连续内存
    for(int i = 1; i < nrow; i++)
    {
        a[i] = a[i - 1] + ncol; // 定义各行的头指针
    }

    for(int i = 0; i < nrow; i++) for(int j = 0; j < ncol; j++)
    {
        scanf("%d", &a[i][j]);
    }

    return 0;
}