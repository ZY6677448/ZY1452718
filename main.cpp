#include <iostream>
#include <string>
#include <list>

class Observer;

class Subject{
public:
	virtual ~Subject() {};
	virtual void registerObsvr(Observer* obsvr) = 0;
	virtual void removeObsvr(Observer* obsvr) = 0;
	virtual void notifyObsvrs(const std::string &msg) = 0;
};
class Observer {
public:
	virtual ~Observer() {};
	virtual void Update(const std::string &msg) = 0;
	virtual std::string getName() = 0;
protected:
	Observer(){};
};

class Tmall : public Subject {
public:
	Tmall() { _observers = new std::list<Observer*>(); }
	void registerObsvr(Observer* obsvr);
	void removeObsvr(Observer* obsvr);
	void notifyObsvrs(const std::string &msg);
private:
	std::list<Observer*> *_observers;
};

void Tmall::registerObsvr(Observer* obsvr) {
	_observers->push_back(obsvr);
}

void Tmall::removeObsvr(Observer* obsvr) {
	if (_observers->size() > 0)
		_observers->remove(obsvr);
}
void Tmall::notifyObsvrs(const std::string &msg) {
	std::cout << "��è��Ϣ��" << msg << std::endl;
	std::list<Observer*>::iterator iter
		= _observers->begin();
	for (; iter != _observers->end(); iter++) {
		(*iter)->Update(msg);
	}
}

class Others : public Observer {
public:
	Others(std::string name, std::string ACTION, std::string action)
	{
		_name = name;
		_action = action;
		_ACTION = ACTION;
	};
	void Update(const std::string &msg);
	std::string getName();
private:
	std::string _name;
	std::string _action;
	std::string _ACTION;
};

std::string Others::getName() {
	return _name;
}

void Others::Update(const std::string &msg) {
	std::cout << "��ע�� " << _name << std::endl;
	if (msg == "��Ʒ������")
		std::cout << "��Ӧ: " << _action
		<< std::endl << std::endl;
	else
		std::cout << "��Ӧ��" << _ACTION
		<< std::endl << std::endl;
}

int main()
{
	Others* A = new Others("�����̼�",
		"��������",
		"���Ž���");
	Others* B = new Others("���",
		"��������",
		"������Ʒ");

	Tmall* tmall = new Tmall();
	tmall->registerObsvr(A);
	tmall->registerObsvr(B);


	tmall->notifyObsvrs("��Ʒ������");
	tmall->notifyObsvrs("��Ʒ������");

	system("Pause");
	return 0;
}