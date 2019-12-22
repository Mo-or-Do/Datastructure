#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int GetOpPriority(char t);
int WhoisPrecOp(char op1, char op2);
void TransInorderToPostorder(char* exp, int explen);