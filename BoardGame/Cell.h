#pragma once
#include "Card.h"
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <deque>
using std::size;
enum State {
	Normal = 0, Start = 1, End, Bridge, AfterBridge, CardS
};
enum Direction {
	Up = 0, Down, Left, Right, None = -1
};
class Cell {
private : 
	int CellNumber;
	Card card;
	State CellState;
	// 왼쪽, 오른쪽, 브릿지
	Direction Previous, Next, Brid;
public :
	std::map<Direction, Cell> LinkedCell;
	Cell() { 
	
	}
	Cell(std::string str, int CellCount) {
		CellNumber = 0;
		//초기 State = Start
		CellState = Start;
		//카드의 초기값
		card.CardSetting('N');
		Previous = None;	
		Next = None;
		Brid = None;

		str.erase(remove(str.begin(), str.end(), ' '), str.end());

		char ch[10];
		strcpy(ch, str.c_str());

		if (CellCount == 0) {
			Next = DirSet(ch[1]);
		}
		else {
			CellNumber = CellCount;
			//CellState가 생성됨.
			makingState(ch[0]);
			if (CellState == End) {
				return;
			}
			Previous = DirSet(ch[1]);
			Next = DirSet(ch[2]);

			if (CellState == Bridge) {
				Brid = Right;
			}
			else if (CellState == AfterBridge) {
				Brid = Left;
			}

			if (CellState == CardS || CellState == Bridge) {
				card.CardSetting(ch[0]);
			}
		}
		
	}
	void makingState(char StateChar) {
		switch (StateChar) {
			case 'B' :
				CellState = Bridge;
				break;
			case 'b' :
				CellState = AfterBridge;
				break;
			case 'H' :
				CellState = CardS;
				break;
			case 'S':
				CellState = CardS;
				break;
			case 'P':
				CellState = CardS;
				break;
			case 'E' :
				CellState = End;
				break;
			default :
				CellState = Normal;
				break;

		}
	}
	Direction DirSet(char dir) {
			switch (dir) {
			case 'L':
				return Left;
				break;
			case 'R':
				return Right;
				break;
			case 'U':
				return Up;
				break;
			case 'D':
				return Down;
				break;
			default:
				return None;
				break;
			}
	}
	void SetPrevious(Cell cell) {
		if (Previous != None) {
			LinkedCell[Previous] = cell;
		}
	}
	void SetNext(Cell cell) {
		if (Next != None) {
			LinkedCell[Next] = cell;
		}
	}
	void SetBridge(Cell cell) {
		if (Brid != None) {
			LinkedCell[Brid] = cell;
		}
	}
	State GetState() {
		return CellState;
	}
	Direction GetPrevDirection() {
		return Previous;
	}
	Direction GetNextDirection() {
		return Next;
	}
	int GetCellNumber() {
		return CellNumber;
	}
	Direction GetBrideDir() {
		return Brid;
	}
	Card returnCard() {
		return card;
	}
};

