#include "Szorny.h"


int main() {
	Szorny s1("Hosarkany",300,30);
	Szorny s2("Sotet varazslo", 250, 40);
	cout << s1.getName() << " " << s1.getHp() << " " << s1.getDmg() << " " << s2.getName() << " " << s2.getHp() << " " << s2.getDmg() << endl;
	s1.tamadas(s2);
	system("pause");
	return 0;
}