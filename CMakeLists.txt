cmake_minimum_required(VERSION 3.22)
set(project_name wlc-backend)
project(${project_name} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
add_library(${project_name}-lib
        src/AppComponent.hpp
        src/DatabaseComponent.hpp
        src/controller/AdminController.hpp src/db/WlcDb.hpp src/service/AdminService.hpp src/service/UserService.hpp src/service/User.hpp)

target_include_directories(${project_name}-lib PUBLIC src)
## link libs
find_package(oatpp              1.3.0 REQUIRED)
find_package(oatpp-postgresql   1.3.0 REQUIRED)
find_package(oatpp-swagger      1.3.0 REQUIRED)
find_package(oatpp-curl         1.3.0 REQUIRED)
find_package(Boost              1.70.0 COMPONENTS ALL)
find_package(OpenSSL REQUIRED)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-curl
        PUBLIC oatpp::oatpp-postgresql
        PUBLIC oatpp::oatpp-swagger
        PUBLIC OpenSSL::SSL
        )

add_definitions(
        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"

        ## Path to database migration scripts
        -DDATABASE_MIGRATIONS="${CMAKE_CURRENT_SOURCE_DIR}/sql"
)
############################################################################

add_executable(${project_name}-exe
        src/App.cpp src/App.cpp src/AppComponent.hpp)
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

