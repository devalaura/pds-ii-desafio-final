cmake_minimum_required(VERSION 3.10)

project(MongoDBExam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "C:/Repos/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(main main.cpp "database/Connection.cpp" "model/Book.cpp")

target_link_libraries(main PRIVATE mongo::bsoncxx_shared mongo::mongocxx_shared)
