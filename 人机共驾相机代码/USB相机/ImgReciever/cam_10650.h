#ifndef CAM_10650_H
#define CAM_10650_H
#include <sys/stat.h>
#include <sys/types.h>
#include <cstdlib>
#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv2/videoio.hpp>
#include <opencv/cv.h>
#include<opencv2/core/core.hpp>
#include "rcs.hh" 	        // Common RCS definitions
#include "nml_mod.hh" 	    // NML_MODULE definitions
using namespace std;
using namespace cv;

class cam_10650 {
 public:
  int device_index_, flip_code_, img_width, img_height, fps;
  char fourcc[4];
  Mat im;

  cam_10650();
  ~cam_10650();
  cam_10650(int device_index, int flip_code);

  //  void save_video(string video_name);
  //  void phrase_video(string video_name, string extract_dir);
  void show();
  void save(string save_dir);
  cam_10650& operator>>(Mat& image);
  cam_10650& operator=(Mat& image);
 private:
  VideoCapture cam_;
//  VideoWriter writer_;
//  VideoCapture reader_;
};

#endif  // CAM_10650_H
