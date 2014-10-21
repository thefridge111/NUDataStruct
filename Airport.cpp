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
    //Variables to keep track of simulation statistics
    unsigned int success_Takeoff, success_Land, fail_Land;
    double avg_Takeoff, avg_Land;
    
    //Runway flag for if runway is busy, runway timer till runway is free and
    //counter for elapsed simulation time
    bool runway_Flag;
    unsigned int runway_Timer = 0;
    unsigned int count = 0;
    
    //Queues to keep track of landing/takeoff wait times and arrival times of 
    //planes in landing and takeoff queues
    queue<int> land_times;
    queue<int> takeoff_times;
    queue<int> landing;
    queue<int> takeoff;
   
    success_Takeoff = 0;
    success_Land = 0;
    fail_Land = 0;    
       
    do {
        //Generate two random numbers to compare to probabilities of new planes 
        //arriving in either queue
        if ((rand() % 100) < (100 * arrivalProb)) {
            landing.push(count); 
        }
        if ((rand() % 100) < (100 * takeoffProb)) {
            takeoff.push(count); 
        }
        
        //Check that the runway isnt busy and act accordingly
        switch (runway_Flag) {
            //Runway is Free
            case false:
                if (landing.size() > 0) {
                    //Check for any planes that have crashed in the landing queue
                    //before beginning any new landings
                    while (((count - landing.front()) > maxTime) && (landing.size() > 0)) {
                        //Store crashed plane's wait time
                        land_times.push(count - landing.front());
                        landing.pop();
                        fail_Land++;
                    }
                    //If any planes remain in landing queue, begin landing
                    if(landing.size() > 0) {
                        //Runway flag is set to indicate runway is in use
                        //Runway timer keeps track of time until runway is free
                        runway_Flag = true;
                        runway_Timer = landingTime;
                        success_Land++;
                        //Store time that landing plane waited
                        land_times.push(count - landing.front());
                        //Notify user that successful landing took place
                        cout << "Plane landed at " << count << endl;
                        landing.pop();
                    } 
                //If no planes are waiting to land, beginning allowing planes to
                //take off if any exist
                } else if (takeoff.size() > 0) {
                        //Runway flag is set to indicate runway is in use
                        //Runway timer keeps track of time until runway is free
                        runway_Flag = true;
                        runway_Timer = takeoffTime;
                        success_Takeoff++;
                        //Store time that taking off plane waited
                        takeoff_times.push(count - takeoff.front());
                        //Notify user that successful takeoff took place
                        cout << "Plane took off at " << count << endl;
                        takeoff.pop();
                    }
                break;
            //Runway is busy
            case true:
                //Check for any planes that have crashed in the landing queue
                if (landing.size() > 0) {
                    //Difference between count and queue front gives wait time
                    while (((count - landing.front()) > maxTime) && (landing.size() > 0)) {
                        //Store crashed plane's wait time 
                        land_times.push(count - landing.front());
                        landing.pop();
                        fail_Land++;
                    }
                }
                break;
        }
        //If the runway is still busy decrement runway timer
        //If the runway timer is at 0 then runway is free, reset runway flag
        if (runway_Timer > 0) {
            runway_Timer--;
        } else {
            runway_Flag = false;
        }
        //Increment counter to keep track of elapsed time in simulation
        count++;
    //When counter exceeds simulation length, simulation is over
    } while (count <= simulationLength);
    
    //Keeps track of number of elements for averaging purposes
    int takeoff_count = 0;
    int land_count = 0;
    
    //Zeros averages before new calculations take place
    avg_Takeoff = 0;
    avg_Land = 0;
    
    //Loops sum wait times of planes in queues and increment element counters
    while (takeoff_times.size() > 0) {        
        takeoff_count++;
        avg_Takeoff += takeoff_times.front();
        takeoff_times.pop();
    }
    while (land_times.size() > 0) {
        land_count++;
        avg_Land += land_times.front();
        land_times.pop();
    }
    
    //Average calculations
    avg_Takeoff = (avg_Takeoff / takeoff_count);
    avg_Land = (avg_Land / land_count);
    
    //Print statistics to screen
    cout << "Number of successful takeoffs: " << success_Takeoff << endl;
    cout << "Number of successful landings: " << success_Land << endl;
    cout << "Number of crashed planes: " << fail_Land << endl;
    cout << "Average takeoff wait time: " << avg_Takeoff << endl;
    cout << "Average landing wait time: " << avg_Land << endl;
    cout << "Planes left in takeoff queue: " << takeoff.size() << endl;
    cout << "Planes left in landing queue: " << landing.size() << endl;



}
