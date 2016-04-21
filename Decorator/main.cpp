#include "Decorator.h"
#include <iostream>
using namespace std;

int main(int argc,char *argv[]) {
	Component *com = new ConcrectComponent;
	Decorator *dec1= new  ConcrectDecorator1(com);//用装饰者1对com进行装饰
	Decorator *dec2= new  ConcrectDecorator2(dec1);//用装饰者2对com进行装饰
	dec1->Operation();
	cout << endl;
	dec2->Operation();

	delete dec2;
	cin.get();
	return 0;
}
