/*
 * =============================================================================
 *
 *       Filename:  support-inl.h
 *
 *    Description:  The definition of some supporting inline functions
 *
 *        Created:  Thu Jul 23 00:40:42 2015
 *       Modified:  Thu Jul 30 02:00:40 2015
 *
 *         Author:  Huang Zonghao
 *          Email:  coding@huangzonghao.com
 *
 * =============================================================================
 */
#ifndef SUPPORT_INL_H_
#define SUPPORT_INL_H_

#include <fstream>
#include "support.h"

/* #####   EXPORTED INCLINE FUNCTION DEFINE ################################## */

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  DoesItExist
 *  Description:  Check the existence of a file
 *       @param:  filename
 *      @return:  whether the file exists or not
 * =============================================================================
 */
inline bool DoesItExist ( const char* filename ){
    std::ifstream f(filename);
    if (f.good()) {
        f.close();
        return true;
    }
    else {
        f.close();
        return false;
    }
}       /* -----  end of function DoesItExist  ----- */



/*
 * ===  FUNCTION  ==============================================================
 *         Name:  ExeCMD
 *  Description:  Execute some system commands and return the stdout
 *       @param:  sys_command
 *      @return:  output of stdout
 * =============================================================================
 */
inline const char* ExeCMD ( const char * cmd ){
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
        if(fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    result.resize(result.size() - 1);
    return result.c_str();
}       /* -----  end of function ExeCMD  ----- */

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  IsValidFileFormat
 *  Description:  Check whether a string is the vaild output file format
 *       @param:  char *
 *      @return:  bool
 * =============================================================================
 */
bool IsValidFileFormat(const char * var){
    if (find(file_format_options.begin(), file_format_options.end(), var) != \
            file_format_options.end())
        return true;
    else return false;
}       /* -----  end of function IsValidFileFormat  ----- */

/*
 * ===  FUNCTION  ==============================================================
 *         Name:  IsValidPolicy
 *  Description:  check whether the input string is the valid policy
 *       @param:  char *
 *      @return:  bool
 * =============================================================================
 */
bool IsValidPolicy(const char * var){
    if (find(policy_options.begin(), policy_options.end(), var) !=\
            policy_options.end())
        return true;
    else return false;
}       /* -----  end of function IsValidPolicy  ----- */


#endif   /* ----- #ifndef SUPPORT-INL_H_  ----- */

/* =============================================================================
 *                         end of file support-inl.h
 * =============================================================================
 */
