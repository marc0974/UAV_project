#pragma once
#include "typeDefinitions.h"
#include "inputInterface.h"
#include "outputInteface.h"

class DroneProcess
{
public:
    DroneProcess(void);
    ~DroneProcess(void);
    void v_reset();
    void v_init(Input_t input);
    void v_run(Input_t input, Output_t ouptut);

private:
    dronePos_t                              m_previousDronePos;
};

