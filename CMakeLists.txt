cmake_minimum_required(VERSION 3.21)

project(FlightwaveApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Flightwave CONFIG REQUIRED)

file(GLOB_RECURSE APP_SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE APP_HEADERS include/*.h include/*.hpp)

add_executable(
	FlightwaveApp 
	${APP_SOURCES}
	${APP_HEADERS}
)

target_link_libraries(
	FlightwaveApp 
	PRIVATE	Flightwave::Flightwave
)

target_include_directories(FlightwaveApp
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(
	FlightwaveApp 
	PROPERTIES
    OUTPUT_NAME "Flightwave.App"
)
