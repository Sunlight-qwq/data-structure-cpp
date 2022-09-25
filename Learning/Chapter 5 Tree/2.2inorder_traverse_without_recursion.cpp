/*
先序遍历二叉树

基本方法：若二叉树为空，则跳过（空操作）；
若二叉树非空，则访问根节点、遍历左子树、遍历右子树（递归）。
*/

#include <iostream>
#include <stack>
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
    // 遇到子树先存储不能访问，第二次才访问
    // 思想：建栈，根结点入栈，访问左子树，根结点出栈，访问右子树
    std::stack<BiNode*> s;
    BiTree p, q;
    p = T;
    while(p || !s.empty())
    {
        if(p) // 若 p 不为空
        {
            // 第一次访问，入栈
            s.push(p);
            p = p -> lchild;
        }
        else
        {
            q = s.top();
            s.pop();
            visit(q);
            p = q -> rchild;
        }
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