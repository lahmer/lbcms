//
// Created by lahmer on 8/14/16.
//

#include "HyperVisor.h"

namespace lbcms{
    namespace compute{
        HyperVisor::HyperVisor(int Hypervisor) {
            m_Hypervisor = Hypervisor;
        }
        std::string HyperVisor::getTcpUri() {
            std::string hypervisor;
            switch (m_Hypervisor){
                case HYPERVISOR_QEMU :{
                            hypervisor = "qemu";
                            break;
                }
                default:{
                    Logger::logError("Unrecognized Hypervisor");
                    throw lbcmsException(UNRECOGNIZED_HYPERVISOR);
                }
                }
            std::string URI = hypervisor + "+tcp://"+m_ip+":"+std::to_string(m_port)+"/system";
            return URI;
        }

        void HyperVisor::EstablishTcpConnection(std::string ip , int port) {
            m_ip = ip;
            m_port = port;
            m_connection = virConnectOpen(getTcpUri().c_str());
            if(m_connection == NULL){
                std::string ErrorMessage = "Unable to connect to remote hypervisor URI = "+getTcpUri();
                Logger::logError(ErrorMessage);
                throw lbcmsException(HYPERVISOR_UNREACHABLE);
            }
        }
        void HyperVisor::CloseConnection() {
            virConnectClose(m_connection);
            m_connection = NULL;
         }

        bool HyperVisor::isConnected() {
            if(m_connection == NULL)
                return false;
            int code = virConnectIsAlive(m_connection);
            if(code == 1)
                    return true;
            return false;

        }
    }
}