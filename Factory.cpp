#include <iostream>
#include <vector>

using namespace std;

class Persian
{
public:
	virtual void info() = 0;
	virtual ~Persian() {}
};
class Black
{
public:
	virtual void info() = 0;
	virtual ~Black() {}
};
class Motley
{
public:
	virtual void info() = 0;
	virtual ~Motley() {}
};
class CarpetPersian : public Persian
{
public:
	void info() {
		cout << "Persian Carpet" << endl;
	}
};
class CarpetBlack : public  Black
{
public:
	void info() {
		cout << "Black Carpet" << endl;
	}
};
class CarpetMotly : public Motley
{
public:
	void info() {
		cout << "Motley Carpet" << endl;
	}
};
class CatPersian : public Persian
{
public:
	void info() {
		cout << "Persian cat" << endl;
	}
};
class CatBlack : public  Black
{
public:
	void info() {
		cout << "Cat Black" << endl;
	}
};
class CatMotley : public Motley
{
public:
	void info() {
		cout << "Cat Motley" << endl;
	}
};
class Color_Factory
{
public:
	virtual Persian* createPersian() = 0;
	virtual  Black* createBlack() = 0;
	virtual Motley* createMotley() = 0;
	virtual ~Color_Factory() {}
};
class Carpet_Factory : public Color_Factory
{
public:
	Persian* createPersian() {
		return new CarpetPersian;
	}
	Black* createBlack() {
		return new CarpetBlack;
	}
	Motley* createMotley() {
		return new CarpetMotly;
	}
};
class Cats_Factory : public Color_Factory
{
public:
	Persian* createPersian() {
		return new CatPersian;
	}
	Black* createBlack() {
		return new CatBlack;
	}
	Motley* createMotley() {
		return new CatMotley;
	}
};
class ROOM
{
public:
	~ROOM() {
		int i = 0;
		for (i = 0; i<vi.size(); ++i)  delete vi[i];
		for (i = 0; i<va.size(); ++i)  delete va[i];
		for (i = 0; i<vh.size(); ++i)  delete vh[i];
	}
	void info() {
		int i;
		for (i = 0; i<vi.size(); ++i)  vi[i]->info();
		for (i = 0; i<va.size(); ++i)  va[i]->info();
		for (i = 0; i<vh.size(); ++i)  vh[i]->info();
	}
	vector<Persian*> vi;
	vector<Black*> va;
	vector<Motley*> vh;
};
class Room
{
public:
	ROOM* create(Color_Factory& factory) {
		ROOM* p = new ROOM;
		p->vi.push_back(factory.createPersian());
		p->va.push_back(factory.createBlack());
		p->vh.push_back(factory.createMotley());
		return p;
	}
};