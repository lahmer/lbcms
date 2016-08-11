//
// Created by lahmer on 8/11/16.
//

#ifndef CLIOTEST_LBCMSEXCEPTION_H
#define CLIOTEST_LBCMSEXCEPTION_H

#include"lbcmsCommon.h"
#include<exception>
namespace lbcms {
    class lbcmsException : public std::exception {
    private:
        std::string msg ;
    public:
        lbcmsException();
        lbcmsException(int ErrorCode);
        virtual const char* what() const throw();
    };
}

#endif //CLIOTEST_LBCMSEXCEPTION_H
