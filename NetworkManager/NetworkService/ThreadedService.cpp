//
// Created by lahmer on 8/13/16.
//
#include"ThreadedService.h"

namespace lbcms{
    namespace network{
        void ThreadedService::StartHandelingClient(std::shared_ptr <boost::asio::ip::tcp::socket> sock) {
            std::thread th(([this,sock](){
                HandleClient(sock);
            }));
            th.detach();
        }

        void ThreadedService::HandleClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
            try{
                boost::asio::streambuf buf;
                boost::asio::read_until(*sock.get(),buf,'\n');
                std::cout<<"recieving the message ::\n";
                std::string Response = "Hello , World !\n";
                boost::asio::write(*sock.get(),boost::asio::buffer(Response));
            }catch (boost::system::system_error &e){
                Logger::logError(e.what());
            }
            delete(this);
        }

    }
}
