#include<vector>
#include<algorithm>
#include<utility>
#include<fstream>


//Node structure definition
struct node
{
	std::string location;
	std::string prompt;
	std::vector<std::pair<std::string,node*>> op;
	void insertNode(node &b);
	void printAll();
};

void node::insertNode(node &b)
{	
	op.push_back({b.location,&b});
}

void node::printAll()
{	
	printf("\n%s",location.c_str());	
	printf("\n%s",prompt.c_str());	
	for(int i=0;i<op.size();i++)
	{
		printf("\n%d. %s",i+1,op[i].first.c_str());		
	}
	printf("\n");	
}







//File reading
std::vector<std::vector<std::string>> parseFile()
{

	std::vector<std::vector<std::string>> tags;	
	int tagnum=-1;

	std::string inpfilestr = ".\\parser-example.txt";
	std::string line;
	std::ifstream ifr(inpfilestr);
	if(ifr.is_open())
	{
		while(getline(ifr,line))
		{						
			if(line[0]=='[')
			{
				tagnum++;
				tags.resize(tags.size()+1);				
				tags[tagnum].push_back(line.substr(1,line.length()-2));
				continue;
			}								
			if(line.length()>1)
				tags[tagnum].push_back(line);			

		}
		ifr.close();
	}
	else
	{
		printf("File reading error\n");
		exit(1);
	}

	return tags;
}




//Graph generation
std::vector<node> getGraph(std::vector<node> &nodes)
{
	std::vector<std::vector<std::string>> tags = parseFile();
	nodes.resize(tags.size());

	for(int i=0;i<tags.size();i++)
	{		
		nodes[i].location = tags[i][0];
		nodes[i].prompt = tags[i][1];
	}	


	std::string nodeLocation;
	std::vector<node>::iterator itr;

	for(int i=0;i<nodes.size();i++)
	{
		for(int j=2;j<tags[i].size();j++)
		{
			nodeLocation = tags[i][j];
			auto pred = [=](const node &thenode)
			{
				return thenode.location == nodeLocation;
			};
			itr = std::find_if(nodes.begin(),nodes.end(),pred);
			nodes[i].insertNode(*itr);
		}
	}
	return nodes;
}









//Graph class definition
class graph
{	
	node *current;
	std::vector<node> n;	
public:	
	graph();
	~graph();
	void printGraph();
	int countNodes() const;
	void getLocation();
	void moveTo(const std::string &str);
	void currentState();
};

graph::graph()
{		
	getGraph(n);
	current = &n[0];		
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
		n[i].printAll();
}

int graph::countNodes() const
{
	return n.size();
}

void graph::getLocation()
{
	printf("\n%s",current->location.c_str());	
}

void graph::moveTo(const std::string &str)
{
	int flag=0;
	for(int i=0;i<current->op.size();i++)	
		if(current->op[i].first == str)
		{
			current = current->op[i].second;	
			flag=1;
		}
	if(flag==0)
		printf("\nI dont know where %s is\n",str.c_str());
}

void graph::currentState()
{
	current->printAll();
}
