cmake_minimum_required(VERSION 3.0)
project(Glad3)

add_library(Glad3 include/glad/glad.h src/glad.c)
target_include_directories(Glad3 PUBLIC include/)