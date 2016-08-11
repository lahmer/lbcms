//
// Created by lahmer on 8/10/16.
//

#ifndef CLIOTEST_LBCMSCOMMON_H
#define CLIOTEST_LBCMSCOMMON_H

#include<plog/Log.h>
#include"Utils/Logger.h"
#include "lbcmsException.h"
#include <iostream>
#include<libssh/libsshpp.hpp>
#include"Utils/SshConnection.h"
#include "Utils/SystemUtils.h"
#include <fstream>
#include"Utils/FileManager/FileBase.h"
#include<libconfig.h++>
#include"Utils/FileManager/FileBase.h"




#define LBCMS_Utils_SSH_CONNECTION_ERROR                0x10000
#define LBCMS_UTILS_SSH_AUTHENIFICATION_ERROR           0x10001
#define LBCMS_UTILS_DIRECTORY_ALREADY_EXISTS            0x10002
#define LBCMS_UTILS_DIRECTORY_CREATE_ERROR              0x10003
#define LBCMS_UTILS_FILE_ALREADY_EXISTS                 0x10004
#define LBCMS_UTILS_CONFIG_FILE_READ_ERROR              0x10005
#define LBCMS_UTILS_CONFIG_PARSE_ERROR                  0x10006
#define yes

#define LBCMS_DEBUG
#endif //CLIOTEST_LBCMSCOMMON_H
