
#include"lbcmsCommon.h"
  using namespace lbcms ;
int main() {
    HostManager::Init();
    network::TcpServer srvr(3333);
    srvr.Start();
    while(true);
}