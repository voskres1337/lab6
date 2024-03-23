#pragma once

template <typename G>
Mx<G>::~Mx() {
	for (int i = 0; i < size; i++)
	{
		delete[] mx[i];
	}
	delete[] mx;
}

template <typename G>
void Mx<G>::addElement(G* d) {
	if (size == 0) {
		mx = new G * *[1];
		mx[0] = new G * [1];
		mx[0][0] = d;
		size = 1;
		return;
	}

	// проверяем, есть ли место для добавления элемента
	int row = 0, col = 0;
	bool found = false;
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			if (mx[row][col] == NULL) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}

	if (found) {
		mx[row][col] = d; // на свободное место
		return;
	}

	// если нет свободного места, то увеличиваем размер матрицы на 1 в каждую строну
	G*** temp = new G * *[size + 1];
	for (int i = 0; i < size + 1; i++) {
		temp[i] = new G * [size + 1];
		for (int j = 0; j < size + 1; j++) {
			temp[i][j] = NULL;
		}
	}

	// копируем существующие элементы в новую матрицу
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp[i][j] = mx[i][j];
		}
	}

	temp[size][0] = d; // добавляем новый элемент
	delete[] mx; // освобождаем память от старой матрицы
	mx = temp;
	size++;
};

template <typename G>
void Mx<G>::deleteElement(int row, int col) {
	if (row < 0 || row >= size || col < 0 || col >= size) {
		cout << "Введите верные значения!" << endl;
		return;
	}
	if (mx[row][col] == NULL) {
		cout << "Ничего нет на позиции [" << row << "][" << col << "]!" << endl;
		return;
	}
	mx[row][col] = NULL;
}

template <typename G>
void Mx<G>::deleteElement(string name) {
	bool elementDeleted = false;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (mx[i][j] != NULL && mx[i][j]->getName() == name) {
				mx[i][j] = NULL;
				elementDeleted = true;
				break; // УБРАТЬ ЕСЛИ НАДО БУДЕТ ВСЕ УСТРОЙСТВА С ЗАДАННЫМ ИМЕНЕМ УДАЛИТЬ
			}
		}
		if (elementDeleted) {
			break; // УБРАТЬ ЕСЛИ НАДО БУДЕТ ВСЕ УСТРОЙСТВА С ЗАДАННЫМ ИМЕНЕМ УДАЛИТЬ
		}
	}
	if (!elementDeleted) {
		cout << "Нет устройств с названием: \"" << name << "\"." << endl;
	}
}

template <typename G>
void Mx<G>::printData() const {
	cout << "|-----------------------------------------\n";
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			if (mx[i][j] != NULL) {
				cout << mx[i][j]->getSpeed() << "\t";
			}
			else {
				cout << "\t";
			}
		}
		cout << endl;
	}
	cout << "|-----------------------------------------\n" << endl;
}

template <typename G>
void Mx<G>::sortMatrix() {
	for (int i = 0; i < size * size - 1; i++) {
		for (int j = 0; j < size * size - i - 1; j++) {
			int row1 = j / size;
			int col1 = j % size;
			int row2 = (j + 1) / size;
			int col2 = (j + 1) % size;

			// проверяем, если текущий элемент null или следующий элемент null
			if (mx[row1][col1] == NULL || mx[row2][col2] == NULL) {
				if (mx[row2][col2] != NULL) {
					// перемещаем null в конец, если следующий элемент не null
					G* temp = mx[row1][col1];
					mx[row1][col1] = mx[row2][col2];
					mx[row2][col2] = temp;
				}
				continue;
			}

			// cравниваем скорость текущего и следующего элементов
			if (*mx[row1][col1] < *mx[row2][col2]) {
				// меняем местами элементы, если текущий элемент меньше следующего
				G* temp = mx[row1][col1];
				mx[row1][col1] = mx[row2][col2];
				mx[row2][col2] = temp;
			}
		}
	}
}

template <typename G>
void Mx<G>::printDevicesWithName(string name) const {
	bool found = false;

	cout << "Поиск устройств с названием: \"" << name << "\":" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (mx[i][j] != NULL && mx[i][j]->getName() == name) {
				found = true;
				mx[i][j]->printData();
			}
		}
	}
	if (!found) {
		cout << "Нет устройств с названием: \"" << name << "\"!" << endl;
	}
}

template <typename G>
void Mx<G>::printDevicesWithSpeedHigher(float speed) const {
	bool found = false;
	cout << "Устройств, со скоростью, большей: \"" << speed << "\":" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (mx[i][j] != NULL && mx[i][j]->getSpeed() > speed) {
				found = true;
				mx[i][j]->printData();
			}
		}
	}
	if (!found) {
		cout << "Нет устройств, со скоростью, большей: \"" << speed << "\"!" << endl;
	}
}

template <typename G>
int Mx<G>::getSize() {
	return this->size;
}

template <typename G>
const G*** Mx<G>::getMatrix() const {
	return this->mx;
}

template <typename G>
const G*** Mx<G>::getCopyOfMatrix() const {
	G*** copy = this->mx;
	return copy;
}

