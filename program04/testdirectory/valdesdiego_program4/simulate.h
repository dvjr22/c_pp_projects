/****************************************************************
 * Header file for the network simulation
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Diego Valdes
 * Date: 4 November 2016
 *
**/

#ifndef SIMULATE_H
#define SIMULATE_H

#include <iostream>
#include <map>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "node.h"

class Simulate {
public:
 Simulate();
 virtual ~Simulate();

 void ReadNetwork(Scanner& in_file);
 void RunSimulation();
 string ToStringNetwork(string label);
 //void SendMsg(Node node);

private:
 int number_of_nodes_;
 map<string, Node> network_;

};

#endif
