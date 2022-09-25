/*
练习：前序遍历的非递归算法
*/

#include <iostream>
#include <stack>
#define OK 1

typedef char TElemType;
typedef int Status;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

auto visit = [](BiTree t) -> void
{
    std::cout << t -> data << std::endl;
};

Status PreOrderTraverse(BiTree T)
{
    BiTree p = T;
    std::stack<BiNode*> s;
    while(p || !s.empty())
    {
        if(p)
        {
            visit(p);
            s.push(p);
            p = p -> lchild;
        }
        else
        {
            // 进入右子树，该结点不会再用到，直接删除
            p = s.top() -> rchild;
            s.pop();
        }
    }
    return OK;
}

int main()
{
    // 构造一棵二叉树
    BiTree bt;
    BiNode root = {'A', NULL, NULL};
    bt = &root;
    BiNode node1 = {0, NULL, NULL}, node2 = {0, NULL, NULL}, node3 = {0, NULL, NULL};
    BiNode node4 = {0, NULL, NULL};
    root.lchild = &node1;
    node1.data = 'B';
    node1.lchild = &node4;
    node4.data = 'D';
    node1.rchild = &node2;
    node2.data = 'E';
    root.rchild = &node3;
    node3.data = 'C';
    

    PreOrderTraverse(bt);

    return 0;
}
