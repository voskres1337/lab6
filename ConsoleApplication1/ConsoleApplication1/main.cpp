#pragma once

#include "class.h"
#include "dynamicMatrix.h"
#include "matrixMethods.cpp"
#include "summator.h"
#include "distributor.h"

using namespace std;

int main()
{
	string brake;

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	Mx<Device> mx;

	Device a;
	Device b;
	Device c;
	c.setName("TEST");
	Device d;
	d.setPrice(1337.0);
	Device e;
	Device f;
	f.setName("F");
	Device g;
	Device h;
	Device i;
	Device j;
	Device k;
	Device l;
	Device m;
	Device n;
	Device o;
	Device p;
	Device q;

	Device* test[17] = {
		&a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l, &m, &n,&o, &p, &q
	};

	for(Device *d : test) {
		mx.printData();
		mx.addElement(d);
	}
	/*
	cout << *mx[1][2] << endl;

	cout << "введите что-то для демонстрации сортировки\n";
	cin >> brake;

	// сортировка
	mx.sortMatrix();
	mx.printData();

	cout << "введите скорость (около 1500). Произведется поиск устр-в, со скоростью, больше указаннной: ";
	//поиск по условию
	float sp;
	cin >> sp;
	mx.printDevicesWithSpeedHigher(sp);

	cout << "введите название (по умолчанию) \"" << a.getName() << "\": ";
	string st;
	cin >> st;
	mx.printDevicesWithName(st);

	cout << "введите что-то для демонстрации удаления\n";
	cin >> brake;
	
	string nameToDelete;
	cout << "Введите название элемента для удаления: ";
	cin >> nameToDelete;
	mx.deleteElement(nameToDelete);
	mx.printData();

	int row ,col;
	cout << "Введите колонку для удаления (с 0): ";
	cin >> col;
	cout << "Введите ряд для удаления (с 0): ";
	cin >> row;
	mx.deleteElement(row, col);
	mx.printData();


	*/
	int db;
	Summator lab5;

	Device* ff = &f;

	lab5.add(mx);
	lab5.add(ff);
	cin >> db;
	lab5.printMap();

	cout << endl << "REMOVE F" << endl << endl;

	lab5.removeKey(ff);
	lab5.printMap();

	lab5.clearMap();
	lab5.printMap();

	cout << "\n\n\n\n\n\n\n" << endl;

	Router abc("Rabota5Router", "SimpleRouter", 16.99, 2000, 19.1);
	abc.display();

	SuperRouter aa("Rabota5SuperRouter", "SimpleRouter", 138.99, 5000, 200.19, 3, 21.1);
	aa.display();

	return 0;
}
