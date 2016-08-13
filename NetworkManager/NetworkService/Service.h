//
// Created by lahmer on 8/13/16.
//

#ifndef CLIOTEST_SERVICE_H
#define CLIOTEST_SERVICE_H
#include"../../lbcmsCommon.h"
namespace lbcms{
    namespace network {
        ///This class provide a base class for the non multithreaded network service
        ///all network service should extend from this class and override
        ///the method HandleClient
        class Service {
        public:
            Service();
            ///This method should be override by the class that wants to implement a service
            ///@param sock [in] The socket that will communicate with
            void HandleClient(boost::asio::ip::tcp::socket& sock);
        };
    }
}

#endif //CLIOTEST_SERVICE_H
