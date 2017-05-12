#include "simulate.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Simulate' for simulating a network.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Diego Valdes
 * Date last modified: 4 November 2016
**/

static string kTag = "SIMULATE: ";

/******************************************************************************
 * Constructor
**/
Simulate::Simulate() {
}

/******************************************************************************
 * Destructor
**/
Simulate::~Simulate() {
}

/******************************************************************************
 * General functions.
**/

/*********************************************************************
 * Function to read the network configuration FROM STANDARD INPUT.
 *
 * Parameters:
 *   in_file: the 'Scanner' from which to read
**/
void Simulate::ReadNetwork(Scanner& in_file) {
  cout << "enter ReadNetwork" << endl;

  while (in_file.HasNext()) {
    string line = in_file.NextLine();
    Node node;
    node.ParseInputLine(line);
    network_[node.GetNodeLabel()] = node;
  }

  cout << "leave ReadNetwork" << endl;
}

/*********************************************************************
 * Function to run the simulation.
 *
 * Parameters:
 *
 * Simulates the sending of a msg through a map of nodes
 * 
**/
void Simulate::RunSimulation() {
  bool done = false;
  int time = 0;

  cout << "enter RunSimulation" << endl;

  // go through map until every node has received the msg.  
  while(!done){

	// iterate over the map
  	for(map<string, Node>::iterator ii = network_.begin(); ii != network_.end(); ++ii){

		// initialize the first node to get the msg
		if(time == 0) (ii->second).SetMessageAtTime(time, "origin");
	
		// check if the node has received the msg
		if((ii->second).GotMessageAtTime() <= time){
			
			// get the links associated witht the node 
			vector<string> yoLinks = (ii->second).GetLinkLabels();
			// adds appropriate time for the links 
			int clockAdder = 0;

			// add the appropriate time to the links that they should get msg
			for(std::size_t i = 0; i < yoLinks.size(); i++){

				clockAdder++;

				// check if the link got the msg and compare to time 
				if(network_.at(yoLinks.at(i)).GotMessageAtTime() > time){

					// add the appropriate time to the links and the appropriate
					// label using the node at the iterator and the node label
					network_.at(yoLinks.at(i)).
						SetMessageAtTime((ii->second).
						GotMessageAtTime() + clockAdder, (ii->second).GetNodeLabel());
				}
			}
		}

		// increment time
		time++;
  	}


	// cycle through map to check if all nodes have received
  	for(map<string, Node>::iterator ii = network_.begin(); ii != network_.end(); ++ii){

		done = true;
		
		// check for dummy time, break if true
		if((ii->second).GotMessageAtTime() == Node::kDummyTime){

			done = false;
			break;
		} 		
	}

  }


  cout << "leave RunSimulation" << endl;
} //RunSimulation

/*********************************************************************
 * Function to 'toString' the network configuration.
**/
string Simulate::ToStringNetwork(string label)
{
  string s = label + "\n";
  s += "NODECOUNT: " + Utils::Format(number_of_nodes_, 4) + "\n";
  map<string, Node>::iterator it;
  for (it = network_.begin(); it != network_.end(); ++it) {
    s += (it->second).ToString() + "\n";
  }

  return s;
}

/*********************************************************************
 * 

void Simulate::SendMsg(Node node){

	vector<string> daLinks = node.GetLinkLabels();
	int clock = node.GotMessageAtTime();
	String label = node.GetNodeLabel();

	for(int i = 0; i < daLinks.size(); i++){
		
		Node node;
		

	}




}
**/

