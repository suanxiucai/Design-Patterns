#include"Observer.h"
#include "Subject.h"
#include<iostream>
using namespace std;
Observer::Observer() {
	_st = '\0';
}

Observer::~Observer() {};

ConcreteObserverA::ConcreteObserverA(Subject *sub) {
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverA::~ConcreteObserverA() {//在观察者生命周期结束的时候，会自动的将自己从观察者列表中除去
	_sub->Detach(this);
	if (_sub != NULL)
		delete _sub;
}

Subject* ConcreteObserverA::GetSubject() {
	return _sub;
}

void ConcreteObserverA::Update(Subject *sub) {
	_st = sub->GetState();//观察者自己取“拉”数据，而不是主题者自己推送
	PrintInfo();
}


void ConcreteObserverA::PrintInfo() {
	cout << "ConcreteObserverA observer  " <<  _st  << endl;
}

ConcreteObserverB::ConcreteObserverB(Subject *sub) {
	_sub = sub;
	_sub->Attach(this);
}

ConcreteObserverB::~ConcreteObserverB() {
	_sub->Detach(this);
	if (_sub != NULL)
		delete _sub;
}

Subject* ConcreteObserverB::GetSubject() {
	return _sub;
}

void ConcreteObserverB::Update(Subject *sub) {
	_st = sub->GetState();
	PrintInfo();
}


void ConcreteObserverB::PrintInfo() {
	cout << "ConcreteObserverB observer  " <<  _st  << endl;
}
