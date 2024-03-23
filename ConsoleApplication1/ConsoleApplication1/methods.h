#pragma once

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

void Device::printData() const {
	cout << "Device: " << this->getName() << endl <<
		"Description: " << this->getDescription() << endl <<
		"Price: $" << this->getPrice() << endl <<
		"Speed: " << this->getSpeed() << " b/s" << endl <<
		"Inputs: " << this->getInputs() << endl << "\n";
}

float Device::maxSpeed(Device b) { return (this->speed > b.speed) * this->speed + (b.speed >= this->speed) * b.speed; }

float Device::minSpeed(Device b) { return (this->speed < b.speed) * this->speed + (b.speed <= this->speed) * b.speed; }
