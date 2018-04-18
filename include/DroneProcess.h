#pragma once
#include "typeDefinitions.h"
#include "inputInterface.h"

class DroneProcess
{
public:
    DroneProcess(void);
    ~DroneProcess(void);
    void v_reset();
    void v_init(Input_t input);

private:
    dronePos_t                              m_previousDronePos;
};

