#include <string>
#include <vector>

enum effect {
	NONE = 0,
	STUN = 1,
	PUSH = 2
};

enum type {
	WEAPON = 0,
	MISC = 1
};

class item
{
public:
	item(int p_type = type::MISC);
	item(std::string p_name, std::string p_desc, int p_type = type::MISC);


	void setName(std::string p_name);
	void setDesc(std::string p_desc);
	void setType(int type);

	std::string getName() { return m_name; }
	std::string getDesc() { return m_desc; }
	int getType() { return m_type; }

private:
	std::string m_name, m_desc;
	int m_type;
};


class weapon : public item
{
public:
	weapon(int p_atk, int p_dur, std::vector<int> p_effects = {0, 0, 0, 0, 0}, int p_type = type::WEAPON);
	weapon(std::string p_name, std::string p_desc, int p_atk, int p_dur, std::vector<int> p_effects = { 0, 0, 0, 0, 0 }, int p_type = type::WEAPON);

	int getAtk() { return m_attack; }
	int getDur() { return m_dur; }
	std::vector<int> getEffects() { return m_effects; }

	void setDur(int newDurability);
	int addEffect(int newEffect);

private:
	int m_dur, m_maxdur, m_type, m_attack;
	std::vector<int> m_effects;
};