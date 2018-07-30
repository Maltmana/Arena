#include "Creature.h"

Creature::Creature(const std::vector<Vec2>& model, std::string creatureType, int maxHp, float attackDmg, const Vec2 & pos, const Color & c)
	:
	Entity(model, pos, c)
{}

int Creature::GetMaxHp() const
{
	return m_maxHp;
}

void Creature::SetMaxHp(int hp)
{
	m_maxHp = hp;
}

