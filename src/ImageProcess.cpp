#include "StdAfx.h"
#include "../include/ImageProcess.h"


ImageProcess::ImageProcess(void)
{
    std::memset(&m_imageRaw,0,sizeof(uint16)*1024*768);
    //   // Load trained model
    //   Example of dataset
    //   http://cvgl.stanford.edu/projects/uav_data/ Unfornutaly not free for commercial usage
    //   cv::FileStorage cvfs("icf_model.txt", cv::FileStorage::READ);
    //   icf_detector.read(cvfs["icf"]);
}




ImageProcess::~ImageProcess(void)
{
}


void ImageProcess::v_setInputImage(const uint16 *imageRaw )
{
    std::memcpy(&m_imageRaw,&imageRaw,sizeof(uint16)*1024*768);
}

void ImageProcess::v_detectPedestrianOnImage(std::vector<pedestrianBoundingBox_t>& pedBB,
                                             uint16& numberOfPedestrianFound)
{
    pedBB = detectPedestrian(m_imageRaw);
    numberOfPedestrianFound = pedBB.size();
    for(uint16 i=0;i<numberOfPedestrianFound;i++) // May be needed to compute an other descripter relevant to our need
    {
      pedBB.at(i).pedDesriptor = v_computePedestrianDescriptor(m_imageRaw,pedBB.at(i));   
    }
}

std::vector<pedestrianBoundingBox_t> ImageProcess::detectPedestrian(uint16* pImageRaw)
{
    // Use ACF algorithm ( Aggregate Channel of Features) No openCV implementation
    // 
    // https://funvision.blogspot.fr/2015/12/aggregate-channel-features-pedestrian.html
    // https://vision.cornell.edu/se3/wp-content/uploads/2014/09/DollarPAMI14pyramids_0.pdf
    // Descriptor based on a trained database with gives relatively goods detection.

    
    std::vector<pedestrianBoundingBox_t> pedBoundingBox;
    
 //   // Use ICF (Integral Channel of Features) 
 //   // openCV example
 //   // model loading
 //   // https://docs.opencv.org/3.0-beta/modules/xobjdetect/doc/integral_channel_features.html
 //  
 
 //
 //   // Copy image in OpenCV format
 //   cv::Mat img = cv::imread(pImageRaw);
 //
 //   // Detect on image
 //   icf_detector.detect(img, objs, 1.2, cv::Size(128, 128), cv::Size(256, 256), 8.0, 20, values);
 //   
 //   //Fill Bounding Box
 //   for (int i = 0; i < objs.size(); ++i)
 //   {
 //       pedestrianBoundingBox_t tempBBox; 
 //       tempBBox.uiTxLL =  objs[i].xLL;
 //       tempBBox.uiTyLL =  objs[i].yLL;
 //       tempBBox.uiTxUR =  objs[i].xUR;
 //       tempBBox.uiTyUR =  objs[i].yUR;
 //       tempBBox.pedDesriptor = values[i];
 //       pedBoundingBox.push_back(tempBBox);
 //   }


    return pedBoundingBox;
    // Use OpenPose algorithm, from upper view, will not work
    // https://github.com/CMU-Perceptual-Computing-Lab/openpose
    // Neural network based algo ( Tensor flow)
    // Which aims to detect pedestrian and whole body tracking ( frame based algo)
}


descriptorOfPed ImageProcess::v_computePedestrianDescriptor(uint16* pImageRaw,
    std::vector<pedestrianBoundingBox_t>::const_reference pedBb)
{
    // Here basically, the idea is to find a feature that will be invariant during multiple frame, like color of the shirt, or in case of lidar reflectivity
    // but needs to investigate 
    // https://ieeexplore.ieee.org/document/7857635/
    // https://www.sciencedirect.com/science/article/pii/S0045790613000864
    descriptorOfPed doP;
    return doP;
}


sint16 ImageProcess::ui_findMatch(std::vector<pedestrianBoundingBox_t>::const_reference pedBb,
    const std::vector<pedestrianBoundingBox_t>& vector)
{
    // Matching Descriptor depending of the type of desciptor type choosen
    // https://docs.opencv.org/3.3.0/dc/dc3/tutorial_py_matcher.html
    sint16 temp = 0;
    // if no matche found return -1
    return temp;
}

void ImageProcess::v_associateWithPreviousBoundingBox(std::vector<LUTMatch_t>& LUTMatch,
                                                      std::vector<pedestrianBoundingBox_t>& pedBB,
                                                      std::vector<pedestrianBoundingBox_t>& prevPedBB)
// find correspondance with the previous match
{

    LUTMatch.clear();
    for(uint16 i=0;i< NUMBERMAXOFPEDESTRIAN;i++)
    {
        sint16 uiIndex = ui_findMatch(pedBB.at(i),prevPedBB);
        LUTMatch_t tempLut;
        tempLut.ui_indexCurrent = i;
        tempLut.ui_indexPrev = uiIndex;
        LUTMatch.push_back(tempLut);
    }
}