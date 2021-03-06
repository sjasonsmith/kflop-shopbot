#include "KMotionDef.h"

#define SPINDLE_BIT 48
#define ZAXIS 2
#define SAFE_Z_HEIGHT 0

main()
{
	if (ReadBit(SPINDLE_BIT)) // only move up if Spindle was on
	{
		ClearBit(SPINDLE_BIT);   //spindle off
		Move(ZAXIS, SAFE_Z_HEIGHT);
		while (!CheckDone(ZAXIS));
		printf("SafeZ\n");
	}
}
