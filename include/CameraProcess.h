#pragma once
#include "typeDefinitions.h"
#include "inputInterface.h"
#include "outputInteface.h"

class CameraProcess
{
public:
    CameraProcess(void);
    ~CameraProcess(void);
    void v_reset();
    void v_init(Input_t input);
    void v_compute3DCameraEstimatePosition(const camPose_t& camPos, const camParameters_t& camParams);
    void v_computeCam2World(const dronePos_t& dronePos, const camPose_t& camPos);
    void v_projectOnDroneWorldCoordinates(const dronePos_t& dronePos, const camPose_t& camPos);
    void v_runSlam(const Input_t& input, const Output_t& output);

private:
    camPose_t                               m_previousCamPos;
};

