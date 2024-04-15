cmake_minimum_required(VERSION 3.13)

# 项目名
project(terminal_music)



include_directories(${CMAKE_SOURCE_DIR}/exec/ftxui/include)
link_directories(${CMAKE_SOURCE_DIR}/lib/ftxui)

# 查找当前目录下的所有源文件 并添加到 DIR_SRCS 变量
aux_source_directory(. SRC)

# 编译入口
add_executable(terminal_music ${SRC})


target_link_libraries(terminal_music ftxui-component)
target_link_libraries(terminal_music ftxui-dom)
target_link_libraries(terminal_music ftxui-screen)