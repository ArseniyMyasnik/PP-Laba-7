#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;

void deskk(string desk[9][9]) {
	cout << "   a  b  c  d  e  f  g  h" << endl;
	for (int i = 8; i > 0; i--) {
		cout << i;
		for (int j = 1; j < 9; j++) {
			cout << desk[i][j];
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	int f1_t, f2_t;
	int f1_p, f2_p;
	string desk[9][9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			desk[i][j] = "  *";
		}
	}
	deskk(desk);
	int f1_x, f1_y, f2_x, f2_y;
XY1:
	cout << "Vvedite koordinatu x dlya pervoj figury(schitaya dosku I chetvert'yu sistemy koordinat): ";
	cin >> f1_x;
	cout << "Vvedite koordinatu y dlya pervoj figury(schitaya dosku I chetvert'yu sistemy koordinat): ";
	cin >> f1_y;
	if ((f1_x) > 8 || (f1_x) < 1 || (f1_y) > 8 || (f1_y) < 1) {
		cout << "Vvedite cifru ot 1 do 8!" << endl;
		goto XY1;
	}
FT1:
	cout << "Vvedite tip figury, dlya etogo vyberite cifru" << endl << "1 - ferz'" << endl << "2 - lad'ya" << endl << "3 - slon" << endl << "4 - kon'" << endl;
	cin >> f1_t;
	if ((f1_t) > 4 || (f1_t) < 1) {
		cout << "Vvedite cifru v diapazone ot 1 do 4!" << endl;
		goto FT1;
	}
XY2:
	cout << "Vvedite koordinatu x dlya vtoroj figury(schitaya dosku I chetvert'yu sistemy koordinat): ";
	cin >> f2_x;
	cout << "Vvedite koordinatu y dlya vtoroj figury(schitaya dosku I chetvert'yu sistemy koordinat): ";
	cin >> f2_y;
	if ((f2_x) > 8 || (f2_x) < 1 || (f2_y) > 8 || (f2_y) < 1) {
		cout << "Vvedite cifru ot 1 do 8!" << endl;
		goto XY2;
	}
FT2:
	cout << "Vvedite tip figury, dlya etogo vyberite cifru" << endl << "1 - ferz'" << endl << "2 - lad'ya" << endl << "3 - slon" << endl << "4 - kon'" << endl;
	cin >> f2_t;
	if ((f2_t) > 4 || (f2_t) < 1) {
		cout << "Vvedite cifru v diapazone ot 1 do 4!" << endl;
		goto FT2;
	}

	if (f1_t == 1) {
		desk[f1_y][f1_x] = "  F";
	}
	else if (f1_t == 2) {
		desk[f1_y][f1_x] = "  L";
	}
	else if (f1_t == 3) {
		desk[f1_y][f1_x] = "  S";
	}
	else if (f1_t == 4) {
		desk[f1_y][f1_x] = "  K";
	}
	if (f2_t == 1) {
		desk[f2_y][f2_x] = "  F";
	}
	else if (f2_t == 2) {
		desk[f2_y][f2_x] = "  L";
	}
	else if (f2_t == 3) {
		desk[f2_y][f2_x] = "  S";
	}
	else if (f2_t == 4) {
		desk[f2_y][f2_x] = "  K";
	}
	deskk(desk);

	double df1_y = f1_y * 1.0, df1_x = f1_x * 1.0, df2_y = f2_y * 1.0, df2_x = f2_x * 1.0;
	cout << f1_y % 2 << endl;
	if (f1_y % 2 == 0 && f1_x % 2 == 0) {
		f1_p = 0;
		cout << "Pervaya figura stoit na chernoj kletke" << endl;
	}
	else if (f1_y % 2 == 0 && f1_x % 2 != 0) {
		f1_p = 1;
		cout << "Pervaya figura stoit na beloj kletke" << endl;
	}
	else if (f1_y % 2 != 0 && f1_x % 2 == 0) {
		f1_p = 1;
		cout << "Pervaya figura stoit na beloj kletke" << endl;
	}
	else if (f1_y % 2 != 0 && f1_x % 2 != 0) {
		f1_p = 0;
		cout << "Pervaya figura stoit na chernoj kletke" << endl;
	}

	if (f2_y % 2 == 0 && f2_x % 2 == 0) {
		f2_p = 0;
		cout << "Vtoraya figura stoit na chernoj kletke" << endl;
	}
	else if (f2_y % 2 == 0 && f2_x % 2 != 0) {
		f2_p = 1;
		cout << "Vtoraya figura stoit na beloj kletke" << endl;
	}
	else if (f2_y % 2 != 0 && f2_x % 2 == 0) {
		f2_p = 1;
		cout << "Vtoraya figura stoit na beloj kletke" << endl;
	}
	else if (f2_y % 2 != 0 && f2_x % 2 != 0) {
		f2_p = 0;
		cout << "Vtoraya figura stoit na chernoj kletke" << endl;
	}

	if (f1_p == f2_p) {
		cout << "Obe figury stoyat na kletkah odinakovogo cveta" << endl;
	}
	else {
		cout << "Obe figury stoyat na kletkah raznogo cveta" << endl;
	}

	if (f1_t == 1) {
		for (int i = 0; i < 8; i++) {
			if ((f2_x == f1_x + i) && (f2_y == f1_y + i) || (f2_x == f1_x - i) && (f2_y == f1_y - i) || (f2_x == f1_x + i) && (f2_y == f1_y - i) || (f2_x == f1_x - i) && (f2_y == f1_y + i)) {
				cout << "Vtoraya figura nahoditsya pod udarom ferzya";
				goto IF1T;
			}
		}
		if ((f1_x == f2_x) || (f1_y == f2_y)) {
			cout << "Vtoraya figura nahoditsya pod udarom ferzya";
		}
		else {
			cout << "Vtoraya figura ne nahoditsya pod udarom ferzya";
		}

	}
IF1T:
	if (f1_t == 2) {
		if ((f1_x == f2_x) || (f1_y == f2_y)) {
			cout << "Vtoraya figura nahoditsya pod udarom lad'i";
		}
		else {
			cout << "Vtoraya figura ne nahoditsya pod udarom lad'i";
		}
	}
	if (f1_t == 3) {
		for (int i = 0; i < 8; i++) {
			if ((f2_x == f1_x + i) && (f2_y == f1_y + i) || (f2_x == f1_x - i) && (f2_y == f1_y - i) || (f2_x == f1_x + i) && (f2_y == f1_y - i) || (f2_x == f1_x - i) && (f2_y == f1_y + i)) {
				cout << "Vtoraya figura nahoditsya pod udarom ferzya";
			}
		}
	}
	if (f1_t == 4) {
		if ((f1_x + 2 == f2_x) && (f1_y + 1) == f2_y || (f1_x + 2 == f2_x) && (f1_y - 1) == f2_y) {
			cout << "Vtoraya figura nahoditsya pod udarom konya";
		}
		if ((f1_x - 2 == f2_x) && (f1_y + 1) == f2_y || (f1_x - 2 == f2_x) && (f1_y - 1) == f2_y) {
			cout << "Vtoraya figura nahoditsya pod udarom konya";
		}
		if ((f1_y + 2 == f2_y) && (f1_x + 1) == f2_x || (f1_y + 2 == f2_y) && (f1_x - 1) == f2_x) {
			cout << "Vtoraya figura nahoditsya pod udarom konya";
		}
		if ((f1_y - 2 == f2_y) && (f1_x + 1) == f2_x || (f1_y - 2 == f2_y) && (f1_x - 1) == f2_x) {
			cout << "Vtoraya figura nahoditsya pod udarom konya";
		}
		else {
			cout << "Vtoraya figura ne nahoditsya pod udarom konya";
		}
	}
}