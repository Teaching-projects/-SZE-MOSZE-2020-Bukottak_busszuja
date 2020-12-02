#include <iostream>
#include "Game.h"

using namespace std;

int main() {
	Damage d;
	d.physical = 3;
	d.magical = 1;
	Game jatek;
	Map palya("palya1.txt");
	jatek.setMap(palya);
	Hero hos("Prince Aidan of Khanduras", 30, d, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
	Monster monster1("Sotetvarazslo", 250, d, 1, 2.0);
	jatek.putHero(hos,1,1);
	jatek.putMonster(monster1,1,3);
	jatek.run();
	cout << "Hello vilag" << endl;
	system("pause");
	return 0;
}