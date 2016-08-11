//
// Created by lahmer on 8/10/16.
//

#ifndef CLIOTEST_LOGGER_H
#define CLIOTEST_LOGGER_H
#include"../lbcmsCommon.h"

namespace lbcms{
class Logger {
public:
    static void logError (std::string);
    static void logDebug(std::string);
};
}


#endif //CLIOTEST_LOGGER_H
