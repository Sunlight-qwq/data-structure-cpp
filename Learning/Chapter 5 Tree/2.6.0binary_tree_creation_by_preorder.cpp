/*
给出一个二叉树的先序序列，建立二叉树

例如：ABC##DE#G##F###，“#”表示空结点，当一个结点的两个
*/

#include <iostream>
#include <stack>
#define OK 1
#define OVERFLOW 3


typedef char TElemType;
typedef int Status;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

Status CreateBiTree(BiTree &T)
{
    char ch = getchar();
    if(ch == '#') T = NULL;
    else
    {
        T = (BiTree) malloc(sizeof(BiNode)); // 申请空间，注意溢出
        if(!T) exit(OVERFLOW);
        T -> data = ch;
        CreateBiTree(T -> lchild);
        CreateBiTree(T -> rchild);
    }
    return OK;
}

Status PreOrderTraverse(BiTree T)
{
    std::stack<BiNode*> s;
    BiTree p = T;
    while(p || !s.empty())
    {
        if(p)
        {
            printf("%c", p -> data);
            s.push(p);
            p = p -> lchild;
        }
        else
        {
            p = s.top() -> rchild;
            s.pop();
        }
    }
    return OK;
}

int main()
{
    BiTree bt;
    CreateBiTree(bt);
    PreOrderTraverse(bt);
    return 0;
}