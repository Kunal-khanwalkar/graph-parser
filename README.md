# graph-parser
A simple graph-like data structure which is parsed from an input file. A kind of tool which I may use for some other project.
All the tool is doing is read the input file, and generate a graph from it. You can navigate through the graph using the commands created in the utilities header file.

### Graph node structure:
1. Location (string)
2. Prompt to display / information about the current location (string)
3. A vector of pairs containing the location of the adjacent point and the point's address 
( std::vector(std::pair(string,*node)) )


### Commands
1. printGraph() - prints the entire graph (void)
2. countNodes() - returns the no. of nodes in the graph (int)
3. getLocation() - prints the current location (void)
4. currentState() - prints all the information about the current node and the traversal options (void)
5. moveTo(string input) - moves to the location given by the user, the location must be an adjacent node (void)

#### To run, simply compile the driver_code.cpp by writing ```g++ driver_code.cpp -o dc``` and run dc.exe
