/****************************************************************
 * Header file for a node in a graph.
 *
 * Author/copyright:  Duncan Buell
 * Date: 7 May 2015
 *
**/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Node {
public:
 Node();
 Node(int node_number);
 virtual ~Node();

 void AddChildSub(int which);
 void DecrementIncoming();
 vector<int> GetChildSubs() const;
 int GetIncomingCount() const;
 int GetNodeNumber() const;
 int GetNumberOfChildren() const;
 bool HasBeenVisited() const;
 void IncrementIncoming();
 void SetVisited(bool what);

 string ToString() const;

private:
 int kDummyNodeNumber = -99; 
 bool visited_; //has been visited
 int node_number_ = kDummyNodeNumber;  //node id
 int incoming_ = 0;  //number of incoming nodes

 vector<int> child_subs_; //keep track of sub directions
};

#endif
