#include<iostream>
#include<vector>
#include<fstream>

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
