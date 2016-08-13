//
// Created by lahmer on 8/12/16.
//

#include "SyncTcpClient.h"

namespace lbcms{
    namespace network{
        SyncTcpClient::SyncTcpClient(std::string ipv4, int port){
            m_ios = new boost::asio::io_service();
            m_endPoint = new boost::asio::ip::tcp::endpoint(boost::asio::ip::address_v4::from_string(ipv4),port);
            m_socket = new boost::asio::ip::tcp::socket(*m_ios);
            m_socket->open(m_endPoint->protocol());
        }
        void SyncTcpClient::Connect() {
            m_socket->connect(*m_endPoint);
        }
        void SyncTcpClient::Close() {
            m_socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
            m_socket->close();
        }
        SyncTcpClient::~SyncTcpClient() {
            Close();
            delete m_socket;
            delete m_ios;
            delete m_endPoint;
        }

        void SyncTcpClient::SendMessage(const std::string& msg) {
            std::string result = msg;
            if(result.at(result.length()-1) != '\n')
                result+='\n';
            boost::asio::write(*m_socket , boost::asio::buffer(result));
        }

        std::string SyncTcpClient::RecieveMessage() {
            boost::asio::streambuf buf;
            boost::asio::read_until(*m_socket,buf,'\n');
            std::istream input(&buf);
            std::string response ;
            std::getline(input , response);
            return response;
        }
    }
}