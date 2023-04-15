#include <iostream>
#include <stdlib.h>  // rand(), srand()
#include <windows.h> // time()
#include <math.h>    // библиотека матеши
#include <time.h>
using namespace std;

void MultiTask(int arr[4][4]) { // Как я понял квадратная матрица это вот это.
	int length = 4;
	for (int i = 0; i < length;i++) {
		for (int j = 0; j < length;j++) {
			arr[i][j] = 1 + rand() % 10;
		}
	}
}

void MultiTask(int arr[4][4], int length) {
	cout << "Квадратная матрица:\n";
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << " " << arr[i][j] << "\t\b";
		}
		cout << endl;
	}
}

void MultiTask(int arr[4][4], int length,int max,int min) {
	cout << endl;
	for (int i = 0; i < length; i++) {
		if (arr[i][i] > max) {
			max = arr[i][i];
		}
		if (arr[i][i] < min) {
			min = arr[i][i];
		}
	}
	cout << "MAX: " << max << endl;
	cout << "MIN: " << min << endl;
}

void MultiTask(int arr[4][4], int length,int z) {
	for (int f = z; f < length; f++) {
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length - 1; j++)
			{
				if (arr[i][j] > arr[i][j + 1]) {
					swap(arr[i][j], arr[i][j + 1]);
				}
			}
		}
	}
}

int rec(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return rec(a, a % b);
	}

}

int BullCow(int a = 0, int random = 1000 + rand() % 4000, int count = 0) {
	if (count == 0) {
		Sleep(4000);
	}
	else {
		Sleep(2000);
	}
	
	system("cls");
	cout << "Введите число: "; cin >> a;

	int bull = 0; int cow = 0;
	// Компюпер
	int four = random % 10; int three = (random / 10) % 10; 
	int two = (random / 100) % 10; int one = (random / 1000) % 10;
	// Челик
	int Four = a % 10; int Three = (a / 10) % 10;
	int Two = (a / 100) % 10; int One = (a / 1000) % 10;

	//cout << one << " " << two << " " << three << " " << four;
	//cout << " " << random;

	if (One == one) {
		bull++;
	}
	else if (One == two || One == three || One == four) {
		cow++;
	}

	if (Two == two) {
		bull++;
	}
	else if (Two == one || Two == three || Two == four) {
		cow++;
	}

	if (Three == three) {
		bull++;
	}
	else if (Three == one || Three == two || Three == four) {
		cow++;
	}

	if (Four == four) {
		bull++;
	}
	else if (Four == one || Four == two || Four == three) {
		cow++;
	}

	if (a == random) {

		cout << "Вы победили!!!\nЧисло попыток: ";
		return count;
	}
	else {
		cout << "Bull: " << bull << endl;
		cout << "Cow: " << cow << endl;
		return BullCow(a,random,count + 1);
	}

}

int main()
{
	setlocale(0, "");
	srand(time(NULL));
	//system("color B5");

	const int length = 4;
	int arr[length][length] = {};
	int max = 0; int min = MAXINT;
	MultiTask(arr);

	MultiTask(arr,length);

	MultiTask(arr, length, max, min);

	MultiTask(arr, length, 0);
	cout << endl;
	MultiTask(arr, length);
	cout << endl << endl;
	cout << "Введите первое число:\n"; int a; cin >> a;
	cout << "Введите второе число:\n"; int b; cin >> b;

	cout << "Максимальный Общий делитель: " << rec(a, b) << endl;

	cout << BullCow();
}
