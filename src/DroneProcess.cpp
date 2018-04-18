#include "StdAfx.h"
#include <set>
#include "../include/DroneProcess.h"


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