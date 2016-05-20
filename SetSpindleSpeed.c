// Based on SpindleUsingJogs/CSS/SpindleJog.c
#include "KMotionDef.h"

#define SPEEDVAR 99				// global persistant variable to store latest speed
#define STATEVAR 98				// global persistant variable to store latest state (-1=CCW,0=off,1=CW)
#define KMVAR  113 //PC_COMM_CSS_S 	// variable KMotionCNC will pass speed parameter (113)

// desired speed is passed from KMotionCNC in variable KMVAR
// save in user variable STATEVAR whether it was off, CW, or CCW (0,1,-1)
// save in user variable SPEEDVAR the last desired speed

main()
{
	float speed = *(float *)&persist.UserData[KMVAR];  // value stored is actually a float 
	//float LastState = persist.UserData[STATEVAR];  // get last state 
	
	printf("SpindleSpeed=%f\n", speed);
	//persist.UserData[SPEEDVAR] = persist.UserData[KMVAR];  // Always save the last desired speed 

}
