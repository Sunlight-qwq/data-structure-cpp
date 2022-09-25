/*
层次遍历：用队列实现即可。
每次将队头输出，并将其子结点入队。
*/

#include <iostream>
#include <queue>
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

Status LevelOrderTraverse(BiTree T)
{
    std::queue<BiNode*> qu;
    BiTree p = T;
    qu.push(p);
    while(!qu.empty()) // 队列非空时，循环
    {
        p = qu.front();
        qu.pop();
        visit(p);
        if(p -> lchild) qu.push(p -> lchild);
        if(p -> rchild) qu.push(p -> rchild);
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
    
    LevelOrderTraverse(bt);

    return 0;
}