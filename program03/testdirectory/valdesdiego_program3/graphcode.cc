#include "graphcode.h"
#include <stack>

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Author: Duncan A. Buell
 * Date last modified: 13 July 2015
**/

static const string TAG = "GraphCode: ";

/******************************************************************************
 * Constructor
**/
GraphCode::GraphCode() {
}

/******************************************************************************
 * Destructor
**/
GraphCode::~GraphCode() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * General 'MagicBaby'.
 * does the topological sort recursively
 *
 *Parameter:
 *	index -- the index to start checking the graph
 *	stack -- the stack to keep track of nodes visited
 *
 * Does recursive DFS search on a graph. sets nodes to true upon being visited 
 * and gets the vector of children node values. cycles through children nodes
 * to check if they've been visited. calls itself recursively if children
 * haven't been visited.
 *
**/

void GraphCode::MagicBaby(int index){
	
	//set node in the graph to true to mark visited
	the_graph_.at(index).SetVisited(true);
	
	//get node and vector of children
	Node node = the_graph_.at(index);
	vector<int> theVector = node.GetChildSubs();

	//for loop to iterate through children
	for(int i = 0; i < node.GetNumberOfChildren(); i++){
		//get number of child node
		int j = theVector.at(i);
		//check if the child node has been visited
		if(!the_graph_.at(j).HasBeenVisited()){
			//recursive call to visited = false
			MagicBaby(j);
		}
	}
	//push visited nodes
	theStack.push(node);	
}

/******************************************************************************
 * Function 'DoTopoSort'.
 *
 * Parameter:
 *   out_stream -- the output stream to which to write the eventual result
**/
void GraphCode::DoTopoSort(ofstream& out_stream){

#ifdef EBUG
  cout << TAG << "enter DoTopoSort\n"; 
#endif

	//cycle through graph to check if nodes have been visited
	vector<Node>::const_iterator iter;
    	for(std::size_t i = 0; i < the_graph_.size(); i++){
		//if visited = false call MagicBaby()
		if(!the_graph_.at(i).HasBeenVisited()){
			MagicBaby(i);
		}
	}

	//print contents of stack to out_stream
	string s = "";
	while(!theStack.empty()){
		s += "Node " + theStack.top().ToString();
		theStack.pop();
		s += "\n";	
	}
	out_stream << "\n" << s << endl;

#ifdef EBUG
  cout << TAG << "leave DoTopoSort\n"; 
#endif

} // void GraphCode::DoTopoSort()

/******************************************************************************
 * Function 'ReadGraph'.
 * We read data from the input stream and create a graph.
 *
 * The only thing tricky about this is to make sure we have all the nodes
 * accounted for in the 'vector' since we use the subscript also as the node
 * number. That's the reason for reading in the beginning and ending node
 * numbers and creating an initial dummy 'vector'.
 *
 * Parameter:
 *     in_stream - the 'Scanner' from which to read
**/
void GraphCode::ReadGraph(Scanner& in_stream) {
  ScanLine scanline;

#ifdef EBUG
  cout << TAG << "enter ReadGraph" << endl; 
#endif

  int first_node, last_node;
  if (in_stream.HasNext()) {
    first_node = in_stream.NextInt();
    last_node = in_stream.NextInt();
    assert ( 0 == first_node);
    // Note that we read inclusive through the 'lastNode' value.
    // Create a 'vector' of dummy nodes just so our 'vector' is of the
    //     right length.
    for(int i = 0; i <= last_node; ++i) {
      Node node = Node(i);
      the_graph_.push_back(node);
    }
  } else {
    Utils::log_stream << TAG << "Terminating. No data in input file." << endl; 
  }

  // Read line by line, one line for each node.
  // Use each line to create a 'ScanLine'.
  // Then parse each 'scanLine' instance to get the child node numbers.
  // And add each child node number to the children for the node in question.
  while (in_stream.HasNext()) {
    string the_line = in_stream.NextLine();
    scanline.OpenString(the_line);
    int parent_node_num = scanline.NextInt();
    Node node = the_graph_.at(parent_node_num);
    while( scanline.HasNext()) {
      int the_child = scanline.NextInt();
      node.AddChildSub(the_child);
    }
    this->the_graph_.at(parent_node_num) = node;
  }

#ifdef EBUG
  cout << TAG << "leave ReadGraph " << endl;
#endif
} // void GraphCode::ReadGraph(Scanner& in_stream)

/******************************************************************************
 * Function 'ToString'.
 * This is the usual 'ToString'. We output the 'vector' of 'Record'
 * instances without regard to the order.
 *
 * Returns:
 *   a formatted 'string' version of the 'vector' of records
**/
string GraphCode::ToString() const {
  string s = "";
#ifdef EBUG
  cout << TAG << "enter ToString\n"; 
#endif

  if (0 == the_graph_.size()) {
    s += "There are no nodes\n";
  } else {
    vector<Node>::const_iterator iter;
    for(iter = the_graph_.begin(); iter != the_graph_.end(); ++iter) {
      s += "Node " + (*iter).ToString();
      s += "\n";
    }
    s += "\n";
  }

#ifdef EBUG
  cout << TAG << "leave ToString\n"; 
#endif
return s;
} // string GraphCode::ToString() const
