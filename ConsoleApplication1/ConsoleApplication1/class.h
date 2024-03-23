#pragma once

#include "country.h"
#include "iClass.h"

using namespace std;

class Device : public IDevice {
private:
	char* name;
	char* description;
	float price;
	float speed;
	unsigned int inputs;
	Country country;
	static int amount;
public:
	Device(const Device& device) {
		this->setName(device.name);
		this->setDescription(device.description);
		this->setSpeed(device.speed);
		this->setPrice(device.price);
		this->setInputs(device.inputs);
	}
	Device() {
		this->setName("New_Device");
		this->setDescription("Empty Description");
		this->setSpeed(rand() % 2300);
		this->setPrice(5);
		this->setInputs(1);
	}

	Device(const char* name, const char* description, float price) {
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->setSpeed(rand() % 2300);
		this->setInputs(rand() % 5 + 1);
	}
	~Device() {
		delete[]this->name;
		delete[]this->description;
	}
	void setName(const char* name);
	const char* getName() const;
	void setDescription(const char* description);
	const char* getDescription() const;
	void setSpeed(float speed);
	float getSpeed() const;
	void setPrice(float price);
	float getPrice() const;
	void setInputs(int inputs);
	int getInputs() const;
	void display() const;
	void printData() const;
	float maxSpeed(Device b);
	float minSpeed(Device b);
};

void Device::setName(const char* name) {
	delete[]this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

const char* Device::getName() const { return this->name; }

void Device::setDescription(const char* description) {
	delete[]this->description;
	this->description = new char[strlen(description) + 1];
	strcpy_s(this->description, strlen(description) + 1, description);
}

const char* Device::getDescription() const { return this->description; }

void Device::setSpeed(float speed) {
	if (speed <= 0) return;
	this->speed = speed;
}

float Device::getSpeed() const { return this->speed; }

void Device::setPrice(float price) {
	if (price <= 0) return;
	this->price = price;
}

float Device::getPrice() const { return this->price; }

void Device::setInputs(int inputs) {
	if (inputs <= 0) return;
	this->inputs = inputs;
}

int Device::getInputs() const { return this->inputs; }

void Device::display() const {
	cout << "Device" << endl;
	printData();
	cout << endl;
}

void Device::printData() const {
	cout << "Название: " << this->getName() << endl <<
		"Описание: " << this->getDescription() << endl <<
		"Цена: $" << this->getPrice() << endl <<
		"Скорость: " << this->getSpeed() << " b/s" << endl <<
		"Выходы: " << this->getInputs() << endl;
}

float Device::maxSpeed(Device b) { return (this->speed > b.speed) * this->speed + (b.speed >= this->speed) * b.speed; }

float Device::minSpeed(Device b) { return (this->speed < b.speed) * this->speed + (b.speed <= this->speed) * b.speed; }

Device operator + (Device& d1, const Device& d2) {
	d1.setSpeed(d1.getSpeed() + d2.getSpeed());
	return d1;
}

bool operator == (const Device& d1, const Device& d2) {
	if (d1.getSpeed() == d2.getSpeed() && d1.getPrice() == d2.getPrice()) return true;
	return false;
}

bool operator > (const Device& d1, const Device& d2) {
	if (d1.getSpeed() > d2.getSpeed()) return true;
	return false;
}

bool operator > (const Device& d1, float value) {
	if (d1.getSpeed() > value) return true;
	return false;
}

bool operator < (const Device& d1, const Device& d2) {
	if (d1.getSpeed() < d2.getSpeed()) return true;
	return false;
}

bool operator < (const Device& d1, float value) {
	if (d1.getSpeed() < value) return true;
	return false;
}

ostream& operator << (ostream& os,const Device& d1) {
	os << d1.getName() << ", " << d1.getDescription() << ", " << d1.getSpeed() << " b/s, $" << d1.getPrice();
 	return os;
}

