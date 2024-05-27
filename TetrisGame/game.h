#pragma once
#include "grid.h"
#include "blocks.cpp"
using namespace std;
//объ€вление класса Game и методов этого класса
class Game {
public:
	Game();
	~Game();
	void Draw();
	void HandleInput();
	void MoveBlockDown();
	bool gameOver;
	int score;
	Music music;

private:
	Grid grid;
	void MoveBlockLeft();
	void MoveBlockRight();
	Block GetRandomBlock();
	vector<Block> GetAllBlocks();
	bool isBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	void Reset();
	void UpdateScore(int linesCleared, int moveDownPoints);
	vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	Sound rotateSound;
	Sound clearSound;
};
	