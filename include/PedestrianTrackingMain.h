 #include "typeDefinitions.h"
#include "inputInterface.h"
#include "outputInteface.h"
#include "PedestrianTrackingAlgo.h"
#pragma once
class pedestrianTrackingMain
{
public:
    pedestrianTrackingMain(void);
    ~pedestrianTrackingMain(void);

    void v_exec(Input_t& input,Output_t& output);


    void v_init(Input_t& input);
    void v_run(Input_t& input, Output_t output);
    void v_reset(Input_t& input);
    void v_stop();

    private:

    DroneProcess    m_droneProcess;
    CameraProcess   m_cameraProcess;
    
    PedestrianTrackingAlgo m_pedTrack;
};

