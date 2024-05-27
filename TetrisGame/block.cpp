#include "block.h"

Block::Block() {// Параметры блока
	cellSize = 30;
	rotationState = 0;// Позиция вращения
	colors = GetCellColors();
	rowOffset = 0;
	columnOffset = 0;
}

void Block::Draw( int offsetX, int offsetY) {// отрисовка блока по позициям каждой его части
	std::vector<Position> tiles = GetCellPositions();
	for (Position item : tiles) {
		DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize +offsetY, cellSize - 1, cellSize - 1, colors[id]);
	}
}

void Block::Move(int rows, int columns) {// перемещение блока
	rowOffset += rows;
	columnOffset += columns;

}

vector<Position> Block::GetCellPositions() { // Получение позиции клетки блока
	vector<Position> tiles = cells[rotationState]; // cells мапа с положениями каждой клетки блока по ключу 
	vector<Position> movedTiles;
	for (Position item : tiles) {
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);//новое положение 
		movedTiles.push_back(newPos);// обновление положения
	}
	return movedTiles;
}

void Block::Rotate()// Поворот блока
{
	rotationState++; // следующее положение блока
	if (rotationState == (int)cells.size()) {// после 3 поворотов возвращается изначальное положение искл. квадратный блок тк одно положение вращения
		rotationState = 0;
	}
}

void Block::UndoRotation()// отмена вращения например в случае если фигура после поворота оказалась за краем поля
{
	rotationState--;
	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}
