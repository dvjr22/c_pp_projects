#include "node.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

/******************************************************************************
 * Class 'Node' for the creation of nodes
 *
 *
 * Author: Diego Valdes
 * Date last modified: 1 Nov 2016
**/

/******************************************************************************
 * Constructor
**/
Node::Node(){
}

/******************************************************************************
 * Constructor
**/
Node::Node(int node_number){
	kDummyNodeNumber = node_number;
	visited_ = false;
	node_number_ = kDummyNodeNumber;
}

/******************************************************************************
 * Destructor
**/
Node::~Node(){

}

/******************************************************************************
 * Function
**/
void Node::AddChildSub(int which){
	child_subs_.push_back(which);
}

/******************************************************************************
 * Function
**/
void Node::DecrementIncoming(){
	incoming_--;
}

/******************************************************************************
 * Function
**/
vector<int> Node::GetChildSubs() const{
	return child_subs_;

}

/******************************************************************************
 * Function
**/
int Node::GetIncomingCount() const{
	return incoming_;
}

/******************************************************************************
 * Function
**/
int Node::GetNodeNumber() const{
	return node_number_;
}

/******************************************************************************
 * Function
**/
int Node::GetNumberOfChildren() const{
	return child_subs_.size();
}

/******************************************************************************
 * Function
**/
bool Node::HasBeenVisited() const{
	return visited_;
}

/******************************************************************************
 * Function
**/
void Node::IncrementIncoming(){
	incoming_++;
}

/******************************************************************************
 * Function
**/
void Node::SetVisited(bool what){
	visited_ = what;
}

/******************************************************************************
 * Function
**/
string Node::ToString() const{ 
	return to_string(node_number_);
}



