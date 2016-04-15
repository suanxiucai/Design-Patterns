#ifndef  _OBSERVER_H_
#define  _OBSERVER_H_
#include "Subject.h"
#include <string>
using namespace std;
typedef string State;
class Observer {
public:
	virtual ~Observer();
	virtual void Update(Subject *sub) = 0;
	virtual void PrintInfo() = 0;
protected:
	State _st;//基类的私有成员在派生类中只能依靠基类的公有或保护的方法进行访问，所以在这里把他设为保护成员而不是私有成员
    Observer();
};

class ConcreteObserverA :public Observer {
public:
	ConcreteObserverA(Subject *sub);
	virtual ~ConcreteObserverA();//析构函数要为虚函数
	
	virtual Subject* GetSubject();//虚函数，方便基类对象指针调用时的动态联编
	void Update(Subject *sub);
	void PrintInfo();
private:
	Subject *_sub;
};

class ConcreteObserverB :public Observer {
public:
	ConcreteObserverB(Subject *sub);
	virtual ~ConcreteObserverB();

	virtual Subject* GetSubject();
	void Update(Subject *sub);
	void PrintInfo();
private:
	Subject *_sub;
};
#endif // ! _OBSERVER_H_
