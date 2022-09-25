#include <cstdio>
#include <cstdlib>

/*
ElemType 用来表示元素类型，可以具体修改
可以事先定义，作为模板
*/

typedef char ElemType;
const int MaxSize = 1000;

typedef struct
{
    // 数组的静态分配
    ElemType data[MaxSize];
    int length;
} SqList; 

typedef struct
{
    // 数组的动态分配
    ElemType *data;
    int length;
} SqListDynamic;

int main()
{
    // 动态分配的初始化
    SqListDynamic L, L_new;
    // malloc 申请堆空间 + 强制类型转换
    // sizeof(ElemType) * MaxSize 为申请空间大小（字节数）
    L.data = (ElemType*) malloc(sizeof(ElemType) * MaxSize);
    
    // C++ 的语法：new
    L.data = new ElemType[10];
}
