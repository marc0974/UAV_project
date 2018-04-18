#pragma once
#include "typeDefinitions.h"


struct Output_t
{
   bool             isPedestriansfound;                         //explicit
   uint16           ui_numberOfPedestrianFound;                 //Numbers of pedestrians
   pedPos_t         a_pedPos[NUMBERMAXOFPEDESTRIAN];            //pedestrian position
   uint16           a_pedDetactionConf[NUMBERMAXOFPEDESTRIAN];  //Confidence Detection
};