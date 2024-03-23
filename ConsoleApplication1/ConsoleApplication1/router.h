#pragma once
#include "modem.h"

class Router : public Modem {
	float outputTrafficSpeed;
public:
	Router(const Router& router):Modem(router) {
		this->setOTS(router.getOTS());
	}
	Router(const char* name, const char* description, float price, int Hz, float outputTrafficSpeed):Modem(name, description, price, Hz) {
		this->setOTS(outputTrafficSpeed);
	}
	Router():Modem() {
		this->setPrice(0);
		this->setOTS(0);
	}

	void setOTS(float outputTrafficSpeed) {
		this->outputTrafficSpeed = outputTrafficSpeed;
	}
	float getOTS() const {
		return this->outputTrafficSpeed;
	}

	void display() const {
		cout << "router" << endl;
		printData();
		cout << endl;
	}

	void printData() const {
		Modem::printData();
		cout << "Скорость раздачи: " << this->getOTS() << endl;
	}
};