#include "game.h"
#include<random>

Game::Game() {// Конструктор класса Game, который инициализирует игровое поле, создает набор фигур, загружает звуки и музыку.
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
	score = 0;
	InitAudioDevice();
	music = LoadMusicStream("Sounds/Tetris.mp3");
	PlayMusicStream(music);
	rotateSound = LoadSound("Sounds/TetrisRotate.mp3");
	clearSound = LoadSound("Sounds/TetrisUpal.mp3");
}

Game::~Game() {//Деструктор класса Game, который освобождает ресурсы (звуки и музыку).
	UnloadSound(rotateSound);
	UnloadSound(clearSound);
	UnloadMusicStream(music);
	CloseAudioDevice();
}

Block Game::GetRandomBlock() {//Функция, которая возвращает случайную фигуру из набора фигур
	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

vector <Block> Game::GetAllBlocks() {//Функция, которая возвращает полный набор фигур
	return { IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock() };
}

void Game::Draw() {//Функция, которая отрисовывает игровое поле, текущую фигуру и следующую фигуру
	grid.Draw();
	currentBlock.Draw(11,11);
	switch (nextBlock.id)
	{case 3:
		nextBlock.Draw(255, 290);
		break;
	case 4:
		nextBlock.Draw(255, 280);
		break;
	default:
		nextBlock.Draw(270, 270);
		break;
	}
}

void Game::HandleInput(){//Функция, которая обрабатывает ввод пользователя (перемещение и вращение фигуры)
	int keyPressed = GetKeyPressed();
	if (gameOver && keyPressed!=0) {//если игра закончена, при нажатии на любую клавишу игра начнется заново
		gameOver = false;
		Reset();
	}
	switch (keyPressed) {
	case KEY_A:
		MoveBlockLeft();
		break;
	case KEY_D:
		MoveBlockRight();
		break;
	case KEY_S:
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_SPACE:
		RotateBlock();
		break;
	}
}

//Функции, которые перемещают текущую фигуру влево, вправо и вниз соответственно
void Game::MoveBlockLeft() {
	if (!gameOver) {
		currentBlock.Move(0, -1);
		if (isBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight() {
	if (!gameOver) {
		currentBlock.Move(0, 1);
		if (isBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown() {
	if (!gameOver) {
		currentBlock.Move(1, 0);
		if (isBlockOutside() || BlockFits() == false) {
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::isBlockOutside()//функцуия проверки нахождения блока внутри игрового поля
{
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.isCellOutside(item.row, item.column)) {
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()//Функция, которая вращает текущую фигуру
{
	if (!gameOver) {
		currentBlock.Rotate();
		if (isBlockOutside()) {
			currentBlock.UndoRotation();
		}
		else {
			PlaySound(rotateSound);
		}
	}
}

void Game::LockBlock(){//Функция, которая фиксирует текущую фигуру на игровом поле, очищает заполненные ряды и обновляет счет.
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if (BlockFits() == false) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	int rowsCleared = grid.ClearFullRows();
	if (rowsCleared > 0) {
		PlaySound(clearSound);
		UpdateScore(rowsCleared, 0);
	}
	
}

bool Game::BlockFits()//Функция, которая проверяет, может ли текущая фигура быть размещена на игровом поле без пересечения с другими фигурами
{
	vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.isCellEmpty(item.row, item.column) == false) {
			return false;
		}
	}
	return true;
}

void Game::Reset()// Функция, которая сбрасывает игру в начальное состояние
{
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints){//Функция, которая обновляет счет игрока на основе количества очищенных рядов и количества очков за опускание фигуры.
	switch (linesCleared) {
	case 1:
		score += 100;
		break;
	case 2:
		score += 300;
		break;
	case 3:
		score += 500;
		break;
	default:
		break;
}
	score += moveDownPoints;
}
