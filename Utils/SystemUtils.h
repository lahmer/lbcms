//
// Created by lahmer on 8/11/16.
//

#ifndef CLIOTEST_SYSTEMUTILS_H
#define CLIOTEST_SYSTEMUTILS_H

#include "../lbcmsCommon.h"
#include "sys/stat.h"
#include <dirent.h>

namespace lbcms {
    class SystemUtils {

    public:
        //TODO::Implement windows specific implementation for this part of the system
        static bool isDirectoryExists(std::string path);
        static void CreateDirectory(std::string path);
        static bool isFileExists(std::string path);
        static void CreateFile(std::string path , std::string content);
        static void ReplaceFile(std::string path , std::string content);
    };
}

#endif //CLIOTEST_SYSTEMUTILS_H
