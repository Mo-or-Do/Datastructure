#include <iostream>
#include "ALGraph.h"
using namespace std;

/*ExpTree exp;
	TreeNode* test;
	char temp[100];
	cin >> temp;
	test = exp.MakeExpTree(temp);
	exp.ShowPostfixTypeExp(test, exp.ShowData); 왜 이부분이 안되는걸까?
	cout << endl;
	cout << exp.EvaluateExpTree(test) << endl;
	
	*/

int main()
{
	ALGraph graph;
	GraphInit(&graph, 6);

	AddEdge(&graph, A, B, 9);
	AddEdge(&graph, B, C, 2);
	AddEdge(&graph, A, C, 12);
	AddEdge(&graph, A, D, 8);
	AddEdge(&graph, D, C, 6);
	AddEdge(&graph, A, F, 11);
	AddEdge(&graph, F, D, 4);
	AddEdge(&graph, E, D, 3);
	AddEdge(&graph, E, C, 7);
	AddEdge(&graph, F, E, 13);

	ConKruskalMst(&graph);
	ShowGraphEdgeInfo(&graph);
	ShowGraphEdgeWeightInfo(&graph);

	return 0;
}