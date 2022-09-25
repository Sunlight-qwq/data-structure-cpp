/*
先序遍历二叉树

基本方法：若二叉树为空，则跳过（空操作）；
若二叉树非空，则访问根节点、遍历左子树、遍历右子树（递归）。
*/

#include <iostream>
#define OK 1
#define ERROR 2

typedef int TElemType;
typedef int Status;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

// 匿名访问函数
auto visit = [](BiTree bt) -> void
{
    std::cout << bt -> data << std::endl;
};

Status PreOrderTraverse(BiTree T)
{
    if(T != NULL)
    {
        visit(T);
        PreOrderTraverse(T -> lchild);
        PreOrderTraverse(T -> rchild);
    }
    return OK;
}

int main()
{
    // 构造一棵二叉树
    BiTree bt;
    BiNode root = {0, NULL, NULL};
    bt = &root;
    BiNode node1 = {0, NULL, NULL}, node2 = {0, NULL, NULL}, node3 = {0, NULL, NULL};
    root.lchild = &node1;
    node1.data = 1;
    node1.rchild = &node2;
    node2.data = 2;
    root.rchild = &node3;
    node3.data = 3;

    PreOrderTraverse(bt);

    return 0;
}