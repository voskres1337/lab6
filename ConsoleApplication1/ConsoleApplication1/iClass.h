#pragma once

class IDevice {
public:
	virtual void setName(const char* name) = 0;
	virtual const char* getName() const = 0;
	virtual void setDescription(const char* description) = 0;
	virtual const char* getDescription() const = 0;
	virtual void setSpeed(float speed) = 0;
	virtual float getSpeed() const = 0;
	virtual void setPrice(float price) = 0;
	virtual float getPrice() const = 0;
	virtual void setInputs(int inputs) = 0;
	virtual int getInputs() const = 0;
	virtual void printData() const = 0;
};