#include <iostream>

// C++ 给函数传参，有三种类型
// 传值，传指针，传引用

void swap(int *m, int *n)
{
    int temp = *m; // 传入指针，需要解引用
    *m = *n;
    *n = temp;
}

// 传入引用，可以修改原值
void swap2(int &m, int &n)
{
    int temp = m;
    m = n;
    n = temp;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;
    swap2(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}