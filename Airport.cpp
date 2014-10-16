// Airport.cpp

#include "Airport.h"
#include <queue>
#include <cstdlib>
#include <iostream>

using namespace std;

void Airport(
  int landingTime,    // Time segments needed for one plane to land
  int takeoffTime,    // Time segs. needed for one plane to take off
  double arrivalProb, // Probability that a plane will arrive in
                      // any given segment to the landing queue
  double takeoffProb, // Probability that a plane will arrive in
                      // any given segment to the takeoff queue
  int maxTime,        // Maximum number of time segments that a plane
                      // can stay in the landing queue
  int simulationLength// Total number of time segs. to simulate
)
{
    unsigned int success_Takeoff, success_Land, fail_Takeoff, remain_land, remain_takeoff;
    double avg_takeoff, avg_Land;
    
    
// Insert content here




}
