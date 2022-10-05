#define MAXVNUM 100

typedef char VertexType;
typedef int ArcType;

typedef struct {
    VertexType vexs[MAXVNUM];
    ArcType arcs[MAXVNUM][MAXVNUM];
} AMGraph;