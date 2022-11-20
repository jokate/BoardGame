#pragma once
#include <iostream>
enum CardSet {
	NoCard = 0, bridge, Hammer, Saw, PhilipsDriver
};
class Card {
private :
	int Score;
	CardSet cardS;
public :
	Card() {}
	void CardSetting(char CardSet) {
		switch (CardSet) {
			case 'B' :
				cardS = bridge;
				Score = 0;
				break;
			case 'H' :
				cardS = Hammer;
				Score = 2;
				break;
			case 'S' :
				cardS = Saw;
				Score = 3;
				break;
			case 'P' :
				cardS = PhilipsDriver;
				Score = 1;
				break;
			default :
				cardS = NoCard;
				Score = 0;
				break;
		}
			
	}
	int GetCardState() {
		return cardS;
	}
	int GetScore() {
		return Score;
	}
};