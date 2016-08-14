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
                    Logger::logError("Connections interrupted");
                     try{
                        (*m_sock.get()).shutdown(boost::asio::ip::tcp::socket::shutdown_both);
                        (*m_sock.get()).close();
                    }catch (boost::system::system_error& e){
                        Logger::logError("Error while closing the connection");
                    }
                    m_sock.reset();
                }
            }));
        }
        void Service::Stop() {

        }

        Service::~Service() {
            std::cout<<"Deleting the service object "<<std::endl;
        }
        std::string Service::GiveResult(std::string message) {
            std::string result = "Hello World\n";
            return result;
        }
    }
}