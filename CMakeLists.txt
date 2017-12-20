cmake_minimum_required(VERSION 3.9)
project(oboe)

#append ./cmake to CMAKE_MODULE_PATH
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(TinyXML REQUIRED)
find_package(ZLIB REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} ${TINYXML_INCLUDE_DIR} ${ZLIB_INCLUDE_DIRS})


set(CMAKE_CXX_STANDARD 11)

add_executable(oboe main.cpp
                AnimatedGraphic.cpp
                AnimatedGraphicCreator.cpp
                base64.cpp
                Enemy.cpp
                EnemyCreator.cpp
                Game.cpp
                GameObjectFactory.cpp
                GameOverState.cpp
                GameState.h
                GameStateMachine.cpp
                InputHandler.cpp
                Level.cpp
                LevelParser.cpp
                MainMenuState.cpp
                MenuButton.cpp
                MenuButtonCreator.cpp
                MenuState.cpp
                PauseState.cpp
                Player.cpp
                PlayerCreator.cpp
                PlayState.cpp
                SDLGameObject.cpp
                StateParser.cpp
                TextureManager.cpp
                TileLayer.cpp
                Vector2D.cpp
        )

target_link_libraries(oboe ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${TINYXML_LIBRARIES} ${ZLIB_LIBRARIES})