#include "KMotionDef.h"

#define XAxisChan	1	// X & Y axis are swapped
#define YAxisChan	0	// X & Y axis are swapped
#define ZAxisChan	2

#define XAxisHomeBit	2	// X & Y axis are swapped
#define YAxisHomeBit	1	// X & Y axis are swapped
#define ZAxisHomeBit	4

#define XYStepPerInch		2482.8171	// Steps per inch in X and Y axis
#define ZStepPerInch		2979.3805	// Steps per inch in Z axis

#define MaxXSoftLimit		49	// Set maximum X axis soft limit
#define MaxYSoftLimit		25	// Set maximum Y axis soft limit
#define MaxZSoftLimit		0	// Set maximum Z axis soft limit

#define MinXSoftLimit		0	// Set minimum X axis soft limit
#define MinYSoftLimit		0	// Set minimum Y axis soft limit
#define MinZSoftLimit		-6	// Set minimum Z axis soft limit

main()
{
	// Mach3 flags bit0=X, bit1=Y, Bit2=Z, etc...
	// int Flags = persist.UserData[5];
	int Flags = 1;
	ClearStopImmediately();
	ResumeCoordinatedMotion();

	if (Flags==1)
	{
		printf("Z-Axis homing routine...");

		// Remove soft limits
		DisableAxis(ZAxisChan);
		ch2->SoftLimitPos=1e+009;
		ch2->SoftLimitNeg=-1e+009;
		EnableAxis(ZAxisChan);

		// Jog axis slowly positive until home switch detect
		Jog(ZAxisChan,1000);
		while (!ReadBit(ZAxisHomeBit));
		Jog(ZAxisChan,0);
		while (!CheckDone(ZAxisChan));
		
		// Move back 0.25" off sensor
		MoveRelAtVel(ZAxisChan, ZStepPerInch*-0.25, 1000);
		while (!CheckDone(ZAxisChan));
		
		// Zero the axis
		DisableAxis(ZAxisChan);
		Zero(ZAxisChan);
		EnableAxis(ZAxisChan);
		
		// Restore axis limit swttings
		ch2->SoftLimitPos=MaxZSoftLimit*ZStepPerInch;
		ch2->SoftLimitNeg=MinZSoftLimit*ZStepPerInch;
			
		printf("complete\n");
	}

	// X-Axis homing routine
	if (Flags==1)
	{
		printf("X-Axis homing routine...");

		// Remove soft limits
		DisableAxis(XAxisChan);
		ch1->SoftLimitPos=1e+009;
		ch1->SoftLimitNeg=-1e+009;
		EnableAxis(XAxisChan);

		// Jog axis slowly negative until home switch detect
		Jog(XAxisChan,-1000);
		while (!ReadBit(XAxisHomeBit));
		Jog(XAxisChan,0);
		while (!CheckDone(XAxisChan));
		
		// Move back 0.25" off sensor
		MoveRelAtVel(XAxisChan, XYStepPerInch*0.25, 1000);
		while (!CheckDone(XAxisChan));
		
		// Zero the axis
		DisableAxis(XAxisChan);
		Zero(XAxisChan);
		EnableAxis(XAxisChan);
		
		// Restore axis limit swttings
		ch1->SoftLimitPos=MaxXSoftLimit*XYStepPerInch;
		ch1->SoftLimitNeg=MinXSoftLimit*XYStepPerInch;
			
		printf("complete\n");
	}

	if (Flags==1)
	{
		printf("Y-Axis homing routine...");

		// Remove soft limits
		DisableAxis(YAxisChan);
		ch0->SoftLimitPos=1e+009;
		ch0->SoftLimitNeg=-1e+009;
		EnableAxis(YAxisChan);

		// Jog axis slowly negative until home switch detect
		Jog(YAxisChan,-1000);
		while (!ReadBit(YAxisHomeBit));
		Jog(YAxisChan,0);
		while (!CheckDone(YAxisChan));
		
		// Move back 0.25" off sensor
		MoveRelAtVel(YAxisChan, XYStepPerInch*0.25, 1000);
		while (!CheckDone(YAxisChan));
		
		// Zero the axis
		DisableAxis(YAxisChan);
		Zero(YAxisChan);
		EnableAxis(YAxisChan);
		
		// Restore axis limit swttings
		ch0->SoftLimitPos=MaxYSoftLimit*XYStepPerInch;
		ch0->SoftLimitNeg=MinYSoftLimit*XYStepPerInch;
			
		printf("complete\n");
	}
}
