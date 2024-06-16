cmake_minimum_required(VERSION 3.10)

project(MongoDBExam)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_TOOLCHAIN_FILE "C:/Repos/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/Repos/vcpkg/installed/x64-windows/share/mongocxx;C:/Repos/vcpkg/installed/x64-windows/share/bsoncxx")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules")
set(mongoc-1.0_DIR "C:/Repos/vcpkg/installed/x64-windows/share/mongoc-1.0")
set(bson-1.0_DIR "C:/Repos/vcpkg/installed/x64-windows/share/bson-1.0")


find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(main main.cpp "database/Connection.cpp" "model/Book.cpp" "database/Repository.cpp")

target_link_libraries(main PRIVATE mongo::bsoncxx_shared mongo::mongocxx_shared)
