//
// Created by lahmer on 8/13/16.
//

#ifndef CLIOTEST_SERVICE_H
#define CLIOTEST_SERVICE_H
#include"../../lbcmsCommon.h"
namespace lbcms {
    namespace network {
        class Service {
        public:
            Service(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
            void StartGivingService();
            void Stop();
            std::string GiveResult(std::string message);
            ~Service();
        private:
            std::unique_ptr<std::thread> m_ConnectionThread;
            std::shared_ptr<boost::asio::ip::tcp::socket> m_sock;
        };
    }
}

#endif //CLIOTEST_SERVICE_H
