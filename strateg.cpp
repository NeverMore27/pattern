#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

template <class T>
class cat {
public:
	void FeedOrWalk(T& name,  int cat_eating = NULL)
	{
		if (cat_eating) {
			std::cout << "The cat wants to walk";
			//вызвать функцию гуляния кота
		
		}
		else {
			std::cout << "The cat wants to eat";
			//вызвать функцию кормления кота
		}
	}
};
