#ifndef KONTROLER_H
#define KONTROLER_H
#include"plansza.h"
#include "wonsz.h"
#include <Windows.h>
class kontroler
{
	plansza board;
	wonsz snake;
	Vector2 owoc;
public:
	kontroler(plansza&, wonsz&);
	void update();
	void display();
	GameState getState();
	void randOwoc();
	Vector2 getOwoc();
	~kontroler();
};

#endif