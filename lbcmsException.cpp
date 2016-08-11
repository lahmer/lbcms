//
// Created by lahmer on 8/11/16.
//

#include "lbcmsException.h"
namespace lbcms{
    lbcmsException::lbcmsException() {
        this->msg = "Unknown Error ";
    }
    lbcmsException::lbcmsException(int ErrorCode) {
        //TODO::add the messages for each error code
        this->msg = "Hello This message tell you ";
    }
    const char* lbcmsException::what() const throw(){
        return this->msg.c_str();
    }
}