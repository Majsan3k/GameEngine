cmake_minimum_required(VERSION 3.8)
project(GameEngine)

set(CMAKE_CXX_STANDARD 11)

set(SDL C:/Users/majal/Documents/Prog3/SDL2)

include_directories(${SDL}/include)
link_directories(${SDL}/lib)

set(SOURCE_FILES game/main.cpp engine/GameEngine.cpp engine/GameEngine.h components/Sprite.cpp components/Sprite.h frame/Frame.cpp frame/Frame.h components/Button.cpp components/Button.h components/Label.cpp components/Label.h components/Movable.cpp components/Movable.h game/Player.cpp game/Item.cpp game/Item.h game/Player.h game/SoundButton.cpp game/SoundButton.h)
add_executable(GameEngine ${SOURCE_FILES})

target_link_libraries(GameEngine SDL2main SDL2)
target_link_libraries(GameEngine SDL2_image SDL2)
target_link_libraries(GameEngine SDL2_mixer SDL2)
target_link_libraries(GameEngine SDL2_ttf SDL2)