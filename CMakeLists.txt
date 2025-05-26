cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)

project(galaxii LANGUAGES CXX C VERSION 0.1)

add_executable(galaxii
	./src/Bdl.cpp
	./src/Main.cpp

	./src/Bdl.hpp
	./src/Inf1.hpp
)
