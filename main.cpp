
#include"lbcmsCommon.h"
#include<boost/asio.hpp>
using namespace lbcms ;
int main() {
    //TODO::add a initialisator for the programm which automatically initialise the logger and the wolfssl
    plog::init(plog::debug, "LogFile.txt");

    Logger::logError("Error ");
   /* unsigned short port = 1050;
    boost::asio::ip::address ip  = boost::asio::ip::address_v4::any();
    boost::asio::ip::tcp::endpoint ep(ip,port);*/

 }