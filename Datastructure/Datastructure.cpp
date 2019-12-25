#include <iostream>
#include "Table.h"
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

int MyHashFunc(Key k)
{
	return (k % 100);
}

int main()
{
	Table mytbl;

	Person* np;
	Person* sp;
	Person* rp;
	
	TBLInit(&mytbl, MyHashFunc);

	np = MakePersonData(990209 ,"Park", "Ansan");
	TBLInsert(&mytbl, Getssn(np), np);
	
	np = MakePersonData(960609, "Ha", "Gangnam");
	TBLInsert(&mytbl, Getssn(np), np);

	np = MakePersonData(641106, "Mi", "Gangwon");
	TBLInsert(&mytbl, Getssn(np), np);

	sp = TBLSearch(&mytbl, 990209);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&mytbl, 960609);
	if (sp != NULL)
		ShowPerInfo(sp);

	sp = TBLSearch(&mytbl, 641106);
	if (sp != NULL)
		ShowPerInfo(sp);

	rp = TBLDelete(&mytbl, 990209);
	if (rp != NULL)
		delete rp;

	rp = TBLDelete(&mytbl, 960609);
	if (rp != NULL)
		delete rp;

	rp = TBLDelete(&mytbl, 641106);
	if (rp != NULL)
		delete rp;

	return 0;
}