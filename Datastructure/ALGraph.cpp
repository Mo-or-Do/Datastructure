#include "ALGraph.h"

void GraphInit(ALGraph* pg, int nv)
{
	pg->numV = nv;
	pg->numE = 0;
	pg->adjlist = new list<int>[nv];
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);

	memset(pg->visitInfo, 0, sizeof(int) * nv);
}

void GraphDestroy(ALGraph* pg)
{
	for (int i = 0; i < pg->numV; i++)
		pg->adjlist[i].clear();
	//delete pg->adjlist;//When I run this statement, then I get RuntimeError
}

void AddEdge(ALGraph* pg, int fromv, int tov)
{
	pg->adjlist[fromv].push_back(tov);
	pg->adjlist[tov].push_back(fromv);
	pg->numE++;
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
	pg->visitInfo[num] = 1;
	printf("%c ", num + 65);
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
	int nextV, visitFlag = 0;

	ShowVertexInfo(pg, visitV);
	stack.push(visitV);

	while (1)
	{
		it = pg->adjlist[visitV].begin();

		for (it; it != pg->adjlist[visitV].end(); it++)
		{
			if (IsVisit(pg, (*it)))
			{
				pg->visitInfo[(*it)] = 1;
				ShowVertexInfo(pg, (*it));

			}
		}

		if (!visitFlag)
		{

		}
	}
}

void BFS_ShowGraphVertex(ALGraph* pg, int startV)
{

}