#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

enum Zoo_ID { Cat_ID = 0, Fox_ID, Horse_ID, Bee_ID };
class Zoo
{
public:
	virtual void info() = 0;
	virtual ~Zoo() {}
	static Zoo* createZoo(Zoo_ID id);
};
class Fox : public Zoo
{
public:
	void info() {
		cout << "This if Fox" << endl;
	}
};
class Cat : public Zoo
{
public:
	void info() {
		cout << "This is Cat" << endl;
	}
};
class Horse : public Zoo
{
public:
	void info() {
		cout << "This is Horse" << endl;
	}
};
class Bee : public Zoo
{
public:
	void info() {
		cout << "This is Bee" << endl;
	}
};
Zoo* Zoo::createZoo(Zoo_ID id)
{
	Zoo * p=nullptr;
	switch (id)
	{
	case Cat_ID:
		p = new Cat();
		break;
	case Bee_ID:
		p = new Bee();
		break;
	case Fox_ID:
		p = new Fox();
		break;
	case Horse_ID:
		p = new Horse();
		break;
	default:
		assert(false);
	}
	return p;
};
int main()
{
	vector<Zoo*> v;
	v.push_back(Zoo::createZoo(Cat_ID));
	v.push_back(Zoo::createZoo(Fox_ID));
	v.push_back(Zoo::createZoo(Bee_ID));
	v.push_back(Zoo::createZoo(Horse_ID));
	for (int i = 0; i<v.size(); i++)
		v[i]->info();
	cin.get();

}