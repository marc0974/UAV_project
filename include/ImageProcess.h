#pragma once
#include "inputInterface.h"
#include <cstring>
#include <vector>

class ImageProcess
{
public:
    ImageProcess(void);
    ~ImageProcess(void);
    void v_setInputImage(const uint16 *imageRaw );
    void v_detectPedestrianOnImage(std::vector<pedestrianBoundingBox_t>& pedBB, uint16& numberOfPedestrianFound);
    std::vector<pedestrianBoundingBox_t> detectPedestrian(uint16* pImageRaw);
    descriptorOfPed v_computePedestrianDescriptor(uint16* pImageRaw,
                                                  std::vector<pedestrianBoundingBox_t>::const_reference pedBb);
    sint16 ui_findMatch(std::vector<pedestrianBoundingBox_t>::const_reference pedBb,
                        const std::vector<pedestrianBoundingBox_t>& vector);
    void v_associateWithPreviousBoundingBox(std::vector<LUTMatch_t>& LUTMatch,
                                            std::vector<pedestrianBoundingBox_t>& pedBB,
                                            std::vector<pedestrianBoundingBox_t>& prevPedBB);
   
private:
    uint16* m_imageRaw; 
};

