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
                #link_directories(/usr/lib)


set(SOURCE_FILES main.cpp Utils/SshConnection.cpp Utils/SshConnection.h lbcmsCommon.h Utils/Logger.cpp Utils/Logger.h lbcmsException.cpp lbcmsException.h Utils/SystemUtils.cpp Utils/SystemUtils.h Utils/FileManager/FileBase.cpp Utils/FileManager/FileBase.h Utils/FileManager/ConfigFile.cpp Utils/FileManager/ConfigFile.h)
add_executable(ClioTest ${SOURCE_FILES} )
TARGET_LINK_LIBRARIES(ClioTest ssh)