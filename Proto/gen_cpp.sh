#!/bin/bash
/home/ender/GameProject3/Server/Common/protobuf-3.12.4/src/protoc -I=./proto_raw --cpp_out=./protoc-gen-cpp ./proto_raw/*.proto
cp -rf ./protoc-gen-cpp/*.* ../Server/Src/Message 