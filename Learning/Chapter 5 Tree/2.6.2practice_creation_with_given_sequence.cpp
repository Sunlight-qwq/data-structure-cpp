#include <cstdio>
#include <stack>
#include <queue>
#define OK 1

/*
输入格式：第一行为输入字符串长度，第二行为结点字符串
*/

typedef int Status;
typedef char TElemType;
const char NULLCHAR = '#';

typedef struct BiNode
{
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode, *BiTree;

Status BiNodeCreation(BiTree &p, TElemType data)
{
    p = new BiNode;
    p -> data = data;
    p -> lchild = NULL;
    p -> rchild = NULL;
}

Status BiTreeCreationQueue(BiTree &T, std::queue<char> qu)
{
    BiTree p, q;
    bool flag = false, continuecycle = true;
    std::stack<BiNode*> s;
    char ch = qu.front();
    qu.pop();
    if(ch == NULLCHAR)
    {
        T = NULL;
        return OK;
    }
    BiNodeCreation(T, ch);
    p = T;
    while(continuecycle)
    {
        ch = qu.front();
        qu.pop();
        switch((char) flag + ((ch == NULLCHAR) << 1))
        {
            case 0: // flag == false 且 读入非空
            {
                BiNodeCreation(q, ch);
                p -> lchild = q;
                s.push(p);
                p = q;
                break;
            }
            case 1: // flag == true 且 读入非空
            {
                BiNodeCreation(q, ch);
                p -> rchild = q;
                flag = false;
                p = q;
                break;
            }
            case 2: // flag == false 且 读入为空
            {
                ch = qu.front();
                qu.pop();
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
            case 3: // flag == true 且 读入为空
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

int main()
{
    int n;
    char ch;
    std::queue<char> qu;
    scanf("%d", &n);
    getchar();
    while(n--)
    {
        scanf("%c", &ch);
        qu.push(ch);
    }
    BiTree T;
    BiTreeCreationQueue(T, qu);
    return 0;
}