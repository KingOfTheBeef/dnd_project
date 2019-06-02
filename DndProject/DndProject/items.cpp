#include "items.h"

void item::setName(std::string p_name)
{
	m_name = p_name;
}

void item::setDesc(std::string p_desc)
{
	m_desc = p_desc;
}

void item::setType(int p_type)
{
	m_type = p_type;
}

item::item(int p_type)
{
	m_name = "Mysterious Item";
	m_desc = "";
	m_type = p_type;
}

item::item(std::string p_name, std::string p_desc, int p_type)
{
	m_name = p_name;
	m_desc = p_desc;
	m_type = p_type;
}

// --------------- WEAPON

weapon::weapon(int p_atk, int p_dur, std::vector<int> p_effects, int p_type) : item(p_type) {
	m_attack = p_atk;
	m_maxdur = m_dur = p_dur;
	m_effects.insert(m_effects.end(), &p_effects[0], &p_effects[5]);
}

weapon::weapon(std::string p_name, std::string p_desc, int p_atk, int p_dur, std::vector<int> p_effects, int p_type) : item(p_name, p_desc, p_type) {
	m_attack = p_atk;
	m_maxdur = m_dur = p_dur;
	m_effects.insert(m_effects.end(), p_effects.begin(), p_effects.end());
};

void weapon::setDur(int p_dur) {
	if (p_dur > m_maxdur)
	{
		m_dur = m_maxdur;
	}
	else if (p_dur < 0)
	{
		m_dur = 0;
	}
	else
	{
		m_dur = p_dur;
	}
};

int weapon::addEffect(int p_effect) {
/*	if (m_effects.size() > 4)
		return 0;
	else
	{
		m_effects.push_back
	}
	*/
	m_effects.push_back(p_effect);
	return 1;
}