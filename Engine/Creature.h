#pragma once
#include "Entity.h"
#include <string>

class Creature : public Entity
{
public:
	Creature(const std::vector<Vec2> & model,  std::string creatureType, int maxHp, float attackDmg, const Vec2 & pos = { 0.f, 0.f }, const Color & c = Colors::Green);
	int GetMaxHp() const;
	void SetMaxHp(int hp);
private:
	std::string m_creatureType;
	int m_maxHp;
	float m_attackDmg;

};