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
	ALGraph* p = (ALGraph*)malloc(sizeof(ALGraph));
	GraphInit(p, 5);

	AddEdge(p, A, B);
	AddEdge(p, A, C);
	AddEdge(p, A, D);
	AddEdge(p, A, E);
	AddEdge(p, B, C);
	AddEdge(p, C, D);
	AddEdge(p, D, E);

	ShowGraphEdgeInfo(p);
	GraphDestroy(p);

	return 0;
}