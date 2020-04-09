#ifndef __IMG__
#define __IMG__


#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can.h>
#include <linux/can/raw.h>

//#include "CommonDefinitionX.h"
#include "rcs.hh"
#include "nml.hh"
#include "nmlmsg.hh"
#include "ColorImagen.hh"

#define MSG_LEN 1024
#define BUF_LEN 2048

#define ESR_TARGET_NUM 64

#define IMG_HEIGHT 1280
#define IMG_WIDTH 720
#define IMG_CHANNEL 3

#define PCAN_MSG_LEN 13
#define RADAR_FRONT_MSG "radar_front"


class cam
{
public:
    UINT8 Image_mat[IMG_HEIGHT * IMG_WIDTH * IMG_CHANNEL];
private:

};

#endif
