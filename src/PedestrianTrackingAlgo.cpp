#include "StdAfx.h"
#include <cstring>
#include <algorithm>

#include "../include/PedestrianTrackingAlgo.h"


PedestrianTrackingAlgo::PedestrianTrackingAlgo(void)
{
    v_reset();
}


PedestrianTrackingAlgo::~PedestrianTrackingAlgo(void)
{
}


void PedestrianTrackingAlgo::v_init(Input_t& input)
{
    //Save data for the next frame
    m_previousTimeStamp = input.ui_timestamp;
    
   
}


void PedestrianTrackingAlgo::v_reset()
{
    // Save as the constructor
       
    m_previousTimeStamp = 0;
}





void PedestrianTrackingAlgo::v_run(Input_t& input, Output_t output)
{
    m_imageProcess.v_setInputImage(input.p_ImageRaw);

    if(m_previousTimeStamp == 0)
    {
        v_init(input);
    }
    else
    {
        m_imageProcess.v_detectPedestrianOnImage(m_pedBB,m_numberOfPedestrianFound);

        if(m_pedBB.empty()) // No detection found
        {
            // Move camera, move drone,
            // Count number of frames before doing this action may be required
        }
        else
        {
        m_imageProcess.v_associateWithPreviousBoundingBox(m_LUTMatch,m_pedBB,m_previousPedBB);
        m_previousPedBB = m_pedBB;
        }
    }
}

void PedestrianTrackingAlgo::v_compute3DpedPos(const Input_t& input, const Output_t& output)
{
    //computes 3D from camera position estimation, drone position, and position on the image.
    // Need computation of homogeneous Matrix, CAM2DRONE 6doF, ground plane estimation,
    // and foot print of the object
}
