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
			//������� ������� ������� ����
		
		}
		else {
			std::cout << "The cat wants to eat";
			//������� ������� ��������� ����
		}
	}
};
