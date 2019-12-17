#pragma once

#include "User.h"
#include "ListBook.h"
class Publisher :public User
{
protected:
	
public:
	Publisher();
	~Publisher();
	ListBook getPublisherList(ListBook& a);
	virtual ListBook getList(ListBook& a);
	virtual void pXoasach(ListBook& a, char* key);
	virtual void pSuasach(ListBook& a, const char* key);
	virtual void pTimSachKhongDuocMua(vector<Bill>&listBill, ListBook& a);


};

