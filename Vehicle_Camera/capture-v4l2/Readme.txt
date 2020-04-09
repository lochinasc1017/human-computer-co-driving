1.example code main.cpp, capture one frame and display.

2.api description
/*
**open and init one video node
**@index: video node, for /dev/video0, index=0
**@width: camera width, for 2560*800, w=2560
**@height: camera height, for 2560*800, h=800
**@format: camera format, V4L2_PIX_FMT_UYVY
**@io_meth: camera IO method, IO_METHOD_USERPTR
**@return: On  success, 0 is returned, others for error
*/
int init_cam(int index, unsigned int width, unsigned int height, unsigned int format, enum io_method io_meth);

/*
**close and deinit camera
**/
int deinit_cam();

/*
**capture one frame
**@pointer_to_cam_data: capture up to @size bytes into the buffer starting at @pointer_to_cam_data
**@size: capture bytes
**@return: On  success, 0 is returned, others for error
**/
int get_cam_frame(unsigned char **pointer_to_cam_data, int *size);

/*
**release one frame
**/
int release_cam_frame();


3.compile
make clean
make -j4

export LD_LIBRARY_PATH=./


4.run
./cap
