
#include"lbcmsCommon.h"

using namespace lbcms ;
int main() {
    //TODO::add a initialisator for the programm which automatically initialise the logger
    plog::init(plog::debug, "LogFile.txt");
    std::cout<<"Hello World";

 }