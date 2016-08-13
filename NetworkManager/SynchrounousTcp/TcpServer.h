//
// Created by lahmer on 8/13/16.
//

#ifndef CLIOTEST_TCPSERVER_H
#define CLIOTEST_TCPSERVER_H

#include <bits/unique_ptr.h>
#include "../../lbcmsCommon.h"

namespace lbcms {
    namespace network {
        class TcpHandler;
        ///This class provide an implementation of a synchrounous multithreded tcp server
        ///at the start of the server, it will create a thread that will handle all the coming
        ///connection at a port each time a connection came the thread will create another thread
        ///that will keep a link with the connection and satisfies all the demandes until the connection
        ///is interrupted
        class TcpServer {
        public:
            TcpServer(unsigned short port);
            void Start();
            void Stop();
            unsigned short getPort();
            void setPort(unsigned short);
            ~TcpServer();
        private:
            unsigned short m_port;
            std::unique_ptr<TcpHandler> m_handler;
        };
    }
}

#endif //CLIOTEST_TCPSERVER_H
