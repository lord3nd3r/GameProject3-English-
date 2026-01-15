cmake_minimum_required(VERSION 2.8)
project(PressureTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -g -D_CONSOLE -D_CRT_SECURE_NO_WARNINGS -DLINUX64")

# Include directories
include_directories(
    .
    ../../Connector
    ../../../Src
    ../../../Src/ServerEngine
    ../../../Common/protobuf_install/include
    ../../../Src/Message
    ../../../Proto/protoc-gen-cpp
)

# Source files
set(SOURCES
    PressureTest.cpp
    ClientObject.cpp
    ../../Connector/ClientConnector.cpp
    ../../../Src/ServerEngine/CommonFunc.cpp
    ../../../Src/ServerEngine/CommonSocket.cpp
    ../../../Src/ServerEngine/CommonMath.cpp
    ../../../Src/ServerEngine/CommonTime.cpp
    ../../../Src/ServerEngine/Log.cpp
    ../../../Src/ServerEngine/DataBuffer.cpp
    ../../../Src/ServerEngine/md5.cpp
    ../../../Src/ServerEngine/CommonConvert.cpp
)

# Protobuf generated sources (Message and Proto/protoc-gen-cpp)
file(GLOB PROTO_SRCS_MESSAGE "../../../Src/Message/*.pb.cc")
file(GLOB PROTO_SRCS_GEN "../../../Proto/protoc-gen-cpp/*.pb.cc")

# Libs
set(PROTOBUF_LIB "${CMAKE_SOURCE_DIR}/../../../Common/protobuf_install/lib/libprotobuf.a")

add_executable(PressureTest ${SOURCES} ${PROTO_SRCS_MESSAGE} ${PROTO_SRCS_GEN})

target_link_libraries(PressureTest ${PROTOBUF_LIB} pthread dl z)
