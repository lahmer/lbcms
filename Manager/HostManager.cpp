//
// Created by lahmer on 8/14/16.
//

#include "HostManager.h"
namespace lbcms{
    std::vector<RemoteHost> HostManager::m_RemoteHost;

    void HostManager::AddNewHost(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
        //Verify if the host already exists
        bool exists = false;
        for(int i = 0 ; i <  m_RemoteHost.size() ; i++){
            std::cout<<"        Testing the ip "<<m_RemoteHost.at(i).getIp()<<std::endl;
            if(m_RemoteHost.at(i).getIp()==sock.get()->remote_endpoint().address().to_string()){
                Logger::logError("Trying to add an existing connection verify the problem ");
                exists = true;
                break;
            }
        }
        if(!exists){
            m_RemoteHost.push_back(RemoteHost(sock));
        }
    }
    void HostManager::Init() {
        plog::init(plog::debug, "LogFile.txt");
    }
}