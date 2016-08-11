//
// Created by lahmer on 8/10/16.
//

#ifndef CLIOTEST_SSHCONNECTION_H
#define CLIOTEST_SSHCONNECTION_H
#include"libssh/libsshpp.hpp"
#include "../lbcmsCommon.h"
namespace lbcms{
class SshConnection {
private:
    ssh::Session *session;
    ssh::Channel *channel;
    int port ;
    std::string ip;
    std::string user;
    std::string password;
public:
    SshConnection(std::string ip , int port ,std::string user , std::string password);
    ~SshConnection();
    ssh::Session* getSession();
    int getPort();
    void Connect();
    void Disconnect();
    ssh::Channel* getChannel();
    std::string executeRemoteCommand(std::string cmd);
};
}



#endif //CLIOTEST_SSHCONNECTION_H
