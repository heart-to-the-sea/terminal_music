cmake_minimum_required(VERSION 3.13)

# 项目名
project(terminal_music)



# include(FetchContent)
# set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
# FetchContent_Declare(ftxui
#   GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
#   GIT_TAG main # Important: Specify a version or a commit hash here.
# )
# FetchContent_MakeAvailable(ftxui)



# 指定包含的目录
include_directories(${CMAKE_SOURCE_DIR}/library/ftxui)
# link_directories(${CMAKE_SOURCE_DIR}/library/ftxui/lib)

add_subdirectory(${CMAKE_SOURCE_DIR}/library/ftxui)


# 查找当前目录下的所有源文件 并添加到 DIR_SRCS 变量
aux_source_directory(./src SRC)

# 编译入口
add_executable(terminal_music ${SRC})


target_link_libraries(terminal_music 
PRIVATE ftxui::screen 
PRIVATE  ftxui::dom
PRIVATE ftxui::component)
