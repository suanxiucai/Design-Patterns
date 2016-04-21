#include "Decorator.h"
#include <iostream>
using namespace std;

Component::Component(){}

Component::~Component(){}

void Component::Operation(){}
//-------------------------------------------
ConcrectComponent::ConcrectComponent(){}

ConcrectComponent::~ConcrectComponent(){}

void ConcrectComponent::Operation() {
	cout << "ConcrectComponent operation" << endl;
}
//--------------------------------------------
Decorator::Decorator(Component *com) {
	this->_com = com;
}

Decorator::~Decorator() {
	delete _com;
}

void Decorator::Operation(){}
//---------------------------------------------
ConcrectDecorator1::ConcrectDecorator1(Component *com):Decorator(com) {};

ConcrectDecorator1::~ConcrectDecorator1(){}

void ConcrectDecorator1::AddedBehavior1() {
	cout << "ConcrectDecorator::AddedBehavior1..." << endl;
}

void ConcrectDecorator1::Operation() {
	_com->Operation();
	this->AddedBehavior1();
}
//---------------------------------------------
ConcrectDecorator2::ConcrectDecorator2(Component *com) :Decorator(com) {};

ConcrectDecorator2::~ConcrectDecorator2() {}

void ConcrectDecorator2::AddedBehavior2() {
	cout << "ConcrectDecorator::AddedBehavior2..." << endl;
}

void ConcrectDecorator2::Operation() {
	_com->Operation();
	this->AddedBehavior2();
}
