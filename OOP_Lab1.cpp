/* Небольшие положительные целые числа <1000 представлены тремя целочисленными полями (первая цифра, вторая цифра и третья цифра). 
Реализовать методы, переводящий число в обычное положительное целое и складывающий два таких числа.
При переполнении сложения должен получаться нуль. */

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

class Number {
private:
	int hundred;
	int ten;
	int one;
public:
	/* Конструктор */
	Number() {
		hundred = 1;
		ten = 0;
		one = 0;
	}

	void init(int a, int b, int c) {
		cout << "Введенные данные" << endl;
		hundred = a;
		ten = b;
		one = c;
	}

	/* Чтение с клавиатуры */
	void read() {
		cout << "Введите сотни" << endl;
		cin >> hundred;
		cout << "Введите десятки" << endl;
		cin >> ten;
		cout << "Введите единицы" << endl;
		cin >> one;
	}
	
	/* Вывод на экран */
	void display() {
		cout << "Сотни: " << hundred << endl;
		cout << "Десятки: " << ten << endl;
		cout << "Единицы: " << one << endl;
	}

	/* Перевод в число */
	int become_number() {
		int number;
		number = hundred * 100 + ten * 10 + one;
		return number;
	}

	/* Суммирование чисел */
	Number operator + (Number &b)
	{
		Number c;
		c.hundred = b.hundred + hundred;
		c.ten = b.ten + ten;
		c.one = b.one + one;
		return c;

	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	Number one, two;

	one.init(2, 6, 3);
	one.display();
	
	two.read();
	Number three = one + two;
	three.display();
	
	return 0;
}

