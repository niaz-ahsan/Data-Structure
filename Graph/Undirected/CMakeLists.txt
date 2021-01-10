cmake_minimum_required(VERSION "3.7.1")

set(CMAKE_CXX_STANDARD 17)

# We're giving a name to our project and this name is accessible via "${PROJECT_NAME}"
project("undirected_graph") 

# Compiling all files inside "src" dir
add_executable(${PROJECT_NAME} src/main.cpp src/person.cpp src/graph.cpp)