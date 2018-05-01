#include "KMotionDef.h"

#define SPINDLE_BIT 48
#define SPINDLE_CW_BIT 49

#define ZAXIS 2
#define SAFE_Z_HEIGHT 0

main()
{
	ClearBit(SPINDLE_CW_BIT);
	SetBit(SPINDLE_BIT);
	printf("Spindle On CCW (Begin)\n");
	Delay_sec(4.0);
	printf("Spindle On CCW (Done)\n");
}
