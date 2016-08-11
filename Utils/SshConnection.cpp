//
// Created by lahmer on 8/10/16.
//

#include "SshConnection.h"
namespace lbcms{
    SshConnection::SshConnection(std::string ip, int port,std::string user , std::string password) {
        this->ip = ip ;
        this->port = port ;
        this->user = user;
        this->password = password;
        this->session = new ssh::Session();
        this->channel = new ssh::Channel(*session);
        Logger::logDebug("Connecting to host @"+ip);
    }
    ssh::Session* SshConnection::getSession() {
        return session;
    }
    void SshConnection::Connect() {
        session->setOption(SSH_OPTIONS_HOST , ip.c_str());
        session->setOption(SSH_OPTIONS_PORT , &port);
        int code = session->connect();
        if(code != SSH_OK){
            std::string errorMsg;
            errorMsg = "can't connect to the host at @=" + ip +"Try to ping it";
            Logger::logError(errorMsg);
            throw lbcmsException(LBCMS_Utils_SSH_CONNECTION_ERROR);
        }
        //now we provide information of authentification
        session->setOption(SSH_OPTIONS_USER , user.c_str());
        code = session->userauthPassword(password.c_str());
        if (code != SSH_AUTH_SUCCESS){
            std::string errorMsg = "error while trying to authenticate to server @="+ip+" and user = "+user + " and password = "+password;
            Logger::logError(errorMsg);
            throw lbcmsException(LBCMS_UTILS_SSH_AUTHENIFICATION_ERROR);
        }
    }
    int SshConnection::getPort() {
        return port;
    }
    void SshConnection::Disconnect() {
        session->disconnect();
     }
    SshConnection::~SshConnection() {
        Disconnect();
        delete session;
    }
    ssh::Channel* SshConnection::getChannel() {
        return this->channel;
    }
    std::string SshConnection::executeRemoteCommand(std::string cmd) {
        std::string msgResult ;
        channel->openSession();
        channel->requestExec(cmd.c_str());
        char buffer[256];
        int nbyte = channel->read(buffer,sizeof(buffer),false);
        while(nbyte > 0){
            for(int i = 0 ; i < nbyte ; i++)
                msgResult+=buffer[i];
            nbyte = channel->read(buffer,sizeof(buffer),false);
        }
        if(nbyte < 0){
            std::string ErrorMessage = "Error while excecuting the remote command @"+cmd+"@  via ssh at the host @="+ip;
            Logger::logError(ErrorMessage);
        }else{
            std::string DebugMessage = "Executing the command "+cmd+" via ssh at host @ = "+ip;
            Logger::logDebug(DebugMessage);
        }
        return msgResult;
    }

}