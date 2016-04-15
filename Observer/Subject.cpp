#include"Subject.h"
#include"Observer.h"
#include<iostream>
#include<list>
using namespace std;
typedef string State;

Subject::Subject() {
	_obv = new list<Observer*>;
}
Subject::~Subject() {};

void Subject::Attach(Observer *obv) {
	(*_obv).push_back(obv);
}
void Subject::Detach(Observer *obv) {
	if (obv != NULL)
		(*_obv).remove(obv);
}
void Subject::Notify() {
	list<Observer *>::iterator it= _obv->begin();
	for (; it != _obv->end(); it++) {
		(*it)->Update(this);//通知所用的观察者
	}
}

ConcreteSubject::ConcreteSubject() {
	_st = '\0';
}
ConcreteSubject::~ConcreteSubject() {};

State ConcreteSubject::GetState() {
	return _st;
}

void ConcreteSubject::SetState(const State &st) {
	_st = st;
}


