#include "StdAfx.h"
#include <set>
#include "../include/DroneProcess.h"
#include "../include/outputInteface.h"


DroneProcess::DroneProcess(void)
{
}


DroneProcess::~DroneProcess(void)
{
}


void DroneProcess::v_reset()
{
    memset(&m_previousDronePos,0,sizeof(dronePos_t));
}
void DroneProcess::v_init(Input_t input)
{
    m_previousDronePos    = input.dronePos;
}

void DroneProcess::v_run(Input_t input,Output_t ouptut)
{
    //Here get output from the pedestrian tracking, and the computing of the world position to act
    // on the drone.
    // The idea is recompute at each frame the action sended to the motors in order correct as soon as possible
    // and follow as smoothly as posible the object.
}