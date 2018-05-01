#include "KMotionDef.h"
#include "PC-DSP.h

#define zRes 2979.3805	// Steps per inch in Z axis

// Globals

#define PROBEBIT 0                           // #110
#define PROBESPEED 500.0f                    // #111
#define XAXIS 1                              // #112
#define YAXIS 0                              // #113
#define ZAXIS 2                              // #114
#define UPSPEED 2000.0f                      // #115
#define DOWNSPEED (PROBESPEED * -1.0f)       // #116
#define DOWNSPEED_SLOW (DOWNSPEED * 0.1)
#define WESTSPEED -1000.0f                   // #117
#define EASTSPEED 1000.0f                    // #118
#define NORTHSPEED 1000.0f                   // #119
#define SOUTHSPEED -1000.0f                  // #120
#define PLATETHICKNESS 0.125f                // #121
#define SAFEZ 1.0f                           // #122
#define PLATEDEPTH 3.0f                      // #123
#define PLATEWIDTH 3.0f                      // #124
#define BUFFERDISTANCE 0.1f                  // #125
#define PROBEDEPTH 0.6f                      // #126
#define RIGHTCORNEROFFSET 0.5f               // #127
#define MAXIMUMTOOLDIAMETER 0.5f             // #128
#define LEFTCORNEROFFSET 0.75f               // #129

// Put a Float as a parameter and pass the command to the App
int DoPCFloat(int cmd, float f)
{
	int result;
	persist.UserData[PC_COMM_PERSIST+1] = *(int*)&f;
	return DoPC(cmd);
}

// Put an integer as a parameter and pass the command to the App
int DoPCInt(int cmd, int i)
{
	int result;
	persist.UserData[PC_COMM_PERSIST+1] = i;
	return DoPC(cmd);
}

// Pass a command to the PC and wait for it to handshake
// that it was received by either clearing the command
// or changing it to a negative error code
int DoPC(int cmd)
{
	int result;
	
	persist.UserData[PC_COMM_PERSIST]=cmd;
	
	do
	{
		WaitNextTimeSlice();	
	}while (result=persist.UserData[PC_COMM_PERSIST]>0);
	
//	printf("Result = %d\n",result);

	return result;
}

void ProbeDown(float speed)
{
	printf("Jogging Down at speed:%f\n", speed);
    Jog(ZAXIS, speed);
	printf("Waiting for probe to read high\n");
	while (ReadBit(PROBEBIT));   		
	printf("Stopping\n");
    Jog(ZAXIS, 0);
	printf("Waiting for Z motion to stop\n");
	while (!CheckDone(ZAXIS));

}

void MoveUp(double distance)
{
	printf("Moving Up by %f\n", distance);
	MoveRel(ZAXIS, distance * zRes);
	while (!CheckDone(ZAXIS));
}

main()
{

	// Find Z Height
	ProbeDown(DOWNSPEED);
	MoveUp(0.05);
	ProbeDown(DOWNSPEED_SLOW);
	printf("Setting Z DRO to plate thickness: %f\n", PLATETHICKNESS);
	DoPCFloat(PC_COMM_SET_Z, PLATETHICKNESS);
	MoveUp(SAFEZ);
}
