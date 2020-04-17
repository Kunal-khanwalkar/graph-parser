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
			auto pred = [=](node &thenode)
			{
				return thenode.location == nodeLocation;
			};
			itr = find_if(nodes.begin(),nodes.end(),pred);
			nodes[i].insertNode(*itr);
		}
	}

	return nodes;
}








class graph
{	
	node *current;
	vector<node*> n;
public:	
	graph();
	~graph();
	void printGraph();
	int countNodes() const;
	void getLocation();
	void moveTo(string &str);
};

graph::graph()
{		
	vector<node> nodes = getGraph();

	current = &nodes[0];
	n.resize(nodes.size());		
	for(int i=0;i<n.size();i++)	
		n[i] = &nodes[i];				
	
	nodes.clear();
	nodes.shrink_to_fit();
}

graph::~graph()
{
	delete current;
	n.clear();
	n.shrink_to_fit();
}

void graph::printGraph()
{
	for(int i=0;i<n.size();i++)
		n[i]->printAll();
}

int graph::countNodes() const
{
	return n.size();
}

void graph::getLocation()
{
	cout<<"\n"<<current->location;
}

void graph::moveTo(string &str)
{
	vector<node*>::iterator itr;
	auto pred = [=](node *thenode)
	{
		return thenode->location == str;
	};
	itr = find_if(n.begin(),n.end(),pred);

	current = *itr;
}




int main()
{
/*
	vector<node> nodes = getGraph();

	for(int i=0;i<nodes.size();i++)
		nodes[i].printAll();
*/

	graph A;			
	A.getLocation();	
	//A.printGraph();
	return 0;
}



