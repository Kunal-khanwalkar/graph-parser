#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include"file-reading.h"
using namespace std;


struct node
{
	string location;
	string prompt;
	vector<pair<string,node*>> op;
	void insertNode(node &b);
	void printAll();
};

void node::insertNode(node &b)
{	
	op.push_back({b.location,&b});
}

void node::printAll()
{	
	cout<<"\n"<<location<<": "<<this;
	cout<<"\n"<<prompt;
	for(int i=0;i<op.size();i++)
	{
		cout<<"\n"<<i+1<<". "<<op[i].first<<": "<<op[i].second;
	}
	cout<<endl;
}



vector<node> getGraph()
{
	vector<vector<string>> tags = parseFile();
	vector<node> nodes(tags.size());

	for(int i=0;i<tags.size();i++)
	{		
		nodes[i].location = tags[i][0];
		nodes[i].prompt = tags[i][1];
	}	


	string nodeLocation;
	vector<node>::iterator itr;

	for(int i=0;i<nodes.size();i++)
	{
		for(int j=2;j<tags[i].size();j++)
		{
			nodeLocation = tags[i][j];
			auto pred = [=](const node &thenode)
			{
				return thenode.location == nodeLocation;
			};
			itr = find_if(nodes.begin(),nodes.end(),pred);
			nodes[i].insertNode(*itr);
		}
	}
/*
	for(int i=0;i<nodes.size();i++)
		nodes[i].printAll();
*/

	return nodes;
}






/*

class graph
{
	node *head;
	vector<node*> n;

public:
	graph(vector<node> &nodes);
	~graph();
	int countNodes() const;
};

graph::graph(vector<node> &nodes)
{		
	vector<node> nodes = getGraph();

	for(int i=0;i<nodes.size();i++)
		nodes[i].printAll();

	head = &nodes[0];
	n.resize(nodes.size());		
	for(int i=0;i<nodes.size();i++)	
		n[i] = &nodes[i];				
}

graph::~graph()
{
	delete head;
	n.erase(n.begin(),n.end());
	n.shrink_to_fit();

}

int graph::countNodes() const
{
	int cnt=0;
	for(int i=0;i<n.size();i++)
		cnt++;
	return cnt;
}
*/





int main()
{

	vector<node> nodes = getGraph();

	for(int i=0;i<nodes.size();i++)
		nodes[i].printAll();


/*
	vector<vector<string>> tags = parseFile();

	for(int i=0;i<tags.size();i++)
	{
		for(int j=0;j<tags[i].size();j++)
			cout<<tags[i][j]<<" : ";
		cout<<endl;
	}

	vector<node> nodes(tags.size());
	
	for(int i=0;i<tags.size();i++)
	{
		cout<<&nodes[i]<<endl;
		nodes[i].location = tags[i][0];
		nodes[i].prompt = tags[i][1];
	}	


	string nodeLocation;
	vector<node>::iterator itr;

	for(int i=0;i<nodes.size();i++)
	{
		for(int j=2;j<tags[i].size();j++)
		{
			nodeLocation = tags[i][j];
			auto pred = [=](const node &thenode)
			{
				return thenode.location == nodeLocation;
			};
			itr = find_if(nodes.begin(),nodes.end(),pred);
			nodes[i].insertNode(*itr);
		}
	}
	

	for(int i=0;i<nodes.size();i++)
	{
		nodes[i].printAll();
	}
	cout<<endl;


	nodes[0].op[1].second->printAll();
	nodes[3].op[0].second->printAll();
	nodes[2].op[2].second->printAll();
*/


	return 0;
}



