#pragma once
#include <vector>
#include<raylib.h>
using namespace std;
//объ€вление класса Grid и методов этого класса
class Grid {
public:
	Grid();
	void Initialize();
	void Print();
	void Draw();
	bool isCellOutside(int row, int column);
	bool isCellEmpty(int row,int column);
	int ClearFullRows();
	int grid[20][10];
private:
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int column);
	int numRows;
	int numCols;
	int cellSize;
	vector <Color> colors;
};