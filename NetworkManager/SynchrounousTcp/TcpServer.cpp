//
// Created by lahmer on 8/13/16.
//

#include "TcpServer.h"
namespace lbcms{
    namespace network{
        TcpServer::TcpServer(unsigned short port) {
            m_port = port;
        }
        unsigned short TcpServer::getPort() {
            return m_port;
        }
        void TcpServer::setPort(unsigned short port) {
            m_port = port;
        }

        void TcpServer::Start() {
            m_handler.reset(new TcpHandler(m_port));
            (*m_handler.get()).Start();
        }

        void TcpServer::Stop() {
            (*m_handler.get()).Stop();
        }

        TcpServer::~TcpServer() {
            m_handler.reset();
        }
    }
}