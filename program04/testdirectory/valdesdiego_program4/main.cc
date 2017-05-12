#include "main.h"

/****************************************************************
 * Main program for simulation of a network.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 4 November 2016
 *
**/

static const string kTag = "Main: ";

void generate(int number);

/*********************************************************************
**/
int main(int argc, char *argv[]) {
  double timenew = 0.0;
  string in_filename = "";
  string timestring = "";

  Scanner scanner;
  Simulate simulator;

  cout << kTag << "Beginning execution\n";

  Utils::CheckArgs(1, argc, argv, "inputfile");
  in_filename = static_cast<string>(argv[1]);

  timestring = Utils::TimeCall("beginning", timenew);
  cout << timestring << endl;

  cout << "start the computation" << endl;

// uncomment this to generate a random graph
//  generate(20);
//  exit(0);

  scanner.OpenFile(in_filename);
  simulator = Simulate();
  simulator.ReadNetwork(scanner);
  cout << simulator.ToStringNetwork("BEFORE SIM") << endl;
  simulator.RunSimulation();
  cout << simulator.ToStringNetwork("AFTER SIM ") << endl;

  cout << kTag << "Ending execution\n";

  timestring = Utils::TimeCall("ending", timenew);
  cout << timestring << endl;

  return 0;
}


/****************************************************************
 * Function to generate random links of a directed graph.
**/
void generate(int number) {
  MyRandom myrandom;
  vector<int> thelinks;
  for (int i = 0; i < number; ++i) {
    int howmanylinks = myrandom.RandomUniformInt(1, 5);
    for (int j = 0; j < howmanylinks; ++j) {
      int link = myrandom.RandomUniformInt(0, number-1);
      thelinks.push_back(link);
    }

    cout << i << "    ";
    for (auto iter = thelinks.begin(); iter != thelinks.end(); ++iter) {
      cout << *iter << " ";
    }
    cout << endl << endl;
    thelinks.clear();
  } // for (int i = 0; i < number; ++i) {
}
