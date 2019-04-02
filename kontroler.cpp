#include "kontroler.h"
#include <iostream>

kontroler::kontroler(plansza &b, wonsz &s) : board(b), snake(s)
{
	randOwoc();
}
void kontroler::update() {
	if ((GetAsyncKeyState('A') & 0x8000)&&snake.getKierunek()!=RIGHT)	snake.setKierunek(LEFT);
	else if ((GetAsyncKeyState('D') & 0x8000) && snake.getKierunek() != LEFT)	snake.setKierunek(RIGHT);
	else if ((GetAsyncKeyState('W') & 0x8000) && snake.getKierunek() != DOWN)	snake.setKierunek(UP);
	else if ((GetAsyncKeyState('S') & 0x8000) && snake.getKierunek() != UP)	snake.setKierunek(DOWN);
	snake.moveTail();
	snake.updateHead();
	if (board.getField(snake.getHead().x, snake.getHead().y) == 'o'|| board.getField(snake.getHead().x, snake.getHead().y) == '|'|| board.getField(snake.getHead().x, snake.getHead().y) == '-')board.setGameState(LOSS);
	if (board.getField(snake.getHead().x, snake.getHead().y) == '*') {
		snake.growTail();
		randOwoc();
	}
	board.czysc();
	display();
}

void kontroler::display() {
	board.setField(getOwoc().x, getOwoc().y, '*');
	if(board.getGameState()==RUNNING)board.setField(snake.getHead().x, snake.getHead().y, 'O');
	queue<Vector2> temp = snake.getTail();
	int length = temp.size();
	for (int i = 0; i < length; i++) {
		board.setField(temp.front().x, temp.front().y, 'o');
		temp.pop();
	}
	if (board.getGameState()==LOSS) board.setField(snake.getHead().x, snake.getHead().y, 'X');
	system("cls");
	board.rysuj();
}
kontroler::~kontroler()
{
}
GameState kontroler::getState() {
	return board.getGameState();
}
Vector2 kontroler::getOwoc() {
	return owoc;
}
void kontroler::randOwoc() {
	owoc.x = rand() % board.getWierszy() + 1;
	owoc.y = rand() % board.getKolumn() + 1;
}