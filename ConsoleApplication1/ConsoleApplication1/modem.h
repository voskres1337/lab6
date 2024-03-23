#pragma once

#include "class.h"

class Modem : public Device {
	int Hz;
public:
	Modem(const Modem& modem):Device(modem) {
		this->setHz(modem.getHz());
	}
	Modem(const char* name, const char* description, float price, int Hz):Device(name, description, price) {
		this->setHz(Hz);
	}
	Modem():Device() {
		this->setName("New_Modem");
		this->setHz(0);
	}

	void setHz(int Hz) {
		this->Hz = Hz;
	}
	int getHz() const {
		return this->Hz;
	}

	void display() const {
		cout << "modem" << endl;
		printData();
		cout << endl;
	}

	void printData() const override {
		Device::printData();
		cout << "Частота: " << this->getHz() << " Hz" << std::endl;
	}
};