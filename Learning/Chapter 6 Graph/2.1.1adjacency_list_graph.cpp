#include <iostream>
#include <unordered_map>

/*
无向带权图的邻接表

输入数据方法：
先输入节点数、边数
然后接下来每边一行，输入起始节点、终节点、权重
*/

typedef char VertexType;
typedef double ArcType;
typedef int Status;

const int MAXV = 100;
const int OK = 1;

struct ArcNode {
    unsigned int adjvex; // 指向顶点的位置
    ArcNode *nextarc;
    ArcType weight;
};

typedef struct VNode {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAXV];

typedef struct {
    AdjList vertices;
    int nvex, narc;
} ALGraph;

Status graphCreation(ALGraph &g, int nvex, int narc)
{
    g.nvex = nvex;
    g.narc = narc;
    for(int i = 0; i < nvex; i++)
    {
        // std::cin >> g.vertices[i].data;
        g.vertices[i].firstarc = NULL;
    }
    int v1, v2;
    ArcType weight;
    ArcNode *p, *q;
    for(int i = 0; i < narc; i++)
    {
        std::cin >> v1 >> v2 >> weight;
        p = new ArcNode;
        p -> adjvex = v2;
        p -> weight = weight;
        p -> nextarc = g.vertices[v1].firstarc;
        g.vertices[v1].firstarc = p;
        q = new ArcNode;
        q -> adjvex = v1;
        q -> weight = weight;
        q -> nextarc = g.vertices[v2].firstarc;
        g.vertices[v2].firstarc = q;
    }
    return OK;
}

int main()
{
    int nvex, narc;
    std::cin >> nvex >> narc;
    ALGraph g;
    graphCreation(g, nvex, narc);
    return 0;
}