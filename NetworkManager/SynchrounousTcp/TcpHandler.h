//
// Created by lahmer on 8/13/16.
//

#ifndef CLIOTEST_TCPHANDLER_H
#define CLIOTEST_TCPHANDLER_H

#include <list>
#include"../../lbcmsCommon.h"
class Service;
namespace lbcms {
    namespace network {
        class TcpHandler {
        public:
            TcpHandler(unsigned short port);
            ~TcpHandler();
            void Stop();
            void Start();
             void SpawnThread(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
        private:
            unsigned short m_port;
            std::unique_ptr<std::thread> m_MainThread;
            std::vector<Service> m_ConnectionsThreads;
            boost::asio::io_service* m_ios;
            boost::asio::ip::tcp::acceptor  *m_acceptor;
            boost::asio::ip::tcp::endpoint *m_ep;
        };
    }
}

#endif //CLIOTEST_TCPHANDLER_H
