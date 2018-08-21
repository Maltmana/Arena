#pragma once

#include "pch.h"
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "LogicComponent.h"

class Drawable;

class GWO 
{

public:		

	// Initializes unique_ptr components to null
	GWO();

	// Calls std::move on each parameter
	GWO(std::unique_ptr<GraphicsComponent> graphicsComponent,
		std::unique_ptr<InputComponent> inputComponent,
		std::unique_ptr<LogicComponent> logicComponent);

	// UNIMPLEMENTED Calls update on the graphics component
	void GraphicsUpdate(Camera const & camera) const;

	std::string m_name = { "null" };
	 Vec2 m_position = { 0,0 };
	 float m_scale = 1.0f; // scale is for camera which is also a GWO
	 double m_speed = 100.0;

	std::unique_ptr<GraphicsComponent> m_graphicsComponent;
	std::unique_ptr<LogicComponent> m_logicComponent;
	std::unique_ptr<InputComponent> m_inputComponent;

	template<class Archive>
	void serialize(Archive & archive)
	{
		archive(CEREAL_NVP(m_position.x), CEREAL_NVP(m_scale), CEREAL_NVP(m_speed)); // serialize things by passing them to the archive
	}

	//"template<class Archive> \n "
	//	"  void serialize(Archive & ar) \n "
	//	"  { \n "
	//	"    ar( member1, member2, member3 ); \n "
	//	"  } \n\n " );

};

// we must connect the cereal archive to logicComponents seralize function.
//
//using namespace std;
//
//struct Human
//{
//	string name = "kevin";
//	int age = 22;
//	double BAC = 0.8;
//	string description = "kevin is an amazing bad ass dude whom many people enjoy being around, especially beautiful women.";
//	string hairColor = "blonde";
//
//	template<class Archive>
//	void serialize(Archive & archive)
//	{
//		archive(CEREAL_NVP(name), CEREAL_NVP(age), CEREAL_NVP(BAC), CEREAL_NVP(description));
//	}
//
//};
/*	Human kevin;
char x = 'x';
int someInt;
double d;
*/
