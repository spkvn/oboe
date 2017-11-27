#OBJS specifies which files to compile as part of the project 
OBJS = main.cpp Game.cpp Player.cpp Enemy.cpp SDLGameObject.cpp TextureManager.cpp Vector2D.cpp InputHandler.cpp 

#CC specifies which compiler we're using 
CC = g++ 

#COMPILER_FLAGS specifies the additional compilation options we're using 
# -w suppresses all warnings 
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against 
LINKER_FLAGS = -lSDL2 -lSDL2_image

#OBJ_NAME specifies the name of our exectuable 
OBJ_NAME = Movement

#This is the target that compiles our executable 
all : $(OBJS) 
	  $(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)