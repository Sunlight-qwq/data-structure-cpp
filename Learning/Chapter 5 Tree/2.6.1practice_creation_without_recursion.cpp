#include <iostream>
#include <stack>
#define OK 1

/*
参考：https://blog.csdn.net/sunnyoldman001/article/details/125883246
*/

typedef char TElemType;
typedef int Status;
const char NULLCHAR = '#';

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

Status BiTreeCreation(BiTree &T)
{
    /*
    步骤：1. 设置 flag，表示当前是否应处理右子树。
    2. 读入首结点，置空左右子结点指针
    3. 开始循环，读入新数据，分类讨论：
    3.1 若数据非空，且 flag 为 false，则当前结点入栈，新建结点链接到当前左子树，p 指针改链接；
    3.2 若数据非空，且 flag 为 true，则新建结点链接到当前右子树，flag 置为 false，p 指针改链接；
    3.3 若数据为空，且 flag 为 true，则：
    3.3.1 若栈为空，则 p 指向栈顶，弹栈，flag 保持为 true（表示处理弹出的右子树）；
    3.3.2 若栈为空，则循环结束；
    3.4 若数据为空，且 flag 为 false，则继续读入下一个数：
    3.4.1 继续读入的数为空：
    3.4.1.1 若栈非空，则栈顶元素出栈，flag 置为 true；
    3.4.1.2 若栈为空，则循环结束；
    3.4.2 继续读入的数非空，则新建结点链接到当前右子树，p 指针改链接。
    */
    BiTree p, q;
    std::stack<BiNode*> s; // 正在处理左子树的结点
    char ch = getchar();
    bool flag = false;
    if(ch == '#')
    {
        T = NULL;
        return OK;
    }
    T = new BiNode;
    T -> data = ch;
    T -> lchild = NULL;
    T -> rchild = NULL;
    p = T;
    bool continuecycle = true;
    while(continuecycle)
    {
        ch = getchar();
        switch((char) flag + ((ch == NULLCHAR) << 1))
        {
            case 0: // flag 为 false 且数据非空
            {
                s.push(p);
                q = new BiNode;
                q -> data = ch;
                q -> lchild = NULL;
                q -> rchild = NULL;
                p -> lchild = q;
                p = q;
                break;
            }
            case 1: // flag 为 true 且数据非空
            {
                q = new BiNode;
                q -> data = ch;
                q -> lchild = NULL;
                q -> rchild = NULL;
                p -> rchild = q;
                p = q;
                flag = false;
                break;
            }
            case 2: // flag 为 false 且数据为空
            {
                ch = getchar();
                if(ch == NULLCHAR)
                {
                    if(s.empty())
                    {
                        continuecycle = false;
                    }
                    else
                    {
                        flag = true;
                        p = s.top();
                        s.pop();
                    }
                }
                else
                {
                    q = new BiNode;
                    q -> data = ch;
                    q -> lchild = NULL;
                    q -> rchild = NULL;
                    p -> rchild = q;
                    p = q;
                }
                break;
            }
            case 3: // flag 为 true 且数据非空
            {
                if(s.empty())
                {
                    continuecycle = false;
                }
                else
                {
                    p = s.top();
                    s.pop();
                }
                break;
            }
        }
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
    BiTreeCreation(bt);
    PreOrderTraverse(bt);
    return 0;
}
