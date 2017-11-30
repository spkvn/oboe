#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include <SDL2/SDL_image.h>
#include <map>

class TextureManager
{
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
	TextureManager() {}

public:
	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip filp = SDL_FLIP_NONE); 
	void drawFrame(std::string id, int x, int y, int width,  int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static TextureManager* instance(); 
	void clearFromTextureMap(std::string id);
};

//defining singleton.
typedef TextureManager TheTextureManager;

#endif	//TEXTUREMANAGER_H