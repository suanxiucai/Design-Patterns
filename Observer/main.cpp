#include"Observer.h"
#include"Subject.h"
#include<iostream>
using namespace std;

int main(int argc, char*argv[]) {
	ConcreteSubject *sub = new ConcreteSubject();//生成一个空的观察者链表
	Observer *o1 = new ConcreteObserverA(sub);//观察者o1被加进了观察者列表， 主题者也被加入了观察者的私有成员中
	Observer *o2 = new ConcreteObserverB(sub);//o2也被加入
	sub->SetState("old");
	sub->Notify();//调用观察者列表中每个观察者的update
	sub->SetState("new");
	sub->Notify();
	return 0;

}
