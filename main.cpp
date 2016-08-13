
#include"lbcmsCommon.h"
  using namespace lbcms ;
int main() {
    //TODO::add a initialisator for the programm which automatically initialise the logger and the wolfssl
    plog::init(plog::debug, "LogFile.txt");

    network::TcpServer srvr(3333);
    srvr.Start();
    while(true);
}