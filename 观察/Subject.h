#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include<list>
#include<string>
using namespace std;
typedef string State;

class Observer;
class Subject {
public:
	Subject();
	virtual ~Subject();

	virtual void Attach(Observer *obv);
	virtual void Detach(Observer *obv);
	virtual void Notify();

	virtual void SetState(const State &st) = 0;
	virtual State GetState() = 0;

private:
	list<Observer*> *_obv;
};

class ConcreteSubject : public Subject{
public:
	ConcreteSubject();
	virtual ~ConcreteSubject();//析构函数应该是虚函数，除非其不用做基类，析构的时候先调用自己的析构函数，再调用基类的析构函数

	State GetState();
	void SetState(const State &st);
private:
	State _st;
};


#endif

