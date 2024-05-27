#include "grid.h"
#include <iostream>
#include "colors.h"

using namespace std;

Grid::Grid() {// задаем параметры нашего поля 20 на 10 клеток размером 30 пикселей
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Initialize();
	colors = GetCellColors();
}

void Grid::Initialize() {// Инициализируем поле заполняя двумерный массив 20 на 10 нулями
	for (int row = 0; row < numRows; row++) {
		for (int column = 0; column < numCols; column++) {
			grid[row][column] = 0;
		}
	}
}

void Grid::Print() {// Выводим поле
	for (int row = 0; row < numRows; row++) {
		for (int column = 0; column < numCols; column++) {
			cout << grid[row][column] << " ";
		}
		cout << endl;
	}
}



void Grid::Draw() {// Отрисовка фигур на поле
	for (int row = 0; row < numRows; row++) {
		for (int column = 0; column < numCols; column++) {
			int cellValue = grid[row][column];// Значение клетки
			DrawRectangle(column * cellSize+11, row * cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);//клетки заполняются в зависимости от фигуры (столбец*размер клетки + отступ слева, размер клетки -1)
			
		}
	}
}

bool Grid::isCellOutside(int row, int column)// проверка на выход за края
{
	if (row >= 0 && row < numRows && column >= 0 && column < numCols) {// больше 0 и меньше длины строки и больше нуля и меньше длины столбца
		return false;
	}
	return true;
}

bool Grid::isCellEmpty(int row, int column)// проверка на пустую клетку
{
	if (grid[row][column] == 0) {
		return true;
	}
	return false;
}

int Grid::ClearFullRows()// Удаление заполненных строк и перемещение остальных вниз
{
	int completed = 0;// пременная для подсчета заполненных строк
	for (int row = numRows - 1; row >= 0; row--) {
		if (IsRowFull(row)) {// Удаление заполненных строк
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {// перемещение вниз остальных на число удаленных
			MoveRowDown(row, completed);
		}
	}
	return completed;// для начисления очков
}

bool Grid::IsRowFull(int row)// проверка на заполненность строки
{
	for (int column = 0; column < numCols; column++) {
		if (grid[row][column] == 0) {
			return false;
		}
	}
	return true;
}

void Grid::ClearRow(int row)// очистка строки
{
	for (int column = 0; column < numCols; column++) {
		grid[row][column] = 0;
	}
}

void Grid::MoveRowDown(int row, int numRows) // Перемещение строк вниз
{
	for (int column = 0; column < numCols; column++) {
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}
