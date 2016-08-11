//
// Created by lahmer on 8/10/16.
//

#include "Logger.h"
namespace lbcms{
    void Logger::logError(std::string msg)  {
        LOGE<<msg;
#ifdef LBCMS_DEBUG
        std::cout<<msg<<std::endl;
#endif
    }
    void Logger::logDebug(std::string msg)  {
        LOGD<<msg;
#ifdef LBCMS_DEBUG
        std::cout<<msg<<std::endl;
#endif
    }
}