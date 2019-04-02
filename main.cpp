#include <iostream>
#include "plansza.h"
#include "wonsz.h"
#include "kontroler.h"
using namespace std;

int main() {
	plansza x(25, 25);
	wonsz w;
	kontroler k(x, w);
	while (k.getState()==RUNNING){
		k.update();Sleep(150);
	}
	cout << "Przegrales!!!"<<endl;
	system("pause");
	return 0;
}