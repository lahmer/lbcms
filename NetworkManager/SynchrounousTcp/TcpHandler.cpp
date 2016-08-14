//
// Created by lahmer on 8/13/16.
//

#include "TcpHandler.h"
namespace lbcms{
    namespace network{
        TcpHandler::TcpHandler(unsigned short port) {
            m_port = port;
            m_ios = new boost::asio::io_service();
            m_ep = new boost::asio::ip::tcp::endpoint(boost::asio::ip::address_v4::any(),m_port);
            m_acceptor = new boost::asio::ip::tcp::acceptor(*m_ios , *m_ep);
        }
        void TcpHandler::Start() {
            unsigned short port = m_port;
                m_MainThread.reset(new std::thread([this](){
                    std::cout<<"Starting tcp handler new thread"<<std::endl;
                    m_acceptor->listen();
                    while(true){
                        std::shared_ptr<boost::asio::ip::tcp::socket> sock ;
                        sock.reset(new boost::asio::ip::tcp::socket(*m_ios));
                        m_acceptor->accept(*(sock.get()));
                        HostManager::AddNewHost(sock);
                     }
                }));
        }
        void TcpHandler::Stop() {

        }
        TcpHandler::~TcpHandler() {

        }
    }
}