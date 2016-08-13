//
// Created by lahmer on 8/12/16.
//

#ifndef CLIOTEST_SYNCTCPCLIENT_H
#define CLIOTEST_SYNCTCPCLIENT_H

#include "../../lbcmsCommon.h"
namespace lbcms{
    namespace network {
        class SyncTcpClient{
        public:
            ///This method is optionnal , it connects to the server
            void Connect();
            ///This method is optionnal , it closes the connection
            void Close();
            ///This method send a message to the server
            ///the method take care of adding a /n at the end of the message if it does'nt exists
            ///@param msg [in] The message that will be send
            void SendMessage(const std::string& msg) ;
            ///This method recieve a message from the server
            std::string RecieveMessage();

            ~SyncTcpClient();


            SyncTcpClient(std::string ipv4 , int port );

        private:
            boost::asio::ip::tcp::endpoint* m_endPoint;
            boost::asio::io_service* m_ios;
            boost::asio::ip::tcp::socket* m_socket;
        };
    }
}

#endif //CLIOTEST_SYNCTCPCLIENT_H
