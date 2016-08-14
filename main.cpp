
#include"lbcmsCommon.h"
#include<libvirt/libvirt.h>
  using namespace lbcms ;
int main() {
    compute::HyperVisor host(HYPERVISOR_QEMU);
    host.EstablishTcpConnection("192.168.1.102",HYPERVISOR_DEFAULT_TCP_PORT);
    std::cout<<host.isConnected()<<std::endl;
    host.CloseConnection();
    std::cout<<host.isConnected()<<std::endl;

    //HostManager::Init();
    //while(true);
}