//
// Created by lahmer on 8/14/16.
//

#ifndef CLIOTEST_LIBVIRTHOST_H
#define CLIOTEST_LIBVIRTHOST_H
#include "../lbcmsCommon.h"
namespace lbcms {
    namespace compute {
        class HyperVisor {
        public:
            HyperVisor(int Hypervisor);
            void EstablishTcpConnection(std::string ip ,int port );
            void CloseConnection();
            bool isConnected();
        private:
            std::string getTcpUri();
        private:
            std::string m_ip;
            int m_port;
            virConnectPtr  m_connection;
            int m_Hypervisor;
        };
    }
}

#endif //CLIOTEST_LIBVIRTHOST_H
