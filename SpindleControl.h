#ifndef SPINDLECONTROL_H
#define SPINDLECONTROL_H

// Define persistent registers to use for spindle information
// Variables 100-107 are reserved.

#define SPINDLECONTROL_VAR_BASE 120

#define SPINDLECONTROL_SPEED_DESIRED   (SPINDLECONTROL_VAR_BASE + 0)
#define SPINDLECONTROL_SPEED_CONFIRMED (SPINDLECONTROL_VAR_BASE + 1)
#define SPINDLECONTROL_STATE_DESIRED   (SPINDLECONTROL_VAR_BASE + 2)
#define SPINDLECONTROL_STATE_ACTUAL    (SPINDLECONTROL_VAR_BASE + 3)

#endif
