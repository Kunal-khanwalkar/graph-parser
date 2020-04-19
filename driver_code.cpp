#include<iostream>
#include"graph-parser-utilities.h"
using namespace std;

int main()
{
	graph *A = new graph();
	string inp;
	while(true)
	{
		A->currentState();
		cout<<"\nWhere to next? ";
		if(inp=="stop")
			break;
		cin>>inp;
		A->moveTo(inp);
	}

}