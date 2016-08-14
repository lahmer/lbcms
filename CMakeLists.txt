cmake_minimum_required(VERSION 3.5)
project(ClioTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#***********************************************************************************************************************
#This part we add the header files directories for the libraries used in this project
#***********************************************************************************************************************
        #add libssh header directories
                INCLUDE_DIRECTORIES(/usr/include)
#***********************************************************************************************************************
#This part is didecated to add the directories of the libraries shared files
#***********************************************************************************************************************
                link_directories(/usr/lib)
                link_directories(/usr/local/lib)


set(SOURCE_FILES
        main.cpp
        lbcmsCommon.h
        Utils/Logger.cpp Utils/Logger.h
        lbcmsException.cpp lbcmsException.h
        Utils/SystemUtils.cpp Utils/SystemUtils.h
        Utils/FileManager/FileBase.cpp Utils/FileManager/FileBase.h
        Utils/FileManager/ConfigFile.cpp Utils/FileManager/ConfigFile.h
        NetworkManager/SynchrounousTcp/SyncTcpClient.cpp NetworkManager/SynchrounousTcp/SyncTcpClient.h
        NetworkManager/SynchrounousTcp/TcpServer.cpp NetworkManager/SynchrounousTcp/TcpServer.h NetworkManager/SynchrounousTcp/TcpHandler.cpp NetworkManager/SynchrounousTcp/TcpHandler.h NetworkManager/SynchrounousTcp/Service.cpp NetworkManager/SynchrounousTcp/Service.h Manager/HostManager.cpp Manager/HostManager.h Manager/RemoteHost.cpp Manager/RemoteHost.h Compute/HyperVisor.cpp Compute/HyperVisor.h Compute/VirtualisationHosCapabilities/VirHostCap.cpp Compute/VirtualisationHosCapabilities/VirHostCap.h Compute/VirtualisationHosCapabilities/VirHostStat.cpp Compute/VirtualisationHosCapabilities/VirHostStat.h)
add_executable(ClioTest ${SOURCE_FILES} )
TARGET_LINK_LIBRARIES(ClioTest config++ boost_system boost_thread virt pthread)