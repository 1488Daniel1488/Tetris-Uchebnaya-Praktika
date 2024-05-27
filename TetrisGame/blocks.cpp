#include "block.h"
#include "position.h"

class LBlock : public Block {// »нформаци€ о блоках, включа€ id и позицию по€влени€ на поле (строка столбец)
public:
	LBlock() {// название блока
		id = 1;// id блока
		cells[0] = { Position(0,2), Position(1,0), Position(1,1), Position(1,2) };// положени€ клеток блока в сетке 3 на 3 дл€ каждого вращени€
		cells[1] = { Position(0,1), Position(1,1), Position(2,1), Position(2,2) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,0) };
		cells[3] = { Position(0,0), Position(0,1), Position(1,1), Position(2,1) };
		Move(0, 3);// положение по€влени€ блока на экране
	}
};

class JBlock : public Block {// »нформаци€ о блоках, включа€ id и позицию по€влени€ на поле (строка столбец)
public:
	JBlock() {// название блока
		id = 2;// id блока
		cells[0] = { Position(0,0), Position(1,0), Position(1,1), Position(1,2) };// положени€ клеток блока в сетке 3 на 3 дл€ каждого вращени€
		cells[1] = { Position(0,1), Position(0,2), Position(1,1), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,2) };
		cells[3] = { Position(0,1), Position(1,1), Position(2,0), Position(2,1) };
		Move(0, 3);// положение по€влени€ блока на экране
	}
};

class IBlock : public Block {
public:
	IBlock() {// название блока
		id = 3;// id блока
		cells[0] = { Position(1,0), Position(1,1), Position(1,2), Position(1,3) };// положени€ клеток блока в сетке 3 на 3 дл€ каждого вращени€
		cells[1] = { Position(0,2), Position(1,2), Position(2,2), Position(3,2) };
		cells[2] = { Position(2,0), Position(2,1), Position(2,2), Position(2,3) };
		cells[3] = { Position(0,1), Position(1,1), Position(2,1), Position(3,1) };
		Move(-1, 3);// особое положение по€влени€ дл€ отцентровки
	}
};

class OBlock : public Block {
public:
	OBlock() {
		id = 4;// id блока
		cells[0] = { Position(0,0), Position(0,1), Position(1,0), Position(1,1) };// только одно положение вращени€ тк это квадрат
		Move(0, 4);// особое положение по€влени€ дл€ отцентровки
	}
};

class SBlock : public Block {
public:
	SBlock() {
		id = 5;
		cells[0] = { Position(0,1), Position(0,2), Position(1,0), Position(1,1) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,2) };
		cells[2] = { Position(1,1), Position(1,2), Position(2,0), Position(2,1) };
		cells[3] = { Position(0,0), Position(1,0), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};

class TBlock : public Block {
public:
	TBlock() {
		id = 6;
		cells[0] = { Position(0,1), Position(1,0), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,1), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(1,2), Position(2,1) };
		cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,1) };
		Move(0, 3);
	}
};

class ZBlock : public Block {
public:
	ZBlock() {
		id = 7;
		cells[0] = { Position(0,0), Position(0,1), Position(1,1), Position(1,2) };
		cells[1] = { Position(0,2), Position(1,1), Position(1,2), Position(2,1) };
		cells[2] = { Position(1,0), Position(1,1), Position(2,1), Position(2,2) };
		cells[3] = { Position(0,1), Position(1,0), Position(1,1), Position(2,0) };
		Move(0, 3);
	}
};