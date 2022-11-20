#include "Player.h"
#include "System.h"


Player::Player(int number) {
	PlayerNumber = number;
	Score = 0;
	Movement = 0;
	BridgeCount = 0;
	CurrentCell = BS.map.CellSet[0];
}
void Player::RollingDice() {
	if (SelectState == true) {
		std::srand(static_cast<unsigned int>(std::time(0)));
		int diceCount = rand() % 6 + 1;
		for (int i = 0; i < cardSet.size(); i++) {
			if (cardSet[i].GetCardState() == 1) {
				BridgeCount++;
				diceCount--;
			}
		}
		Movement = diceCount;
	}
}

void Player::GettingCard() {
	if (CurrentCell.GetState() == 5) {
		cardSet.push_back(CurrentCell.returnCard());
	}
}

bool Player::Move(std::string str) {
	if (str.size() < Movement || str.size() > Movement)
		return false;
	else {
		char ch[6];
		strcpy(ch, str.c_str());
		for (int i = 0; i < str.size(); i++) {
			if (ch[i] == 'u' || ch[i] == 'U') {
				MoveDir[i] = Up;
			}
			else if (ch[i] == 'd' || ch[i] == 'D') {
				MoveDir[i] = Down;
			}
			else if (ch[i] == 'r' || ch[i] == 'R') {
				MoveDir[i] = Right;
			}
			else if (ch[i] == 'l' || ch[i] == 'L') {
				MoveDir[i] = Left;
			}
			else {
				return false;
			}
		}
	}
	return NextSet();
}
bool Player::NextSet() {
	Cell infoCell = CurrentCell;
	for (int i = 0; i < Movement; i++) {
		//경로 존재
		if (CurrentCell.GetNextDirection() == MoveDir[i] || CurrentCell.GetPrevDirection() == MoveDir[i] || CurrentCell.GetBrideDir() == MoveDir[i]) {
			infoCell = BS.map.CellSet[infoCell.GetCellNumber()].LinkedCell[MoveDir[i]];
		}
		else {
			return false;
		}
	}
	CurrentCell = infoCell;
	return true;
}