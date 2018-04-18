#include "StdAfx.h"
#include "../include/PedestrianTrackingMain.h"


pedestrianTrackingMain::pedestrianTrackingMain(void)
{
}


pedestrianTrackingMain::~pedestrianTrackingMain(void)
{
}


void pedestrianTrackingMain::v_exec(Input_t& input, Output_t& output)
{
    m_cameraProcess.v_runSlam(input,output);

    switch(input.dM) // Define algo behaviour
    {
    case dronePedestrianTrackingMode::init:
        v_init(input);
            break;   
    case dronePedestrianTrackingMode::run:
        v_run(input,output);
            break;
    case dronePedestrianTrackingMode::reset:
        v_reset(input);
           break;
    case dronePedestrianTrackingMode::stop:
        v_stop();
        break;
    default:
        break;
    }
}


void pedestrianTrackingMain::v_init(Input_t& input)
{
   m_pedTrack.v_init(input);
   m_cameraProcess.v_init(input);
   m_droneProcess.v_init(input);
}


void pedestrianTrackingMain::v_reset(Input_t& input)
{
    m_pedTrack.v_reset();
    m_cameraProcess.v_reset();
    m_droneProcess.v_reset();
}


void pedestrianTrackingMain::v_run(Input_t& input, Output_t output)
{
    
    m_pedTrack.v_run(input,output);
    
}

void pedestrianTrackingMain::v_stop()
{
   m_pedTrack.v_reset();
}
