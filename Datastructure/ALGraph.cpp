#include "ALGraph.h"

int CompPriority(Edge e1, Edge e2)
{
	return (e1.weight - e2.weight);
}

void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjlist = new list<int>[nv];
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	pg->heap = new Heap(CompPriority);
	memset(pg->visitInfo, 0, sizeof(int) * nv);
}

void GraphDestroy(ALGraph* pg)
{
	for (int i = 0; i < pg->numV; i++)
		pg->adjlist[i].clear();
	//delete pg->adjlist;//When I run this statement, then I get RuntimeError
}

void AddEdge(ALGraph* pg, int fromv, int tov, int weight)
{
	Edge edge = {fromv, tov, weight};

	pg->adjlist[fromv].push_back(tov);
	pg->adjlist[tov].push_back(fromv);
	pg->numE++;

	pg->heap->Insert(new HeapNode(edge));
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	list<int>::iterator it;
	
	for (int i = 0; i < pg->numV; i++)
	{
		printf("Vertex linked to %c : ", i + 65);
		for (it = pg->adjlist[i].begin(); it != pg->adjlist[i].end(); it++)
			printf("%c ", (*it) + 65);
		printf("\n");
	}
}

void ShowVertexInfo(ALGraph* pg, int num)
{
	//printf("%c ", num + 65);
}

int IsVisit(ALGraph* pg, int num)
{
	if (pg->visitInfo[num])
		return 1;
	return 0;
}

void DFS_ShowGraphVertex(ALGraph* pg, int startV)
{
	list<int>::iterator it;
	stack<int> stack;
	int visitV = startV;
	int visitFlag = 0;

	ShowVertexInfo(pg, visitV);
	pg->visitInfo[visitV] = 1;
	//stack.push(visitV);

	while (1)
	{
		it = pg->adjlist[visitV].begin();
		visitFlag = false;

		for (; it != pg->adjlist[visitV].end(); it++)
		{
			if (!IsVisit(pg, (*it)))
			{
				stack.push(visitV);
				visitV = (*it);
				pg->visitInfo[(*it)] = 1;
				ShowVertexInfo(pg, (*it));
				visitFlag = 1;
				break;
			}
		}

		if (!visitFlag)
		{
			if (stack.empty())
				break;
			else
			{
				visitV = stack.top();
				stack.pop();
			}
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}//so hard..

void BFS_ShowGraphVertex(ALGraph* pg, int startV)
{
	list<int>::iterator it;
	queue<int> que;
	int visitV = startV;

	ShowVertexInfo(pg, visitV);
	pg->visitInfo[visitV] = 1;
	it = pg->adjlist[visitV].begin();
	//stack.push(visitV);

	while (1)
	{
		for (; it != pg->adjlist[visitV].end(); it++)
		{
			if (!IsVisit(pg, (*it)))
			{
				que.push((*it));
				ShowVertexInfo(pg, (*it));
				pg->visitInfo[(*it)] = 1;
			}
		}

		if (que.empty())
			break;

		visitV = que.front();
		it = pg->adjlist[visitV].begin();
		que.pop();
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void RemoveWayEdge(ALGraph* pg, int fromv, int tov)
{
	list<int>::iterator it;
	it = pg->adjlist[fromv].begin();

	for (; it != pg->adjlist[fromv].end(); it++)
	{
		if ((*it) == tov)
		{
			pg->adjlist[fromv].erase(it);
			break;
		}
	}
}

void RemoveEdge(ALGraph* pg, int fromv, int tov)
{
	RemoveWayEdge(pg, fromv, tov);
	RemoveWayEdge(pg, tov, fromv);
	(pg->numE)--;
}

void RecoverEdge(ALGraph* pg, int fromv, int tov, int weight)
{
	pg->adjlist[fromv].push_back(tov);
	pg->adjlist[tov].push_back(fromv);
	pg->numE++;
}

int IsConnectedVertex(ALGraph* pg, int v1, int v2)
{
	list<int>::iterator it;
	stack<int> stack;
	int visitV = v1;
	int visitFlag = 0;

	ShowVertexInfo(pg, visitV);
	pg->visitInfo[visitV] = 1;

	while (1)
	{
		it = pg->adjlist[visitV].begin();
		visitFlag = false;

		for (; it != pg->adjlist[visitV].end(); it++)
		{
			if ((*it) == v2)
			{
				memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
				return true;
			}
			if (!IsVisit(pg, (*it)))
			{
				stack.push(visitV);
				visitV = (*it);
				pg->visitInfo[(*it)] = 1;
				ShowVertexInfo(pg, (*it));
				visitFlag = 1;
				break;
			}
		}

		if (!visitFlag)
		{
			if (stack.empty())
				break;
			else
			{
				visitV = stack.top();
				stack.pop();
			}
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return false;
}

void ConKruskalMst(ALGraph* pg)
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;

	while((pg->numE + 1) > pg->numV)
	{
		edge = *(pg->heap->Delete());
		RemoveEdge(pg, edge.v1, edge.v2);

		if (!IsConnectedVertex(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	for (int i = 0; i < eidx; i++)
		pg->heap->Insert(new HeapNode(recvEdge[i]));
}/*
 **ASSIGNMENT**
 How can I do that Implementing Ascending order Kruskal Algorithm?
 */

void ShowGraphEdgeWeightInfo(ALGraph* pg)
{
	Heap h = *pg->heap;
	Edge* edge;

	while (!h.IsEmpty())
	{
		edge = h.Delete();
		printf("(%c - %c), weight : %d\n", edge->v1 + 65, edge->v2 + 65, edge->weight);
	}
}