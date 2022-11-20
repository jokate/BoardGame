#pragma once
#include "Cell.h"
#include "Map.h"
#include "Card.h"
#include <vector>
#include "System.h"
#include <cstdlib>
#include <ctime>


using namespace std;
enum PlayerState {
	Idle = 0, OnBridge, Ended
};

class Player {
private :
	int	OrderofEnded, BridgeCount, Movement, Score, PlayerNumber;
	PlayerState PlyerState;
	vector<Card> cardSet;
	Direction MoveDir[6];
public :
	std::string str;
	Cell CurrentCell;
	bool SelectState;
	Player() {

	}
	Player(int number);
	void RollingDice();
	void GettingCard() {
		if (CurrentCell.GetState() == CardS) {
			Card card = CurrentCell.returnCard();
			if (card.GetCardState() == PhilipsDriver) {
				Score += card.GetScore();
				str = "PhilipsDriver";
			}
			else if (card.GetCardState() == Saw) {
				Score += card.GetScore();
				str = "Saw";
			}
			else if (card.GetCardState() == Hammer) {
				Score += card.GetScore();
				str = "Hammer";
			}
			cardSet.push_back(card); 
		}
		else {
			str = "No";
		}
	}
	void Rest();
	void CountingBridgeCard() {
		BridgeCount = 0;
		for (int i = 0; i < cardSet.size(); i++) {
			if (cardSet[i].GetCardState() == bridge) {
				BridgeCount++;
			}
		}
	}
	bool Move(string str);
	bool NextSet();
	int GetMoveCount() {
		return Movement;
	}
	PlayerState GetPlayerState() {
		return PlyerState;
	}
	int GetScore() {
		return Score;
	}
	int GetBridgeCount() {
		return BridgeCount;
	}
	int GetOrderOfEnded() {
		return OrderofEnded;
	}
	void EndScore();
};