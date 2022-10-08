#include <iostream>

/*
在邻接矩阵上的深度优先搜索方法
*/

typedef char VertexType;
typedef int ArcType;
typedef int Status;

const int OK = 1;

typedef struct {
    VertexType *vexs;
    ArcType **arcs;
    int nvex;
} AMGraph;

Status initGraph(AMGraph &g, int n)
{
    g.nvex = n;
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



Status dfs(AMGraph g, int startv=0, bool *visited=NULL)
{
    if(visited == NULL)
    {
        visited = new bool[g.nvex]; // 用数组储存已访问的链表
    }
    visited[startv] = true;
    std::cout << startv << " ";
    for(int w = 0; w < g.nvex; w++) // 遍历所有行
    {
        if((g.arcs[startv][w] != 0) && (!visited[w]))
        {
            dfs(g, w, visited);
        }
    }
    return OK;
}

int main()
{
    AMGraph g;
    int n = 6;
    initGraph(g, n);
    g.arcs[0][1] = 1;
    g.arcs[1][0] = 1;
    g.arcs[0][2] = 1;
    g.arcs[2][0] = 1;
    g.arcs[0][3] = 1;
    g.arcs[3][0] = 1;
    g.arcs[1][4] = 1;
    g.arcs[4][1] = 1;
    g.arcs[2][4] = 1;
    g.arcs[4][2] = 1;
    g.arcs[3][5] = 1;
    g.arcs[5][3] = 1;

    dfs(g, 1);
    return 0;
}