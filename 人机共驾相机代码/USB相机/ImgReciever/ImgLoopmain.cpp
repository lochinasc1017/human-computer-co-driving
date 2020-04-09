#include <stdlib.h>	        // exit()
#include <signal.h>	        // SIGINT, signal()
#include <unistd.h>         // sleep
#include <time.h>
#include "rcs.hh" 	        // Common RCS definitions
#include "nml_mod.hh" 	    // NML_MODULE definitions
#include "ColorImagen.hh"
#include <iostream>
#include "ImgReciever.hh"
int Loop_done = 0;

extern "C" void Loop_quit(int sig);
void Loop_quit(int sig)
{
    Loop_done = 1;
}


int main(int argc, char **argv)
{
//    std::cout<<"dfsfsfd"<<std::endl;
    nml_start();
    set_rcs_print_destination(RCS_PRINT_TO_STDOUT);
    RCS_TIMER *timer = new RCS_TIMER(0.1);
//            std::cout<<"goo1d"<<std::endl;
    RADARRECIEVER_MODULE *module = new RADARRECIEVER_MODULE();
    signal(SIGINT, Loop_quit);
    while(!Loop_done)
    {
        module->PRE_PROCESS();
        module->POST_PROCESS();
        timer->wait();
    }
    nml_cleanup();
    return 0;
}
