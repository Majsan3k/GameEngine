cmake_minimum_required(VERSION 3.8)
project(GameEngine)

set(CMAKE_CXX_STANDARD 11)

set(SDL C:/Users/majal/Documents/Prog3/SDL2)

include_directories(${SDL}/include)
link_directories(${SDL}/lib)

set(SOURCE_FILES main.cpp engine/GameEngine.cpp engine/GameEngine.h components/Sprite.cpp components/Sprite.h components/Player.cpp components/Player.h frame/Frame.cpp frame/Frame.h components/Item.cpp components/Item.h)
add_executable(GameEngine ${SOURCE_FILES})

target_link_libraries(GameEngine SDL2main SDL2)
target_link_libraries(GameEngine SDL2_image SDL2)