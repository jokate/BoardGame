#pragma once
#include "Cell.h"
#include "Card.h"
#include "Map.h"
#include "Player.h"
#include <vector>
#include <iostream>
#include <io.h>

class BoardSystem {
private:
public:
	bool OneEnded;
	int Operation, turn, playerNumber, NumofEndPlayer;
	Map map;
	vector<string> files;

	vector<Player> PlayerSet;
	BoardSystem() {
		playerNumber = 0;
	}
	void Initialize(std::string  str, int plNumber) {
		NumofEndPlayer = 0;
		OneEnded = false;
		Operation = 0;
		playerNumber = plNumber;
		map.Initailize(str);
		for (int i = 0; i < playerNumber; i++) {
			Player pl(i + 1);
			PlayerSet.push_back(i);
		}
		turn = 1;
	}
	int WinnerPlayer() {
		int Winner = 0;
		int WinnerScore = 0;
		for (int i = 0; i < playerNumber; i++) {
			if (WinnerScore < PlayerSet[i].GetScore()) {
				WinnerScore = PlayerSet[i].GetScore();
				Winner = i;
			}
			else if (WinnerScore == PlayerSet[i].GetScore()) {
				if (PlayerSet[Winner].GetOrderOfEnded() > PlayerSet[i].GetOrderOfEnded()) {
					Winner = i;
				}
			}
		}
		return Winner + 1;
	}
	int EndScore() {
		int Score = 0;
		if (NumofEndPlayer == 1) {
			OneEnded = true;
			Score += 7;
		}
		else if (NumofEndPlayer == 2) {
			Score += 3;
		}
		else if (NumofEndPlayer == 3) {
			Score += 1;
		}
		return Score;
	}
	void ChangeTurn() {
		Operation = 0;
		while (true) {
			turn = (turn % playerNumber) + 1;
			if (PlayerSet[turn - 1].GetPlayerState() == Ended) {
				continue;
			}
			else {
				break;
			}
		}
	}
	bool GameEnd() {
		if (NumofEndPlayer == playerNumber - 1) {
			return true;
		}
		else
			return false;
	}
	static int Check(std :: string str) {
		int number = 0;
		try {
			number = std::stoi(str);
		}
		catch (exception e) {
			return 0;
		}
		if (number > 4 || number < 2) {
			return 0;
		}
		else {
			return number;
		}
	}
	void ReadMaps(string Filedir) {
		struct _finddata_t fd;	
		intptr_t handle;
		if ((handle = _findfirst(Filedir.c_str(), &fd)) == -1L)
			return;
		do {
			files.push_back(fd.name);
		} while (_findnext(handle, &fd) == 0);
		_findclose(handle);
	}
	void ReInitialize(string str) {
		map.ClearMap();
		PlayerSet.clear();
		Initialize(str, playerNumber);
	}
};
extern BoardSystem BS;
