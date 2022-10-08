#include <iostream>

/*
创建带权无向图
*/

typedef char VertexType;
typedef int ArcType;
typedef int Status;

const int NULLEDGE = 0;
const int OK = 1;


typedef struct {
    int num_vexs;
    VertexType *vexs;
    ArcType **arcs;
} AMGraph;

Status weightedGraphCreation(AMGraph &g, int n)
{
    g.num_vexs = n;
    g.vexs = new VertexType[n];
    g.arcs = new ArcType*[n];
    g.arcs[0] = new ArcType[n * n];
    for(int i = 1; i < n; i++)
    {
        g.arcs[i] = g.arcs[i - 1] + n;
    }
    for(int i = 0; i < n * n; i++)
    {
        (*g.arcs)[i] = NULLEDGE;
    }

    // 读取权的信息
    int m, v1, v2;
    double weight;
    std::cin >> m;
    while(m--)
    {
        std::cin >> v1 >> v2 >> weight;
        g.arcs[v1][v2] = weight;
    }
    return OK;
}

void PrintAdjacencyMatrix(AMGraph g)
{
    for(int i = 0; i < g.num_vexs; i++)
    {
        for(int j = 0; j < g.num_vexs; j++)
        {
            std::cout << g.arcs[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;
    AMGraph g;
    weightedGraphCreation(g, n);
    PrintAdjacencyMatrix(g);
    return 0;
}
