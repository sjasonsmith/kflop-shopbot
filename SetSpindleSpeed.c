// Based on SpindleUsingJogs/CSS/SpindleJog.c
#include "KMotionDef.h"

#include "SpindleControl.h"

main()
{
	// KMotion will set SPINDLECONTROL_SPEED_DESIRED for us.
	const float desiredSpeed = *(float*)&persist.UserData[SPINDLECONTROL_SPEED_DESIRED];  // value stored is actually a float 
	
	printf("Set spindle speed = %f...\n", desiredSpeed);
	while (desiredSpeed != *(float*)&persist.UserData[SPINDLECONTROL_SPEED_CONFIRMED])
	{
		printf("waiting...\n");
		Delay_sec(0.01);
	}
	printf("...done\n");
}
