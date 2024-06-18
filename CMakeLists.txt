cmake_minimum_required(VERSION 3.10)

project(
	PDS_II_DESAFIO_FINAL
	LANGUAGES CXX
	VERSION ${PROJECT_VERSION_PATCH}
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_PREFIX_PATH "C:/vcpkg/installed/x64-windows/share")

find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)

add_executable(main main.cpp "database/Connection.cpp" "model/Book.cpp" "database/Repository.cpp")

target_link_libraries(main PRIVATE mongo::bsoncxx_shared mongo::mongocxx_shared)
