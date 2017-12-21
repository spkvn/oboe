#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";  

void PlayState::update()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

}

void PlayState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	StateParser stateParser;
	stateParser.parseState("../conf/oboePlay.xml", s_playID, &m_gameObjects, &m_textureIDList);

	std::cout << "entering PlayState" << std::endl;
	return true;
}

bool PlayState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++ )
	{
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();

	//clear texture manager.
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TheTextureManager::instance()->clearFromTextureMap(m_textureIDList[i]);
	}

	std::cout << "exiting PlayState" << std::endl;
	return true;
}