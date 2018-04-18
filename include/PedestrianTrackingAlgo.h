#pragma once
#include "typeDefinitions.h"
#include "inputInterface.h"
#include "outputInteface.h"
#include <vector>
#include "ImageProcess.h"
#include "DroneProcess.h"
#include "CameraProcess.h"

class PedestrianTrackingAlgo
{
public:
    PedestrianTrackingAlgo(void);
    ~PedestrianTrackingAlgo(void);
    void v_init(Input_t& input);
    void v_reset();
    void v_run(Input_t& input, Output_t output);
private:

    ImageProcess    m_imageProcess;
    
    
    
    uint64                                  m_previousTimeStamp;
    std::vector<pedestrianBoundingBox_t>    m_previousPedBB;
    uint16                                  m_numberOfPedestrianFound;                 //Numbers of pedestrians
    std::vector<pedestrianBoundingBox_t>    m_pedBB;     
    std::vector<LUTMatch_t>                 m_LUTMatch; 
    
};

