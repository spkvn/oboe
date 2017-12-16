#OBJS specifies which files to compile as part of the project 
OBJS = main.cpp Game.cpp Player.cpp Enemy.cpp SDLGameObject.cpp TextureManager.cpp Vector2D.cpp InputHandler.cpp MenuState.cpp PlayState.cpp GameStateMachine.cpp MenuButton.cpp PauseState.cpp AnimatedGraphic.cpp GameOverState.cpp GameObjectFactory.cpp PlayerCreator.cpp StateParser.cpp MainMenuState.cpp MenuButtonCreator.cpp EnemyCreator.cpp AnimatedGraphicCreator.cpp Level.cpp TileLayer.cpp LevelParser.cpp base64.cpp

#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
# -g gives debug info. Allows gdb to add file level breakpoints.
COMPILER_FLAGS = -w -g

#LINKER_FLAGS specifies the libraries we're linking against 
#SDL2, SDL2_Image TinyXML zlib
LINKER_FLAGS = -lSDL2 -lSDL2_image -ltinyxml -lz

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = sdlbook.o

#This is the target that compiles our executable 
all : $(OBJS) 
	  $(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)