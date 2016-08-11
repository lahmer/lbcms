//
// Created by lahmer on 8/11/16.
//

#ifndef CLIOTEST_FILEBASE_H
#define CLIOTEST_FILEBASE_H
#include"../../lbcmsCommon.h"
namespace lbcms {

    class FileBase {
    protected:
        std::string m_path;
        FILE *m_file;
    public:
        FileBase(std::string path);
        std::string getPath();
        FILE* getFileHandler();
        void closeFile();
    };
}

#endif //CLIOTEST_FILEBASE_H
