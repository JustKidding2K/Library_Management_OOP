#pragma once
#include "ListBook.h"
#include "User.h"
class Composer :public User
{
protected:

public:
	
	Composer();
	~Composer();
	virtual ListBook getList(ListBook& a);
	virtual void pXoasach(ListBook& a, char* key);
	virtual void pSuasach(ListBook& a,const char* key);
};

