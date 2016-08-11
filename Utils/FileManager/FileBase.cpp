//
// Created by lahmer on 8/11/16.
//

#include "FileBase.h"
namespace lbcms{
    FileBase::FileBase(std::string path) {
        m_path = path;
        m_file = fopen(path.c_str() , "rw");
    }
    FILE* FileBase::getFileHandler() {
        return m_file;
    }
    std::string FileBase::getPath() {
        return m_path;
    }
    void FileBase::closeFile() {
        fclose(m_file);
    }
}