template <typename G>
ostream& operator << (ostream& os, Mx<G>& m) {
	for (int i = 0; i < m.getSize(); i++) {
		cout << "|";
		for (int j = 0; j < m.getSize(); j++) {
			if (m.getMatrix()[i][j] != NULL) {
				os << m.getMatrix()[i][j]->getSpeed() << "\t";
			}
			else {
				os << "\t";
			}
		}
		os << endl;
	}
	return os;
}
/*
Mx::~Mx() {
	for (int i = 0; i < size; i++)
	{
		delete[] mx[i];
	}
	delete[] mx;
}

void Mx::addElement(Device* d) {
	// если матрица пуста, то выделяем память под первый объект класса
	if (size == 0) {
		mx = new Device * *[1];
		mx[0] = new Device*[1];
		mx[0][0] = d;
		size = 1;
		return;
	}

	// проверяем, есть ли место для добавления элемента
	int row = 0, col = 0;
	bool found = false;
	for (row = 0; row < size; row++) {
		for (col = 0; col < size; col++) {
			if (mx[row][col] == NULL) {
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}

	if (found) {
		mx[row][col] = d; // на свободное место
		return;
	} 

	// если нет свободного места, то увеличиваем размер матрицы на 1 в каждую строну
	Device* **temp = new Device* *[size + 1];
	for (int i = 0; i < size + 1; i++) {
		temp[i] = new Device*[size + 1];
		for (int j = 0; j < size + 1; j++) {
			temp[i][j] = NULL;
		}
	}

	// копируем существующие элементы в новую матрицу
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp[i][j] = mx[i][j];
		}
	}

	temp[size][0] = d; // добавляем новый элемент
	delete[] mx; // освобождаем память от старой матрицы
	mx = temp;
	size++;
}

void Mx::deleteElement(string name) {
	bool elementDeleted = false;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (mx[i][j] != NULL && mx[i][j]->getName() == name) {
				mx[i][j] = NULL;
				elementDeleted = true;
				break; // УБРАТЬ ЕСЛИ НАДО БУДЕТ ВСЕ УСТРОЙСТВА С ЗАДАННЫМ ИМЕНЕМ УДАЛИТЬ
			}
		}
		if (elementDeleted) {
			break; // УБРАТЬ ЕСЛИ НАДО БУДЕТ ВСЕ УСТРОЙСТВА С ЗАДАННЫМ ИМЕНЕМ УДАЛИТЬ
		}
	}
	if (!elementDeleted) {
		cout << "Нет устройств с названием: \"" << name << "\"." << endl;
	}
}

void Mx::deleteElement(int row, int col) {
	if (row < 0 || row >= size || col < 0 || col >= size) {
		cout << "Введите верные значения!" << endl;
		return;
	}
	if (mx[row][col] == NULL) {
		cout << "Ничего нет на позиции [" << row << "][" << col << "]!" << endl;
		return;
	}
	mx[row][col] = NULL;
}

void Mx::printData() const {
	cout << "|-----------------------------------------\n";
	for (int i = 0; i < size; i++) {
		cout << "|";
		for (int j = 0; j < size; j++) {
			if (mx[i][j] != NULL) {
				cout << mx[i][j]->getSpeed() << "\t";
			}
			else {
				cout << "\t";
			}
		}
		cout << endl;
	}
	cout << "|-----------------------------------------\n" << endl;
}

void Mx::sortMatrix() {
	for (int i = 0; i < size * size - 1; i++) {
		for (int j = 0; j < size * size - i - 1; j++) {
			int row1 = j / size;
			int col1 = j % size;
			int row2 = (j + 1) / size;
			int col2 = (j + 1) % size;

			// проверяем, если текущий элемент null или следующий элемент null
			if (mx[row1][col1] == NULL || mx[row2][col2] == NULL) {
				if (mx[row2][col2] != NULL) {
					// перемещаем null в конец, если следующий элемент не null
					Device* temp = mx[row1][col1];
					mx[row1][col1] = mx[row2][col2];
					mx[row2][col2] = temp;
				}
				continue;
			}

			// cравниваем скорость текущего и следующего элементов
			if (*mx[row1][col1] < *mx[row2][col2]) {
				// меняем местами элементы, если текущий элемент меньше следующего
				Device* temp = mx[row1][col1];
				mx[row1][col1] = mx[row2][col2];
				mx[row2][col2] = temp;
			}
		}
	}
}

void Mx::printDevicesWithName(string name) const {
	bool found = false;

	cout << "Поиск устройств с названием: \"" << name << "\":" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (mx[i][j] != NULL && mx[i][j]->getName() == name) {
				found = true;
				mx[i][j]->printData();
			}
		}
	}
	if (!found) {
		cout << "Нет устройств с названием: \"" << name << "\"!" << endl;
	}
}

void Mx::printDevicesWithSpeedHigher(float speed) const {
	bool found = false;
	cout << "Устройств, со скоростью, большей: \"" << speed << "\":" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (mx[i][j] != NULL && mx[i][j]->getSpeed() > speed) {
				found = true;
				mx[i][j]->printData();
			}
		}
	}
	if (!found) {
		cout << "Нет устройств, со скоростью, большей: \"" << speed << "\"!" << endl;
	}
}

int Mx::getSize() {
	return this->size;
}

const Device* **Mx::getMatrix() const {
	return this->mx;
}

const Device* **Mx::getCopyOfMatrix() const {
	Device* **copy = this->mx;
	return copy;
}
*/

