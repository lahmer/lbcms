//
// Created by lahmer on 8/13/16.
//

#ifndef CLIOTEST_THREADEDSERVICE_H
#define CLIOTEST_THREADEDSERVICE_H

#include "../../lbcmsCommon.h"
namespace lbcms{
    namespace network {
        ///This class provide an interface for a service who will be done in a single thread

        class ThreadedService {
        public:
            ThreadedService();
            void StartHandelingClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock);

            void HandleClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
        };
    }
}

#endif //CLIOTEST_THREADEDSERVICE_H
