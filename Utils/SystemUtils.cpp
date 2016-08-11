//
// Created by lahmer on 8/11/16.
//

#include "SystemUtils.h"

namespace lbcms{
    bool SystemUtils::isDirectoryExists(std::string path) {
        DIR *directory ;
        directory = opendir(path.c_str());
        if(directory == NULL){
            return false ;
        }else
            closedir(directory);
        return true;
    }

    void SystemUtils::CreateDirectory(std::string path) {
        if(isDirectoryExists(path)){
            std::string ErrorMessage = "Trying to create a directory which already exists :"+path;
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_DIRECTORY_ALREADY_EXISTS);
        }
        int code = mkdir(path.c_str() , S_IRWXU|S_IRWXG|S_IROTH | S_IXOTH);
        if(code == -1){
            std::string ErrorMessage = "Error while trying to create the directoy : " + path;
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_DIRECTORY_CREATE_ERROR);
        }
    }

    bool SystemUtils::isFileExists(std::string path) {
        std::ifstream f(path.c_str());
        return f.good();
    }

    void SystemUtils::CreateFile(std::string path, std::string content) {
        if(isFileExists(path)){
            std::string ErrorMessage = " Trying to create a file whic already exists : "+path;
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_FILE_ALREADY_EXISTS);
        }
        std::ofstream file(path);
        file<<content;
        file.close();
    }

    void SystemUtils::ReplaceFile(std::string path, std::string content) {
        std::ofstream file(path);
        file<<content;
        file.close();
    }
}