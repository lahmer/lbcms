//
// Created by lahmer on 8/14/16.
//

#ifndef CLIOTEST_HOSTMANAGER_H
#define CLIOTEST_HOSTMANAGER_H
#include"../lbcmsCommon.h"
namespace lbcms {
    namespace network{
        class TcpServer;
    }
     class RemoteHost;
     class HostManager {
    public:
        static void Init();
        static void AddNewHost(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
    private:
        static std::vector<RemoteHost> m_RemoteHost;
        static network::TcpServer *m_server;
    };
}

#endif //CLIOTEST_HOSTMANAGER_H
