//
// Created by lahmer on 8/14/16.
//

#ifndef CLIOTEST_REMOTEHOST_H
#define CLIOTEST_REMOTEHOST_H

#include "../lbcmsCommon.h"
namespace lbcms {
    class RemoteHost {
    public:
        RemoteHost(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
        std::string getIp();
    private:
        std::shared_ptr<boost::asio::ip::tcp::socket> m_sock ;
        std::string m_ip;

    };
}

#endif //CLIOTEST_REMOTEHOST_H
