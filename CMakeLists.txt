# CMakeList.txt : CMake project for DoublyLinkedList1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("NourUtilList")

# Add source to this project's executable.
add_executable (NourUtilList 
	"main.cpp" 
	"utillist.cpp" 
	"utillist.h" 
	"my_extras.h"
)

# TODO: Add tests and install targets if needed.
