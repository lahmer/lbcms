//
// Created by lahmer on 8/12/16.
//

#include "SocketServer.h"

namespace lbcms{

    SingleThreadedSocketServer::SingleThreadedSocketServer(int port) {
        m_SocketHandler = socket(AF_INET,SOCK_STREAM,0);
        if(m_SocketHandler < 0){
            std::string ErrorMessage = "Error establishing the socket";
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_COMMUNICATION_SOCKET_ERROR);
        }
        //now the socket server is created
        m_serverAddress.sin_family = AF_INET;
        m_serverAddress.sin_addr.s_addr = htons(INADDR_ANY);
        m_serverAddress.sin_port = htons(m_port);
        int code = bind(m_SocketHandler , (sockaddr*)&m_serverAddress,sizeof(m_serverAddress));
        if(code < 0 ){
            std::string ErrorMessage = "Error binding the the socket server to the port " + m_port;
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_COMMUNICATION_SOCKET_BIND_ERROR);
        }
        m_size = sizeof(m_serverAddress);
     }

    void SingleThreadedSocketServer::WaitForClient() {
        listen(m_SocketHandler , 1 );
        m_ClientHandler = accept(m_SocketHandler,(struct sockaddr * )&m_serverAddress,&m_size);
        if(m_ClientHandler < 0){
            std::string ErrorMessage = "Error Establishing communication with client ";
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_COMMUNICATION_CLIENT_ERROR);
        }
    }
    void SingleThreadedSocketServer::SendMessage(std::string& msg)const {
        if(msg.length() > LBCMS_UTILS_COMMUNICATION_SOCKETSERVER_BUFFER_SIZE){
            std::string ErrorMessage = "Trying to send a message with a bigger length than the buffer max size length = " + msg.length();
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_COMMUNICATION_MESSAGE_SIZE_OVERFLOW);
        }
        send(m_ClientHandler,msg.c_str(),msg.length(),0);
    }
    std::string SingleThreadedSocketServer::RecieveMessage() {
        int nbyte = recv(m_ClientHandler,m_buffer,1024,0);
        if(nbyte < 0 ){
            std::string ErrorMessage = "Error While recieving message from the client ";
            Logger::logError(ErrorMessage);
            throw lbcmsException(LBCMS_UTILS_COMMUNICATION_RECIEVE_ERROR);
        }
        std::string result ;
        for (int i = 0; i < nbyte; ++i) {
            result += m_buffer[i];
        }
        return result;
    }
}