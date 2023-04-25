cmake_minimum_required(VERSION 3.25)
<<<<<<< HEAD
project(space-ship)

set(CMAKE_CXX_STANDARD 17)

add_executable(space-ship main.cpp Framework.cpp Game.cpp Player.cpp Shot.cpp Sprite.cpp Timer.cpp Asteroid.cpp)

=======
project(space_ship)

set(CMAKE_CXX_STANDARD 17)

add_executable(space_ship main.cpp Framework.cpp Game.cpp Player.cpp Shot.cpp Sprite.cpp Timer.cpp Asteroid.cpp)
>>>>>>> b523c5694f8ce21ce92f5a1e182d28aa22f7b403

set(SDL2_INCLUDE_DIRS "/usr/include/SDL2")
set(SDL2_LIBRARIES "-L/usr/lib/x86_64-linux-gnu -lSDL2")
include_directories(${SDL2_INCLUDE_DIRS})

<<<<<<< HEAD


target_link_libraries(space-ship ${SDL2_LIBRARIES})
=======
target_link_libraries(space_ship ${SDL2_LIBRARIES})
>>>>>>> b523c5694f8ce21ce92f5a1e182d28aa22f7b403
