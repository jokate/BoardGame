#include "Cell.h"
#include "Card.h"
class Map {
private:
	int CellCount;
	std::deque<Cell> UpBridge, DownBridge;
	std::vector<Cell> BridgeCell;
public:
	std::vector<Cell> CellSet;
	void Initailize(std::string fileName) {
		CellCount = 0;
		std::ifstream readfile;
		readfile.open(fileName);
		if (readfile.is_open())
		{
			while (!readfile.eof())
			{
				std::string str;
				std::getline(readfile, str);
				if (str.empty()) {
					break;
				}
				Cell cell = Cell(str, CellCount);
				CellSet.push_back(cell);
				CellCount++;
			}
			SettingLink();
			readfile.close();
		}
	}
	int GetCellCount() const {
		return CellCount;
	}
	void SettingLink() {
		for (int i = 0; i < CellCount; i++) {
			if (i == 0) {
				CellSet[i].SetNext(CellSet[i + 1]);
			}
			else if (i == CellCount - 1) {
				break;
			}
			else {
				if (CellSet[i].GetState() == Bridge) {
					if (CellSet[i].GetNextDirection() == Up) {
						UpBridge.push_front(CellSet[i]);
					}
					else if (CellSet[i].GetNextDirection() == Down) {
						DownBridge.push_front(CellSet[i]);
					}
				}
				else if (CellSet[i].GetState() == AfterBridge) {
					if (CellSet[i].GetNextDirection() == Up) {
						CellSet[DownBridge.front().GetCellNumber()].SetBridge(CellSet[i]);
						CellSet[i].SetBridge(CellSet[DownBridge.front().GetCellNumber()]);
						DownBridge.pop_front();
					}
					else if (CellSet[i].GetNextDirection() == Down) {
						CellSet[UpBridge.front().GetCellNumber()].SetBridge(CellSet[i]);
						CellSet[i].SetBridge(CellSet[UpBridge.front().GetCellNumber()]);
						UpBridge.pop_front();
					}
				}
				CellSet[i].SetPrevious(CellSet[i - 1]);
				CellSet[i].SetNext(CellSet[i + 1]);
			}
		}
		return;
	}
	void ClearMap() {
		CellCount = 0;
		CellSet.clear();
		BridgeCell.clear();
		UpBridge.clear();
		DownBridge.clear();
	}
};
#pragma once
