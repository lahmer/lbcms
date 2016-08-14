//
// Created by lahmer on 8/14/16.
//

#include "RemoteHost.h"
namespace lbcms{
    RemoteHost::RemoteHost(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
        m_sock = sock;
        m_ip = sock.get()->remote_endpoint().address().to_string();
        std::cout<<"A new Host detected with the address "<<m_ip<<std::endl;
    }
    std::string RemoteHost::getIp() {
        return m_ip;
    }
}