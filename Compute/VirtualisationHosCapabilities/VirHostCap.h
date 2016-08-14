//
// Created by lahmer on 8/14/16.
//

#ifndef CLIOTEST_VIRHOSTCAP_H
#define CLIOTEST_VIRHOSTCAP_H
#include"../../lbcmsCommon.h"
namespace lbcms {
    namespace compute {
        ///This class contains inforamtion about the virtualisation host capabilities
        ///Those information does'nt change across time like cpu version and ram size...
        class VirHostCap {
        public:
            VirHostCap(virConnectPtr& ptr);
            std::string m_hostname;
            int m_vcpus;
            std::string m_cpu_model;
            unsigned long  m_memory_size;
        };
    }
}

#endif //CLIOTEST_VIRHOSTCAP_H
