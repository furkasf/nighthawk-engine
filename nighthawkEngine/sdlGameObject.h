#pragma once
#include"gameObject.h"
#include"loadprams.h"
#include"vector2D.h"
#include"TextureManager.h"
#include"Game.h"

class sdlGameObject : public gameObject
{
public:

	sdlGameObject();
    virtual void update() override;
    virtual void draw() override;
    virtual void clean() override;
    virtual void load(const loadPrams* params) override;

	vector2D& getPossition();
	int getWidth();
	int getHeight();

	virtual ~sdlGameObject(){}
protected:

	
	vector2D m_position;
	vector2D m_velocity;
	vector2D m_acceleration;

	//scalle variables
	int m_width;
	int m_height;
	//sellection variables get sprite from spritesheet for animetion
	int m_currentFrame;
	int m_currentRow;

	int m_numFrame;

	int m_callbackID;
	int m_animSpeed;

	//texture id use for sellect texture from texture maanager in texture table(map)
	std::string m_textureId;

};

