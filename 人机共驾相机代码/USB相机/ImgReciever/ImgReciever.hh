#ifndef IMGRECIEVER_HH
#define IMGRECIEVER_HH

#include <sys/stat.h>
#include "CommonDefinitionX.hh"
#include "LocalPosen.hh"
#include "ColorImagen.hh"
#define IMAGE_WIDTH 1824
#define IMAGE_HEIGHT 940
#define IMAGE_CHANNEL 3
class RADARRECIEVER_MODULE
{
public:
    UINT8 Image_mat[IMAGE_HEIGHT * IMAGE_WIDTH * IMAGE_CHANNEL];
//    IMGRECIEVER_MODULE();
//    virtual ~IMGRRECIEVER_MODULE();

    virtual void PRE_PROCESS();
    virtual void POST_PROCESS();
    virtual void INITIALIZE_NML();
    void CamSensorConfig();
    void displayCamData();
    void SaveData();
    NML * COLORIMAGE_CHANNEL;
    COLORIMAGE_MSG *img_msg;

};
#endif







