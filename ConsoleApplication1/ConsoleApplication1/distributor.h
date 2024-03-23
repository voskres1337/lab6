#pragma once
#include <iostream>

#include "router.h"

class SuperRouter : public Router {
	int connectedDevices;
	float overallTrafficOutput;
public:
	/*
	SuperRouter(const SuperRouter& sRouter):Router(sRouter) {
		this->setDevices(sRouter.getDevices());
		this->setOutput(sRouter.getOutput());
	}
	*/
	SuperRouter(const char* name, const char* description, float price, int Hz, float outputTrafficSpeed, int connectedDevices, float overallTrafficOutput):Router(name, description, price, Hz, outputTrafficSpeed) {
		this->setDevices(connectedDevices);
		this->setOutput(overallTrafficOutput);
	}
	SuperRouter():Router() {
		this->setDevices(0);
		this->setOutput(0);
	}
	void setDevices(int connectedDevices) {
		this->connectedDevices = connectedDevices;
	}
	int getDevices() {
		return this->connectedDevices;
	}

	void setOutput(float overallTrafficOutput) {
		this->overallTrafficOutput = overallTrafficOutput;
	}
	float getOutput() {
		return this->overallTrafficOutput;
	}

	void display() const {
		cout << "superRouter" << endl;
		printData();
		cout << endl;
	}

	void printData() const override {
		Router::printData();
		cout << "Всего раздано трафика: " << this->overallTrafficOutput << std::endl <<
			"Кол-во подключённых устройств: " << this->connectedDevices << std::endl;
	}
};