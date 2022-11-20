#include "System.h"
#include "Cell.h"
#include "Card.h"
#include "Player.h"
BoardSystem BS;


Player::Player(int number) {
	OrderofEnded = 100;
	PlyerState = Idle;
	PlayerNumber = number;
	Score = 0;
	Movement = 0;
	BridgeCount = 0;
	CurrentCell = BS.map.CellSet[0];
}

bool Player::NextSet()
{
	int BridgeC = 0;
	Card BridgeCard;
	Cell infoCell;
	PlayerState status = PlyerState;
	infoCell = CurrentCell;
	for (int i = 0; i < Movement; i++) {
		if (status == Idle) {
			//경로 존재
			if (infoCell.GetNextDirection() == MoveDir[i]) {
				infoCell = BS.map.CellSet[infoCell.GetCellNumber()].LinkedCell[MoveDir[i]];
				if (infoCell.GetState() == End) {
					EndScore();
					BS.NumofEndPlayer++;
					OrderofEnded = BS.NumofEndPlayer;
					status = Ended;
					break;
				}
			}
			else if (infoCell.GetPrevDirection() == MoveDir[i]) {
				if (BS.OneEnded == true) {
					return false;
				}
				infoCell = BS.map.CellSet[infoCell.GetCellNumber()].LinkedCell[MoveDir[i]];
			}
			else if (infoCell.GetBrideDir() == MoveDir[i]) {
				if (MoveDir[i] == Left && BS.OneEnded == true) {
					return false;
				}
				if (status == Idle) {
					status = OnBridge;
					continue;
				}
			}
			else {
				return false;
			}
		}
		else if (status == OnBridge) {
			if (infoCell.GetState() == Bridge) {
				if (MoveDir[i] == Left) {
					if (BS.OneEnded == true) {
						return false;
					}
					status = Idle;
					BridgeC++;
				}
				else if (MoveDir[i] == Right) {
					infoCell = BS.map.CellSet[infoCell.GetCellNumber()].LinkedCell[MoveDir[i]];
					status = Idle;
					BridgeC++;
				}
				else {
					return false;
				}
			}
			else if (infoCell.GetState() == AfterBridge) {
				if (MoveDir[i] == Left) {
					if (BS.OneEnded == true) {
						return false;
					}
					infoCell = BS.map.CellSet[infoCell.GetCellNumber()].LinkedCell[MoveDir[i]];
					status  = Idle;
					BridgeC++;
				}
				else if (MoveDir[i] == Right) {
					status = Idle;
					BridgeC++;
				}
				else {
					return false;
				}
			}
			
		}
	}
	PlyerState = status;
	if (BridgeC > 0) {
		for (int i = 0; i <BridgeC; i++) {
			BridgeCard.CardSetting('B');
			cardSet.push_back(BridgeCard);
		}
	}
	CurrentCell = infoCell;
	BS.Operation++;
	return true;
}

void Player::EndScore() {
	if (BS.NumofEndPlayer == 0) {
		BS.OneEnded = true;
		Score += 7;
	}
	else if (BS.NumofEndPlayer == 1) {
		Score += 3;
	}
	else if (BS.NumofEndPlayer == 2) {
		Score += 1;
	}
}

void Player::RollingDice() {
		if (SelectState == true) {
			std::srand(static_cast<unsigned int>(std::time(0)));
			int diceCount = rand() % 6 + 1;
			diceCount -= BridgeCount;
			if (diceCount < 0) {
				Movement = 0;
				BS.Operation++;
				return;
			}
			Movement = diceCount;
			BS.Operation++;
		}

}

bool Player::Move(string str) {

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
void Player::Rest() {
	for (int i = 0; i < cardSet.size(); i++) {
		if (cardSet[i].GetCardState() == bridge) {
			cardSet.erase(cardSet.begin() + i);
			break;
		}
	}
	BS.Operation++;
}