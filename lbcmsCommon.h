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
#include"Utils/Communication/TlsServer.h"
#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include"Utils/Communication/SocketServer.h"
#include<exception>




#define LBCMS_Utils_SSH_CONNECTION_ERROR                0x10000
#define LBCMS_UTILS_SSH_AUTHENIFICATION_ERROR           0x10001
#define LBCMS_UTILS_DIRECTORY_ALREADY_EXISTS            0x10002
#define LBCMS_UTILS_DIRECTORY_CREATE_ERROR              0x10003
#define LBCMS_UTILS_FILE_ALREADY_EXISTS                 0x10004
#define LBCMS_UTILS_CONFIG_FILE_READ_ERROR              0x10005
#define LBCMS_UTILS_CONFIG_PARSE_ERROR                  0x10006
#define LBCMS_UTILS_COMMUNICATION_SOCKET_ERROR          0x10007
#define LBCMS_UTILS_COMMUNICATION_SOCKET_BIND_ERROR     0x10008
#define LBCMS_UTILS_COMMUNICATION_CLIENT_ERROR          0x10009
#define LBCMS_UTILS_COMMUNICATION_MESSAGE_SIZE_OVERFLOW 0x10010
#define LBCMS_UTILS_COMMUNICATION_RECIEVE_ERROR         0x10011

#define LBCMS_UTILS_COMMUNICATION_SOCKETSERVER_BUFFER_SIZE          1024


#define LBCMS_DEBUG
#endif //CLIOTEST_LBCMSCOMMON_H
