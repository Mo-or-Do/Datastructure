#ifndef __ALGRAPH__
#define __ALGRAPH__
#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
	int numV;//a Number of vertices
	int numE;//a Number of edges
	list<int>* adjlist;
	int* visitInfo;
} ALGraph;

void GraphInit(ALGraph* pg, int nv);
void GraphDestroy(ALGraph* pg);
void AddEdge(ALGraph* pg, int fromv, int tov);
void ShowGraphEdgeInfo(ALGraph* pg);
void DFS_ShowGraphVertex(ALGraph* pg, int startV);
void BFS_ShowGraphVertex(ALGraph* pg, int startV);

#endif