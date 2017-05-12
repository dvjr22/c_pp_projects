#include "gcdtest.h"
#include <iostream>

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'GCDTest' for testing gcd algorithms.
 *
 * Author: Duncan A. Buell
 * Date last modified: 20 August 2016
**/

/******************************************************************************
 * Constructor
**/
GCDTest::GCDTest() {
}

/******************************************************************************
 * Destructor
**/
GCDTest::~GCDTest() {
}

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function to create the numbers to be tested.
**/
void GCDTest::CreateNumbers(LONG how_many_tests, LONG max_test_number_size)
{
  cout << "create " << how_many_tests << " records" << endl;

  MyRandom myrandom;
  LONG upperlimit = max_test_number_size;

  for (int i = 0; i < how_many_tests; ++i) {
    LONG a = myrandom.RandomUniformInt(0, upperlimit);
    LONG b = myrandom.RandomUniformInt(0, upperlimit);
    veca_.push_back(a);
    vecb_.push_back(b);
  }

  cout << "done with creation of " << how_many_tests << " records" << endl;
}

/******************************************************************************
 * Function to format a progress line.
**/
string GCDTest::FormatProgress(LONG sub, LONG a, LONG b,
                               LONG g, LONG g3)
{
  string s = "";
  s += Utils::Format(sub, 11) + " ";
  s += Utils::Format(a, 11) + " ";
  s += Utils::Format(b, 11) + " ";
  s += Utils::Format(g, 8) + " ";
  s += Utils::Format(g3, 8);

  if ((g > 0) && (g3 > 0) && (g != g3)) {
    s += " GCDS NOT EQUAL";
  }
  return s;
}

/*********************************************************************
 * Naive gcd
 * Obtains a gcd for two numbers by dividing until it reaches 0.
 * Returns the remainder before reaching 0, which is the gcd of
 * both numbers.
**/
LONG GCDTest::GcdNaive(LONG a, LONG b)
{
    //remainder
    long c; 
    
    //divide until b reaches 0
    while(b != 0){ 
        c = b;
        b = a % b;
        a = c;
        count_divisions_naive_ ++;
    }
    return a;
}

/*********************************************************************
 * Subtract three times gcd
 * Obtains a gcd by subtracting at most four timesf and checking 
 * if the smaller number has reached 0. If the smaller number has reached 
 * 0, returns the smaller number before 0 was reached.
 * If after the fourth subtraction the smaller number hasn't reached 0,
 * use division to get the gcd in the same manner that GDCNaive does.
 * the smaller number hasn't reached 0, use division to 
**/
LONG GCDTest::GcdSubtract(LONG a, LONG b) {
    long smaller, larger, remainder;
    
    //check for the larger of the variables and set them accordingly
    if(a > b){
        larger = a;
        smaller = b;
    }else{
        larger = b;
        smaller = a;
    }
    
    //subtract at most four times and return the value before larger reached 0
    for(int i = 0; i < 4; i++){
        larger = larger - smaller;
        count_subtractions_ ++;
        if(larger == 0)
            return smaller;
        if(larger < smaller){
            count_subtractions_ ++;
            long temp = larger;
            larger = smaller;
            smaller = temp;
        } 
                
    }
  
    //divide if subtraction from above hasn't returned a gcd
    while(larger != 0){ 
        remainder = larger;
        larger = smaller % larger;
        smaller = remainder;
        count_divisions_subtract_ ++;    
    }
    
    return smaller;
}

/*********************************************************************
**/
void GCDTest::RunTheTests()
{
  double timenew;
  string timestring;

  // test naive
  timestring = Utils::TimeCall("bef naive false", timenew);
  cout << timestring << endl;
  TestNaive(false);
  timestring = Utils::TimeCall("aft naive false", timenew);
  cout << timestring << endl;

  // test subtract
  timestring = Utils::TimeCall("bef subtract false", timenew);
  cout << timestring << endl;
  TestSubtract(false);
  timestring = Utils::TimeCall("aft subtract false", timenew);
  cout << timestring << endl;

  // test naive with the secondary test
  timestring = Utils::TimeCall("bef naive true", timenew);
  cout << timestring << endl;
  TestNaive(true);
  timestring = Utils::TimeCall("aft naive true", timenew);
  cout << timestring << endl;

  // test subtract with the secondary test
  timestring = Utils::TimeCall("bef subtract true", timenew);
  cout << timestring << endl;
  TestSubtract(true);
  timestring = Utils::TimeCall("aft subtract true", timenew);
  cout << timestring << endl;

  // test naive against subtract
  timestring = Utils::TimeCall("bef n-sub false", timenew);
  cout << timestring << endl;
  TestNaiveSubtract();
  timestring = Utils::TimeCall("aft n-sub false", timenew);
  cout << timestring << endl;

  cout << "done with the computation" << endl;
}

/*********************************************************************
**/
void GCDTest::TestNaive(bool check_result) {
    
  LONG a, b;
  count_divisions_naive_ = 0;
 
  for (UINT i = 0; i < veca_.size(); ++i) {
    a = veca_.at(i);
    b = vecb_.at(i);
    GcdNaive(a, b);
  }
    
  cout << "Number of naive divisions " << count_divisions_naive_ << endl;

}

/*********************************************************************
**/
void GCDTest::TestNaiveSubtract() {
  LONG a, b, g, g3;

  count_divisions_naive_ = 0;
  count_subtractions_ = 0;
  count_divisions_subtract_ = 0;
  for (UINT i = 0; i < veca_.size(); ++i) {
    a = veca_.at(i);
    b = vecb_.at(i);
    g = this->GcdNaive(a, b);
    g3 = this->GcdSubtract(a, b);

    if (g != g3) {
      cout << "ERROR N-SUB" << a << " " << b << " " << g << " " << g3 << endl;
    }
  }
  cout << "Test naive against subtract shows no discrepancies" << endl;
}

/*********************************************************************
**/
void GCDTest::TestSubtract(bool check_result) {
    
  LONG a, b;
  count_subtractions_ = 0;
  count_divisions_subtract_ = 0;
 
  for (UINT i = 0; i < veca_.size(); ++i) {
    a = veca_.at(i);
    b = vecb_.at(i);
    GcdSubtract(a, b);
  }

  cout << "Number of subtractions and divisions " << count_subtractions_
       << " " << count_divisions_subtract_ << endl;
}
