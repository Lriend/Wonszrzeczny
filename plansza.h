#ifndef PLANSZA_H
#define PLANSZA_H

#include"wonsz.h"
enum GameState 
{ 
	RUNNING, WIN, LOSS 
};
class plansza
{
	char board[100][100];
	int wierszy, kolumn;
	GameState gameState;
public:
	void setField(int, int, char);
	void rysuj();
	char getField(int, int);
	GameState getGameState();
	void setGameState(GameState);
	plansza(int, int);
	int getWierszy();
	int getKolumn();
	void czysc();
	~plansza();
};

#endif