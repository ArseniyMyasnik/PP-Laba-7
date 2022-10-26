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
	cout << "������� ���������� x ��� ������ ������(������ ����� I ��������� ������� ���������): ";
	cin >> f1_x;
	cout << "������� ���������� y ��� ������ ������(������ ����� I ��������� ������� ���������): ";
	cin >> f1_y;
	if ((f1_x) > 8 || (f1_x) < 1 || (f1_y) > 8 || (f1_y) < 1) {
		cout << "������� ����� �� 1 �� 8!" << endl;
		goto XY1;
	}
FT1:
	cout << "������� ��� ������, ��� ����� �������� �����" << endl << "1 - �����" << endl << "2 - �����" << endl << "3 - ����" << endl << "4 - ����" << endl;
	cin >> f1_t;
	if ((f1_t) > 4 || (f1_t) < 1) {
		cout << "������� ����� � ��������� �� 1 �� 4!" << endl;
		goto FT1;
	}
	XY2:
	cout << "������� ���������� x ��� ������ ������(������ ����� I ��������� ������� ���������): ";
	cin >> f2_x;
	cout << "������� ���������� y ��� ������ ������(������ ����� I ��������� ������� ���������): ";
	cin >> f2_y;
	if ((f2_x) > 8 || (f2_x) < 1 || (f2_y) > 8 || (f2_y) < 1) {
		cout << "������� ����� �� 1 �� 8!" << endl;
		goto XY2;
	}
FT2:
	cout << "������� ��� ������, ��� ����� �������� �����" << endl << "1 - �����" << endl << "2 - �����" << endl << "3 - ����" << endl << "4 - ����" << endl;
	cin >> f2_t;
	if ((f2_t) > 4 || (f2_t) < 1) {
		cout << "������� ����� � ��������� �� 1 �� 4!" << endl;
		goto FT2;
	}

	if (f1_t == 1) {
		desk[f1_y][f1_x] = "  �";
	}
	else if (f1_t == 2) {
		desk[f1_y][f1_x] = "  �";
	}
	else if (f1_t == 3) {
		desk[f1_y][f1_x] = "  �";
	}
	else if (f1_t == 4) {
		desk[f1_y][f1_x] = "  �";
	}
	if (f2_t == 1) {
		desk[f2_y][f2_x] = "  �";
	}
	else if (f2_t == 2) {
		desk[f2_y][f2_x] = "  �";
	}
	else if (f2_t == 3) {
		desk[f2_y][f2_x] = "  �";
	}
	else if (f2_t == 4) {
		desk[f2_y][f2_x] = "  �";
	}
	deskk(desk);

	double df1_y = f1_y * 1.0, df1_x = f1_x * 1.0, df2_y = f2_y * 1.0, df2_x = f2_x * 1.0;
	cout << f1_y % 2 << endl;
	if (f1_y % 2 == 0 && f1_x % 2 == 0) {
		f1_p = 0;
		cout << "������ ������ ����� �� ������ ������" << endl;
	}
	else if (f1_y % 2 == 0 && f1_x % 2 != 0) {
		f1_p = 1;
		cout << "������ ������ ����� �� ����� ������" << endl;
	}
	else if (f1_y % 2 != 0 && f1_x % 2 == 0) {
		f1_p = 1;
		cout << "������ ������ ����� �� ����� ������" << endl;
	}
	else if (f1_y % 2 != 0 && f1_x % 2 != 0) {
		f1_p = 0;
		cout << "������ ������ ����� �� ������ ������" << endl;
	}

	if (f2_y % 2 == 0 && f2_x % 2 == 0) {
		f2_p = 0;
		cout << "������ ������ ����� �� ������ ������" << endl;
	}
	else if (f2_y % 2 == 0 && f2_x % 2 != 0) {
		f2_p = 1;
		cout << "������ ������ ����� �� ����� ������" << endl;
	}
	else if (f2_y % 2 != 0 && f2_x % 2 == 0) {
		f2_p = 1;
		cout << "������ ������ ����� �� ����� ������" << endl;
	}
	else if (f2_y % 2 != 0 && f2_x % 2 != 0) {
		f2_p = 0;
		cout << "������ ������ ����� �� ������ ������" << endl;
	}

	if (f1_p == f2_p) {
		cout << "��� ������ ����� �� ������� ����������� �����" << endl;
	}
	else {
		cout << "��� ������ ����� �� ������� ������� �����" << endl;
	}

	if (f1_t == 1) {
		for (int i = 0; i < 8; i++) {
			if ((f2_x == f1_x + i) && (f2_y == f1_y + i) || (f2_x == f1_x - i) && (f2_y == f1_y - i) || (f2_x == f1_x + i) && (f2_y == f1_y - i) || (f2_x == f1_x - i) && (f2_y == f1_y + i)) {
				cout << "������ ������ ��������� ��� ������ �����";
				goto IF1T;
			}
		}
		if ((f1_x == f2_x) || (f1_y == f2_y)) {
			cout << "������ ������ ��������� ��� ������ �����";
		}
		else {
			cout << "������ ������ �� ��������� ��� ������ �����";
		}

	}
	IF1T:
	if (f1_t == 2) {
		if ((f1_x == f2_x) || (f1_y == f2_y)) {
			cout << "������ ������ ��������� ��� ������ �����";
		}
		else {
			cout << "������ ������ �� ��������� ��� ������ �����";
		}
	}
	if (f1_t == 3) {
		for (int i = 0; i < 8; i++) {
			if ((f2_x == f1_x + i) && (f2_y == f1_y + i) || (f2_x == f1_x - i) && (f2_y == f1_y - i) || (f2_x == f1_x + i) && (f2_y == f1_y - i) || (f2_x == f1_x - i) && (f2_y == f1_y + i)) {
				cout << "������ ������ ��������� ��� ������ �����";
			}
		}
	}
	if (f1_t == 4) {
		if ((f1_x + 2 == f2_x) && (f1_y + 1) == f2_y || (f1_x + 2 == f2_x) && (f1_y - 1) == f2_y) {
			cout << "������ ������ ��������� ��� ������ ����";
		}
		if ((f1_x - 2 == f2_x) && (f1_y + 1) == f2_y || (f1_x - 2 == f2_x) && (f1_y - 1) == f2_y) {
			cout << "������ ������ ��������� ��� ������ ����";
		}
		if ((f1_y + 2 == f2_y) && (f1_x + 1) == f2_x || (f1_y + 2 == f2_y) && (f1_x - 1) == f2_x) {
			cout << "������ ������ ��������� ��� ������ ����";
		}
		if ((f1_y - 2 == f2_y) && (f1_x + 1) == f2_x || (f1_y - 2 == f2_y) && (f1_x - 1) == f2_x) {
			cout << "������ ������ ��������� ��� ������ ����";
		}
		else {
			cout << "������ ������ �� ��������� ��� ������ ����";
		}
	}
}