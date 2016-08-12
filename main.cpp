
#include"lbcmsCommon.h"

using namespace lbcms ;
int main() {
    //TODO::add a initialisator for the programm which automatically initialise the logger and the wolfssl
    plog::init(plog::debug, "LogFile.txt");
    std::cout<<"Hello World";
    Logger::logError("Hello");
 }