/*
 * =============================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:  This file contains the main workflow of the PIM project
 *
 *        Created:  Wed Jul 22 13:57:40 2015
 *       Modified:  Fri Jul 31 21:32:05 2015
 *
 *         Author:  Huang Zonghao
 *          Email:  coding@huangzonghao.com
 *
 * =============================================================================
 */

/* #####   HEADER FILE INCLUDES   ############################################ */
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <iostream>
#include "../include/support.h"
#include "../include/command_queue.h"
#include "../include/system_info.h"
/*
 * ===  FUNCTION  ==============================================================
 *         Name:  main
 *  Description:
 * =============================================================================
 */
 /* :TODO:Thu Jul 23 00:16:19 2015 00:16:huangzonghao:
  * Try to make the main function bare a combination of subfunctions
  */
int main ( int argc, const char ** argv ) {
    /* set up the user interrupt handler */
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = InterruptHandler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);

    CommandQueue control;
    SystemInfo sysinfo;
    sysinfo.check_gpu();
    if(!LoadCommands(argc, argv, &control)){
        printf("Failure while reading in the commands, exit");
        return 1;
    }
/* :TODO:Fri Jul 31 17:34:09 2015:huangzonghao:
 *  then load the parameters
 *  next loop all the functions sequencially
 *  help
 *  recovery
 *  model 1
 *  model 2
 *  .
 *  .
 *  .
 *  (note all the models shall be called by the frame function)
 *
 */
    if (!LoadParameters(&control)){
        printf("Failure while loading the parameters, exit");
        return 2;
    }
    /* start the clock */
    timeval  tv1, tv2;
    gettimeofday(&tv1, NULL);


    /* end the clock */
    gettimeofday(&tv2, NULL);
    double program_running_time = \
                (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 + \
                (double) (tv2.tv_sec - tv1.tv_sec);

    std::cout << "The total time elaspsed: " << program_running_time << std::endl;
    return EXIT_SUCCESS;
}       /* ----------  end of function main  ---------- */


/* =============================================================================
 *                         end of file main.cc
 * =============================================================================
 */
