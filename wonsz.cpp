#include "wonsz.h"
wonsz::wonsz()
{
	Vector2 vec;
	head.x = head.y = vec.x = 2;
	vec.y = 1;
	kierunek = RIGHT;
	tail.push(vec);
}


wonsz::~wonsz()
{
}

void wonsz::setKierunek(Kierunek k) {
	kierunek = k;
}
Kierunek wonsz::getKierunek() {
	return kierunek;
}
void wonsz::setHead(Vector2 v) {
	head = v;
}
Vector2 wonsz::getHead() {
	return head;
}
void wonsz::moveTail() {
	tail.push(head);
	tail.pop();
}
void wonsz::growTail() {
	tail.push(head);
}
queue<Vector2> wonsz::getTail() {
	return tail;
}
void wonsz::updateHead() {
	switch (kierunek)
	{
	case UP:
		head.x--;
		break;
	case DOWN:
		head.x++;
		break;
	case LEFT:
		head.y--;
		break;
	case RIGHT:
		head.y++;
	}
}