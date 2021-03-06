﻿#include "EarthquakeSkill.h"
#include "Player.h"
#include "Monster.h"

EarthquakeSkill::EarthquakeSkill(string skill_name, int use_mp, int power)
{
	this->skill_name = skill_name;
	this->use_mp = use_mp;
	this->power = power;
}

void EarthquakeSkill::UseSkill(Player* player)
{
	if (!(player->GetMp() >= use_mp))
		return;

	vector<Monster*>* monster = Monster::GetInstance();

	player->SetMp(player->GetMp()-use_mp);

	int monsterNumber = monster->size();
	for (int i = 0; i < monster->size(); i++)
	{
		(*monster)[i]->EarthquakeSkillHit(player->GetPos(), power);
		if (monsterNumber != monster->size())	//몬스터죽으면
		{
			i--;
			monsterNumber = monster->size();
		}
	}

	monster = nullptr;
}