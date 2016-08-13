//
// Created by lahmer on 8/13/16.
//

#include "Service.h"

namespace lbcms{
    namespace network{
        Service::Service(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
            m_sock = sock;
        }
        void Service::StartGivingService() {
            m_ConnectionThread.reset(new std::thread([this](){
                //here we put the method to be executed by the thread
                std::cout<<"Thread Service started"<<std::endl;
                boost::asio::streambuf buf;
                try{
                while(true){
                    boost::asio::read_until(*m_sock.get(),buf,'\n');
                    std::istream inputBuffer(&buf);
                    std::string recievedMessage ;
                    std::getline(inputBuffer,recievedMessage);
                    std::cout<<"recieving a message :"<<recievedMessage<<std::endl;
                    std::string result = GiveResult(recievedMessage);
                    boost::asio::write(*(m_sock.get()),boost::asio::buffer(result));
                }
                }catch (boost::system::system_error& e){
                    Logger::logError(e.what());
                }
            }));
        }
        void Service::Stop() {
            (*m_ConnectionThread.get()).~thread();
            m_sock.reset();
        }
        Service::~Service() {
            Stop();
        }
        std::string Service::GiveResult(std::string message) {
            std::string result = "Hello World\n";
            return result;
        }
    }
}