#include <iostream>

/*
定义一个动态分配内存的邻接矩阵图，邻接矩阵大小按节点数分配。
*/

typedef char VertexType;
typedef int ArcType;
typedef int Status;

const int OK = 1;

typedef struct {
    VertexType *vexs;
    ArcType **arcs;
} AMGraph;

Status initGraph(AMGraph &g, int n)
{
    g.vexs = new VertexType[n];
    g.arcs = new ArcType*[n];
    g.arcs[0] = new ArcType[n * n];
    for(int i = 1; i < n; i++)
    {
        g.arcs[i] = g.arcs[i - 1] + n;
    }
    for(int i = 0; i < n * n; i++)
    {
        g.arcs[0][i] = 0;
    }
    return OK;
}

int main()
{
    int n = 3;
    AMGraph g;
    initGraph(g, n);

    g.vexs[0] = 'A';
    g.vexs[1] = 'B';
    g.vexs[2] = 'C';
    g.arcs[0][1] = 1;
    g.arcs[1][0] = 1;

    for(int i = 0; i < n; i++)
    {
        printf("%c ", g.vexs[i]);
    }
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", g.arcs[i][j]);
        }
        printf("\n");
    }

    return 0;
}