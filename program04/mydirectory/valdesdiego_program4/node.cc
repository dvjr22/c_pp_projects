#include "node.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Node' for holding data for a node.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Diego Valdes
 * Date last modified: 4 November 2016
**/

static const string kTag = "NODE: ";
const string Node::kDummyLabel = "DUMMYLABEL";

/******************************************************************************
 * Constructor
**/
Node::Node() {
  node_label_ = Node::kDummyLabel;
  time_got_message_ = Node::kDummyTime;
  got_message_from_node_ = Node::kDummyLabel;
}

/******************************************************************************
 * Destructor
**/
Node::~Node() {
}

/******************************************************************************
 * Accessors
**/
/*********************************************************************
 * Get a 'vector' of the link labels
**/
vector<string> Node::GetLinkLabels() {
  return links_;
}

/*********************************************************************
 * Get the time when the message was received.
**/
int Node::GotMessageAtTime() {
  return time_got_message_;
}

/*********************************************************************
 * Get the node from whom the message was received.
**/
string Node::GotMessageFrom() {
  return got_message_from_node_;
}

/*********************************************************************
 * Get the node number of this node.
**/
string Node::GetNodeLabel() {
  return node_label_;
}

/*********************************************************************
 * Set the time when the message was received.
**/
void Node::SetMessageAtTime(int when, string from_whom)
{
  cout << "NODESETATTIME " << node_label_ << " " << when << " FROM " << from_whom << endl; 
  time_got_message_ = when;
  got_message_from_node_ = from_whom;
}

/******************************************************************************
 * General functions.
**/

/*********************************************************************
 * Parse an input line to set up the node links.
 *
 * Parameters:
 *   line -- the input line as a string
**/
void Node::ParseInputLine(string line) {
  ScanLine scanline;
//  cout << "enter ParseInputLine " << line << endl;

  scanline.OpenString(line);
  node_label_ = scanline.Next();
  while (scanline.HasNext()) {
    string link_label = scanline.Next();
    links_.push_back(link_label);
  }

//  cout << "leave ParseInputLine " << line << endl;
}

/*********************************************************************
 * Usual 'toString' function.
**/
string Node::ToString() const {
  string s = "";
  s += Utils::Format(node_label_, 4);
  s += " TIME: " + Utils::Format(time_got_message_, 4);
  s += " (FROM: " + Utils::Format(got_message_from_node_, 4) + ") ";

  s += " LINKS: ";
  vector<string>::const_iterator it;
  for (it = links_.begin(); it != links_.end(); ++it) {
    s += " " + Utils::Format(*it, 4);
  }

  return s;
}

