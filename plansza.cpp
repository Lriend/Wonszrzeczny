#include "plansza.h"
#include<iostream>
#include<cstdlib>
plansza::plansza(int w, int h):wierszy(w), kolumn(h), gameState(RUNNING){
	board[0][0] = board[0][kolumn+1] = board[wierszy+1][0] = board[wierszy+1][kolumn+1]= '+';
	for (int i = 1; i <= wierszy; i++) {
		board[i][0] = board[i][kolumn+1] = '|';
	}
	for (int i = 1; i <= kolumn; i++) {
		board[0][i] = board[wierszy + 1][i] = '-';
	}
	for (int i = 1; i <= wierszy; i++) {
		for (int j = 1; j <= kolumn; j++) {
			board[i][j] = ' ';
		}
	}
}

plansza::~plansza()
{
}

void plansza::setField(int x, int y, char znak) {
	board[x][y] = znak;
}

void plansza::rysuj() {
	for (int i = 0; i < wierszy + 2; i++) {
		for (int j = 0; j < kolumn + 2; j++) std::cout << board[i][j];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
char plansza::getField(int x, int y) {
	return board[x][y];
}
void plansza::czysc() {
	board[0][0] = board[0][kolumn + 1] = board[wierszy + 1][0] = board[wierszy + 1][kolumn + 1] = '+';
	for (int i = 1; i <= wierszy; i++) {
		board[i][0] = board[i][kolumn + 1] = '|';
	}
	for (int i = 1; i <= kolumn; i++) {
		board[0][i] = board[wierszy + 1][i] = '-';
	}
	for (int i = 1; i <= wierszy; i++) {
		for (int j = 1; j <= kolumn; j++) {
			board[i][j] = ' ';
		}
	}
}
GameState plansza::getGameState(){
	return gameState;
}
void plansza::setGameState(GameState stat) {
	gameState = stat;
}
int plansza::getWierszy() {
	return wierszy;
}
int plansza ::getKolumn() {
	return kolumn;
}