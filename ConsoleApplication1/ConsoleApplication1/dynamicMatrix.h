#pragma once

template <typename G>
class Mx {
public:
	~Mx();
	void addElement(G* d);
	void deleteElement(string name);
	void deleteElement(int row, int col);
	void printData() const;
	void sortMatrix();
	void printDevicesWithName(string name) const;
	void printDevicesWithSpeedHigher(float speed) const;
	int getSize();
	friend ostream& operator<<(ostream& os, Mx<G>& m);
	const G* **getMatrix() const;
	const G* **getCopyOfMatrix() const;
	G** operator[](int row) {
		if (row >= 0 && row < size) {
			return mx[row];
		}
		else {
			return NULL;
		}
	}
	Mx<G>& operator=(const Mx<G>& other) {
		if (this != &other) {
			for (int i = 0; i < size; ++i) {
				delete[] mx[i];
			}
			delete[] mx;

			size = other.size;
			mx = new G**[size];
			for (int i = 0; i < size; ++i) {
				mx[i] = new G*[size];
				for (int j = 0; j < size; ++j) {
					mx[i][j] = other.mx[i][j];
				}
			}
		}
		return *this;
	}
	bool operator==(const Mx<G>& other) const {
		if (size != other.size) {
			return false; // Если размеры не совпадают, матрицы неравны
		}
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (mx[i][j] != other.mx[i][j]) {
					return false; // Если хотя бы один элемент не совпадает, матрицы неравны
				}
			}
		}
		return true;
	}
private:
	int size = 0;
	G* **mx = NULL;
};
