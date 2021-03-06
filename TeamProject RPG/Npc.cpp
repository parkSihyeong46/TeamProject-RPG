﻿#include "Npc.h"

Npc* Npc::npc = nullptr;

Npc* Npc::GetInstance()
{
	if (npc == nullptr)
		npc = new Npc();

	return npc;
}

void Npc::ReleaseInstance()
{
	delete npc;
	npc = nullptr;
}

const Pos& Npc::GetPos() const
{
	return pos;
}

void Npc::SetPos(const int& x, const int& y)
{
	pos.SetX(x);
	pos.SetY(y);
}

array<int, 2> Npc::OpenShop(const int& playerXPosition, const int& playerYPosition, const int& playerDirection)
{
	//구매한 아이템
	array<int, 2> item{ Shop::EXIT , -1 };

	//피격여부
	bool isAttacked = false;

	//타점
	int attackXPosition = 0;
	int attackYPosition = 0;

	//NPC위치
	int NPCXPosition = this->GetPos().GetX();
	int NPCYPosition = this->GetPos().GetY() + 2;

	//플레이어보는방향에 따라서 공격위치설정
	if (playerDirection == NpcCheck::RIGHT)
	{
		attackXPosition = playerXPosition + 3;
		attackYPosition = playerYPosition - 1;
	}
	else if (playerDirection == NpcCheck::LEFT)
	{
		attackXPosition = playerXPosition - 5;
		attackYPosition = playerYPosition - 1;
	}

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y >= -2; y--)
		{
			if ((attackXPosition == NPCXPosition + y) && (attackYPosition == NPCYPosition - 2 + x))
			{
				isAttacked = true;
			}
		}
	}

	if (isAttacked == true)
		item = shopUI.SelectUI();

	return item;		//구매한물건번호리턴
}