#include "smatch.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'SMatch' for testing gcd algorithms.
 *
 * Author: Duncan A. Buell
 * Date last modified: 20 August 2016
**/

/******************************************************************************
 * Constructor
**/
SMatch::SMatch() {
}

/******************************************************************************
 * Destructor
**/
SMatch::~SMatch() {
}

/******************************************************************************
 * General functions.
**/
/******************************************************************************
 * Function to create DNA strings.
void SMatch::CreateDNA() {
  string thedna = "";
  MyRandom myrandom;

  for (int i = 0; i < 100; ++i) {
    int r = myrandom.RandomUniformInt(0, 100);
    if (r < 50) {
      thedna += "A";
    } else if (r < 75) {
      thedna += "C";
    } else if (r < 90) {
      thedna += "T";
    } else {
      thedna += "G";
    }
  }
  cout << thedna << endl;
}
**/

/******************************************************************************
 * Function to find matches of patterns in the text.
**/
void SMatch::FindMatches() {
  
    //variables to keep track of counts
    int patternCount = 0;
    int hits = 0;
    int compare = 0;
    
    //variables for matching pattern to strings
    string pattern = "";
    //string toMatch = "";
    string toMatch = ToStringText();
    
    cout << "Finding matches\n";
    
    //gets the pattern in the vector
    //displays the pattern and resets variables for new comparison
    for(std::string::size_type i = 0; i < the_patterns_.size(); i++){
        pattern = the_patterns_[i];
        patternCount = 0;
        compare = 0;
        hits = 0;
        cout << "The pattern: " << pattern << "\n";
        
        //gets the size of the pattern
        for(std::string::size_type a = 0; a < pattern.size(); a++){
            patternCount++;   
        }
            
            //iterate over the string based on length
            for(std::string::size_type j = 0; j < toMatch.size(); j++){
                
                //match first char of pattern to itteration of match string
                if(pattern[0] == toMatch[j]){            
                    
                    //iterate over remaining pattern with possible match
                    for(int k = 1; k < patternCount; k++){
                        
                        //increment compare
                        compare++;
                        
                        if(pattern[k] == toMatch[j + k]){
               
                            //completed iteration over match
                            if(k == patternCount-1){
                                
                                //where match found
                                //int match = j;
                                //increment hits for current pattern
                                hits++;
                            } 
                        }else{
                            break;
                        }
                    }
                }
            } 
        
        cout << "Hits in string for pattern: " << pattern << ", " << hits << "\n";
        cout << "Extra comparisons: " << compare << "\n";
    }
   
}

/******************************************************************************
 * Function to read the patterns.
**/
void SMatch::ReadPatterns(Scanner& in_scanner)
{
  while (in_scanner.HasNext()) {
    string input = in_scanner.NextLine();
    the_patterns_.push_back(input);
  }
}

/******************************************************************************
 * Function to read the text.
**/
void SMatch::ReadText(Scanner& in_scanner)
{
  while (in_scanner.HasNext()) {
    string input = in_scanner.NextLine();
    the_text_.push_back(input);
  }
}

/******************************************************************************
 * Function to 'ToString' the 'vector' of patterns.
**/
string SMatch::ToStringPatterns() {
  string s = "";

  for(vector<string>::iterator it = the_patterns_.begin();
                               it != the_patterns_.end(); ++it) {
    s += (*it) + "\n";
  }

  return s;
}


/******************************************************************************
 * Function to 'ToString' the 'vector' of text.
**/
string SMatch::ToStringText() {
  string s = "";

  for(vector<string>::iterator it = the_text_.begin();
                               it != the_text_.end(); ++it) {
    s += " " + (*it);
  }

  return s;
}

