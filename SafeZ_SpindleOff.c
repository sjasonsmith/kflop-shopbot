#include "KMotionDef.h"

#define ZAxisChan	2
#define SPINDLE_BIT 16

main()
{
		// Spindle Off
		ClearBit(SPINDLE_BIT);
		
		MoveAtVel(ZAxisChan, 0, 1000);
		while (!CheckDone(ZAxisChan));

		printf("SafeZ\n");
}

