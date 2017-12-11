#include <iostream>
#include <vector>

using namespace std;

class CarpetPersian 
{
public:
	void info() {
		cout << "Persian Carpet" << endl;
	}
};
class CarpetBlack 
{
public:
	void info() {
		cout << "Black Carpet" << endl;
	}
};
class CarpetRed
{
public:
	void info() {
		cout << "Red Carpet" << endl;
	}
};
class CarpetWhite
{
public:
	void info() {
		cout << "White Carpet" << endl;
	}
};
class CarpetMotley
{
public:
	void info() {
		cout << "Motley Carpet" << endl;
	}
};
class ElectronShop
{
public:
	vector<CarpetPersian> vi;
	vector<CarpetBlack> va;
	vector<CarpetRed> vh;
	vector<CarpetWhite> vc;
	vector<CarpetMotley> ve;
	void info() {
		int i;
		for (i = 0; i<vi.size(); ++i)  vi[i].info();
		for (i = 0; i<va.size(); ++i)  va[i].info();
		for (i = 0; i<vh.size(); ++i)  vh[i].info();
		for (i = 0; i<vc.size(); ++i)  vc[i].info();
		for (i = 0; i<ve.size(); ++i)  ve[i].info();
	}
};
class ShopBuilder
{
protected:
	ElectronShop* p;
public:
	ShopBuilder() : p(0) {}
	virtual ~ShopBuilder() {}
	virtual void create() {}
	virtual void buildPersian() {}
	virtual void buildBlack() {}
	virtual void buildRed() {}
	virtual void buildWhite() {}
	virtual void buildMotley() {}
	virtual ElectronShop* get() { return p; }
};
class FirstShopBuilder : public ShopBuilder
{
public:
	void create() { p = new ElectronShop; }
	void buildPersian() { p->vi.push_back(CarpetPersian()); }
	void buildBlack() { p->va.push_back(CarpetBlack()); }
	void buildWhite() { p->vc.push_back(CarpetWhite()); }
	void buildRed() { p->vh.push_back(CarpetRed()); }
};
class SecondShopBuilder : public ShopBuilder
{
public:
	void create() { p = new ElectronShop; }
	void buildPersian() { p->vi.push_back(CarpetPersian()); }
	void buildBlack() { p->va.push_back(CarpetBlack()); }
	void buildWhite() { p->vc.push_back(CarpetWhite()); }
	void buildMotley() {p->ve.push_back(CarpetMotley()); }
};
class Director
{
public:
	ElectronShop* create(ShopBuilder & builder)
	{
		builder.create();
		builder.buildPersian();
		builder.buildBlack();
		builder.buildRed();
		builder.buildWhite();
		builder.buildMotley();
		return(builder.get());
	}
};