
#pragma once
typedef float float32;
typedef double float64;
typedef signed short sint16;
typedef unsigned short uint16;
typedef long long int  uint64;


struct dronePos_t
{
    float32 f_wx; //World absolute position in the map
    float32 f_wy;
    float32 f_wz;
};


struct pedPos_t
{
    float32 f_wx; //World absolute position in the map
    float32 f_wy;
    float32 f_wz;
};
struct camPose_t
{
    float32 f_tx; // Relative position to the dronePost
    float32 f_ty;
    float32 f_tz;
    float32 f_pitch;
    float32 f_yaw;
    float32 f_roll;
};


struct camParameters_t //Model use is the pinhole model Intrinsinc calibration
{
    float32 fx; // Focal mm units
    float32 fy;
    float32 cx; // Main point pixel units
    float32 cy;
};

 enum dronePedestrianTrackingMode {init, run, reset,stop}; 

#define NUMBERMAXOFPEDESTRIAN (10U)



struct descriptorOfPed
{
    float32 af_PedestrianDescripor[32];
};

struct pedestrianBoundingBox_t // Position of the pedestrian in the image
{
    uint16 uiTxUR; //Tx Upper Right
    uint16 uiTyUR;
    uint16 uiTxLL;
    uint16 uiTyLL; //Ty LowerLeft
    uint16 uiCOnfidence; //Detection Confidence
    descriptorOfPed pedDesriptor; //Find appropiate descriptor, color of the pedestrian shirt, visible, or high level invariant information
};
struct LUTMatch_t
{
    sint16 ui_indexPrev;
    sint16 ui_indexCurrent;
};