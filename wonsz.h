
#ifndef WONSZ_H
#define WONSZ_H
#include <queue>
#include "plansza.h"
using namespace std;

struct Vector2 {
	int x;
	int y;
};
enum Kierunek{LEFT, RIGHT, UP, DOWN};
class wonsz
{
	Kierunek kierunek;
	Vector2 head;
	queue<Vector2> tail;
	
public:
	void setKierunek(Kierunek);
	Kierunek getKierunek();
	void setHead(Vector2);
	void updateHead();
	Vector2 getHead();
	void moveTail();
	void growTail();
	queue<Vector2> getTail();
	wonsz();
	~wonsz();
};

#endif