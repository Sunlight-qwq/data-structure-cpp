/*
顺序结构存储二叉树：

按满二叉树位置编号，空位置存特殊值（如 0）
*/

#include <cstdio>
#define MAXSIZE 100

typedef int TElemType;

typedef TElemType SqBiTree[MAXSIZE];

int main()
{
    // 顺序二叉树相当于数组
    SqBiTree bt;
    bt[0] = 1;
    bt[2] = 5;
    return 0;
}