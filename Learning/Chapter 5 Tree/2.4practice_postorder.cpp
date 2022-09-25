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

Status PostOrderTraverse(BiTree T)
{
    BiTree p = T, q, r = NULL; // r 储存最近访问的元素
    std::stack<BiNode*> s, t;
    while(p || !s.empty())
    {
        if(p) // 若 p 非空
        {
            s.push(p);
            p = p -> lchild;
        }
        else
        {
            p = s.top();
            q = p -> rchild;
            if(q && q != r) // 如果 p 有右子节点，且未被访问过
            {
                p = q;
                s.push(p);
                p = p -> lchild;
            }
            else // 如果 p 没有右子结点，或已被访问
            {
                visit(p);
                s.pop();
                r = p;
                p = NULL;
            }
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
    
    PostOrderTraverse(bt);

    return 0;
}
