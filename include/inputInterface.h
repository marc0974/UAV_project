#pragma once
#include "typeDefinitions.h"



struct Input_t
{
    dronePedestrianTrackingMode       dM;                 // Operation drone Mode
    uint64          ui_timestamp;       // Timestamp of the system
	dronePos_t      dronePos;           // Drone Position on the map   
	camPose_t       camPos;             // Camera Position relative to the drone
	camParameters_t camParams;          // Camera Parameters
	uint16*         p_ImageRaw;         // Current Image
	
};