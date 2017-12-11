#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
class Object
{
	
};


class ObjectPool
{
private:
	struct Pool
	{
		Object* instance;
		bool    is_use;
	};
	vector<Pool> my_pool;
public:
	Object* createNewObject()
	{
		for (size_t i = 0; i < my_pool.size(); ++i)
		{
			if (!my_pool[i].is_use)
			{
				my_pool[i].is_use = true; 
				return my_pool[i].instance;
			}
		}

		Pool record;
		record.instance = new Object;
		record.is_use = true;

		my_pool.push_back(record);

		return record.instance;
	}
	void deleteObject(Object* object)
	{	
		for (size_t i = 0; i < my_pool.size(); ++i)
		{
			if (my_pool[i].instance == object)
			{
				my_pool[i].is_use = false;
				break;
			}
		}
	}
	virtual ~ObjectPool()
	{
		
		for (size_t i = 0; i < my_pool.size(); ++i)
			delete my_pool[i].instance;
	}
};