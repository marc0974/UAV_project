#include "StdAfx.h"
#include <set>
#include "../include/CameraProcess.h"


CameraProcess::CameraProcess(void)
{
}


CameraProcess::~CameraProcess(void)
{
}

void CameraProcess::v_reset()
{
    memset(&m_previousCamPos,0,sizeof(camPose_t));
}
void CameraProcess::v_init(Input_t input)
{
    m_previousCamPos    = input.camPos;
}

void CameraProcess::v_compute3DCameraEstimatePosition( const camPose_t& camPos,
    const camParameters_t& camParams)
{
    // This function is bit more complexe, multiple method could be used: 
    //      -    By computing the ground plane and detecting the foot print of the object.
    //      -  This methods needs to know exactly the drone position (6D) and the camera position in (6D)
    //      - http://openaccess.thecvf.com/content_cvpr_workshops_2015/W12/papers/Smedt_On-Board_Real-Time_Tracking_2015_CVPR_paper.pdf
    //      -    Moving the drone allows triangulation of the object possible but the object needs to be standstill
    //      https://www.thinkmind.org/download.php?articleid=ubicomm_2015_5_10_10080
    //      I would go for the ground plane constraint
}



void CameraProcess::v_computeCam2World(const dronePos_t& dronePos, const camPose_t& camPos)
{

}

void CameraProcess::v_projectOnDroneWorldCoordinates(const dronePos_t& dronePos, const camPose_t& camPos)
{
    

}

void CameraProcess::v_runSlam(const Input_t& input, const Output_t& output)
{
    // https://github.com/raulmur/ORB_SLAM2
    // Mono Camera Slam that gives good results, licence GPLv3, and dependencies to openCV BSDM.
    // Key frames based and bundle adjustment methods to build a relevant 3D environment model
    // Implementation inside a parrot drone
    // https://www.youtube.com/watch?v=XlJS2QzWi5o
}
