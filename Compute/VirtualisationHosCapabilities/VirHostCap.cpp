//
// Created by lahmer on 8/14/16.
//

#include "VirHostCap.h"
namespace lbcms{
    namespace compute{
        VirHostCap::VirHostCap(virConnectPtr &ptr) {
            char* temp ;
            //Getting The host name
            temp = virConnectGetHostname(ptr);
            m_hostname = temp;
            //get max number of virtual cpus
            m_vcpus = virConnectGetMaxVcpus(ptr,NULL);
            //Get the node information
            virNodeInfo info;
            virNodeGetInfo(ptr,&info);
            m_cpu_model = info.model;
            m_memory_size = info.memory;
        }
    }
}