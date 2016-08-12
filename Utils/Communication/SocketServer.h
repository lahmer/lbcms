//
// Created by lahmer on 8/12/16.
//

#ifndef CLIOTEST_SOCKETSERVER_H
#define CLIOTEST_SOCKETSERVER_H

#include"../../lbcmsCommon.h"
namespace lbcms {
    class SingleThreadedSocketServer {
    private:
        int m_port;
        sockaddr_in m_serverAddress;
        int m_SocketHandler;
        int m_ClientHandler;
        socklen_t m_size;
        //TODO::fix the problem of the buffer size dont leave it as it is
        char m_buffer[1024];
    public:
        ///This Constructor is responsible for initialisating the socket and bid it to the provided
        ///port number
        ///@param port [in] The port number on which the server will listen
        SingleThreadedSocketServer(int port);
        ///This method will listen at the port wiating for a communication comming from a client
        void WaitForClient();
        ///This method will send a message to the connected client
        ///@param msg  a string contains the message to be sent
        void SendMessage(std::string &msg)const;
        std::string RecieveMessage();
    };
}

#endif //CLIOTEST_SOCKETSERVER_H
