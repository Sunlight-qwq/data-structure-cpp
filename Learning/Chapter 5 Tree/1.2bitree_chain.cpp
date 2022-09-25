#include <cstdio>

typedef int TElemType;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

// 三叉链表：需要找前驱时使用
typedef struct TriTNode {
    TElemType data;
    TriTNode *lchild, *rchild, *parent;
} TriTNode, *TriTree;

int main()
{
    BiTree bt;
    BiNode root = {0, NULL, NULL};
    bt = &root;
    bt -> data = 2;

    TriTree tbt;
    TriTNode troot = {0, NULL, NULL, NULL};
    tbt = &troot;
    tbt -> data = 1;

    return 0;
}
