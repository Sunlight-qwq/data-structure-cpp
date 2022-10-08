#include <iostream>
#include <queue>


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

Status bfs(AMGraph g, int startv=0, bool *visited=NULL)
{
    int u, w;
    std::cout << startv << " ";
    if(visited == NULL)
    {
        visited = new bool[g.nvex];
        for(int i = 0; i <= g.nvex; i++)
        {
            visited[i] = false;
        }
    }
    visited[startv] = true;
    std::queue<int> qu;
    qu.push(startv);
    while(!qu.empty())
    {
        u = qu.front();
        qu.pop();
        for(w = 0; w < g.nvex; w++)
        {
            if((g.arcs[u][w] != 0) && (visited[w] == false))
            {
                std::cout << w << " ";
                visited[w] = true;
                qu.push(w);    
            }
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

    bfs(g, 1);
    return 0;
}