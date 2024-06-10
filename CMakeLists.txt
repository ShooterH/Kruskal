cmake_minimum_required(VERSION 3.15)

#set the project name
project(Kruskal)

set(SRC_LIST 
        src/Kruskal.c
        inc/linkedlist.c
	inc/graph_matrix.c)
#add the executable
add_executable(${PROJECT_NAME} 
               ${SRC_LIST})

target_include_directories(${PROJECT_NAME} 
                           PRIVATE 
                           ${PROJECT_SOURCE_DIR}/inc)