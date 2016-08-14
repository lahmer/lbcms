//
// Created by lahmer on 8/10/16.
//

#ifndef CLIOTEST_LBCMSCOMMON_H
#define CLIOTEST_LBCMSCOMMON_H

#include<plog/Log.h>
#include <iostream>
#include<libssh/libsshpp.hpp>
#include <fstream>
#include<libconfig.h++>
#include<exception>
#include <boost/asio.hpp>
#include<thread>
#include<libvirt/libvirt.h>


#include "lbcmsException.h"
#include"Utils/Logger.h"
#include "Utils/SystemUtils.h"
#include"Utils/FileManager/FileBase.h"
#include"NetworkManager/SynchrounousTcp/SyncTcpClient.h"
#include<libvirt/libvirt.h>
#include "NetworkManager/SynchrounousTcp/TcpHandler.h"
#include"NetworkManager/SynchrounousTcp/TcpServer.h"
#include"NetworkManager/SynchrounousTcp/Service.h"
#include"Manager/HostManager.h"
#include "Manager/RemoteHost.h"
#include "Compute/HyperVisor.h"


#define LBCMS_UTILS_DIRECTORY_ALREADY_EXISTS            0x10002
#define LBCMS_UTILS_DIRECTORY_CREATE_ERROR              0x10003
#define LBCMS_UTILS_FILE_ALREADY_EXISTS                 0x10004
#define LBCMS_UTILS_CONFIG_FILE_READ_ERROR              0x10005
#define LBCMS_UTILS_CONFIG_PARSE_ERROR                  0x10006


            #define HYPERVISOR_QEMU                                 0x10007
            #define UNRECOGNIZED_HYPERVISOR                         0x10008
#define HYPERVISOR_UNREACHABLE                          0x10009
#define HYPERVISOR_DEFAULT_TCP_PORT                     16509


#define LBCMS_DEBUG
#endif //CLIOTEST_LBCMSCOMMON_H
