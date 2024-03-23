#pragma once
#include <map>
#include <string>
#include "class.h"
#include "dynamicMatrix.h"

using namespace std;

class Summator {
	map<Device*, int> score;
	int overall = 0;
public:
	void add(Device* d) {
		if (score.count(d)) {
			score[d] += 1;
		}
		else {
			score.insert({d,1});
		}
		overall += d->getPrice();
	}

	template <typename G>
	void add(Mx<G> mx) {
		for (int i = 0; i < mx.getSize(); ++i) {
			for (int j = 0; j < mx.getSize(); ++j) {
				if (mx[i][j] != NULL) {
					add(mx[i][j]);
				}
			}
		}
	}

	void removeKey(Device* d) {
		overall -= score[d] * d->getPrice();
		score.erase(d);
	}

	void printMap() {
		cout << "Elements:" << endl;
		for (auto const& elem : score)
			cout << elem.first->getName() << " : " << elem.second << endl;
		cout << "Overall: " << this->overall << endl;
	}

	void printPair(Device* d) {
		cout << d->getName() << " : " << this->score[d] << endl;
	}

	void clearMap() {
		this->score.clear();
		overall = 0;
	}
};