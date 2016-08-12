//
// Created by lahmer on 8/10/16.
//

#ifndef CLIOTEST_LOGGER_H
#define CLIOTEST_LOGGER_H
#include"../lbcmsCommon.h"

namespace lbcms{
class Logger {
public:
    ///This function is used to save error messages in the log file
    ///and to print them in the screen in case of debug
    ///@param [in] msg a message that indicates the error string to be displayed
    static void logError (std::string msg);
    static void logDebug(std::string msg );
};
}


#endif //CLIOTEST_LOGGER_H
