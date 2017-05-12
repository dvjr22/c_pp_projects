/****************************************************************
 * Header file for the string matching test.
 *
 * Author/copyright:  Duncan Buell
 * Date: 20 August 2016
 *
**/

#ifndef SMATCH_H
#define SMATCH_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "myrandom.h"

class SMatch {
public:
 SMatch();
 virtual ~SMatch();

 void CreateDNA();
 void FindMatches();
 void ReadPatterns(Scanner& in_scanner);
 void ReadText(Scanner& in_scanner);

 string ToStringText();
 string ToStringPatterns();

private:
 vector<string> the_text_;
 vector<string> the_patterns_;

};

#endif
