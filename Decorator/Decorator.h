#ifndef _DECORATOR_H_
#define _DECORATOR_H_
class Component {//基类
public:
	virtual ~Component();
	virtual void Operation();
protected:
	Component();
private:
};

class ConcrectComponent :public Component {//派生出具体的被装饰者
public:
	ConcrectComponent();
	~ConcrectComponent();
	void Operation();//实现虚基类中的接口
protected:
private:
};

class Decorator:public Component//派生出的装饰者基类
{
public:
	Decorator(Component *com);
	virtual ~Decorator();
	void Operation();//实现虚基类中的接口
protected:
	Component *_com;//被装饰的对象
private:
};

class ConcrectDecorator1 :public Decorator {//派生出的具体的装饰者1
public:
	ConcrectDecorator1(Component *com);
	~ConcrectDecorator1();
	void Operation();
	void AddedBehavior1();//装饰者带来的特性
protected:
private:
};

class ConcrectDecorator2 :public Decorator {//派生出的具体的装饰者2
public:
	ConcrectDecorator2(Component *com);
	~ConcrectDecorator2();
	void Operation();
	void AddedBehavior2();//装饰者带来的特性
protected:
private:
};
#endif
