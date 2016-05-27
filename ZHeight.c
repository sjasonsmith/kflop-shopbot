#include "KMotionDef.h"

// Globals
double *pD = (double *)persist.UserData;
float xRes, yRes, zRes;

#define PROBEBIT 171                         // #110
#define PROBESPEED 500.0f                    // #111
#define XAXIS 0                              // #112
#define YAXIS 1                              // #113
#define ZAXIS 2                              // #114
#define UPSPEED 2000.0f                      // #115
#define DOWNSPEED (PROBESPEED * -1.0f)       // #116
#define WESTSPEED -1000.0f                   // #117
#define EASTSPEED 1000.0f                    // #118
#define NORTHSPEED 1000.0f                   // #119
#define SOUTHSPEED -1000.0f                  // #120
#define PLATETHICKNESS 0.621f                // #121
#define SAFEZ 3.0f                           // #122
#define PLATEDEPTH 3.0f                      // #123
#define PLATEWIDTH 3.0f                      // #124
#define BUFFERDISTANCE 0.1f                  // #125
#define PROBEDEPTH 0.6f                      // #126
#define RIGHTCORNEROFFSET 0.5f               // #127
#define MAXIMUMTOOLDIAMETER 0.5f             // #128
#define LEFTCORNEROFFSET 0.75f               // #129

main()
{

	// Find Z Height
	ProbeDown();
	printf("Setting Z DRO to plate thickness: %f\n", PLATETHICKNESS);
	DoPCFloat(PC_COMM_SET_Z, PLATETHICKNESS);
	
	void ProbeDown()
{
	printf("Jogging Down at speed:%f\n", DOWNSPEED);
    Jog(ZAXIS, DOWNSPEED);
	printf("Waiting for probe to read high\n");
	while (!ReadBit(PROBEBIT));   		
	printf("Stopping\n");
    Jog(ZAXIS, 0);
	printf("Waiting for Z motion to stop\n");
	while (!CheckDone(ZAXIS));
}


}
