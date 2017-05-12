/****************************************************************
 * Header file for the node class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Diego Valdes
 * Date: 4 November 2016
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
 virtual ~Node();

 static const int kDummyTime = 999999999; // dummy time is infinitely in the future
 static const string kDummyLabel;

 vector<string> GetLinkLabels();
 string GetNodeLabel();
 int GotMessageAtTime();
 string GotMessageFrom();
 void SetMessageAtTime(int when, string from_whome);
 void ParseInputLine(string line);
 string ToString() const;

private:
 int time_got_message_;
 string got_message_from_node_;
 string node_label_;

 vector<string> links_;

};

#endif
