#pragma once
#include "User.h"
#include "Composer.h"
#include "Publisher.h"
#include "MenuCommandLine.h"
class Admin:public User
{
public:
	virtual void pThemsach(ListBook& a);
	virtual ListBook getList(ListBook& a);
	virtual void pXoasach(ListBook& a, char* key);
	virtual void pSuasach(ListBook& a,const char* key);
	void pTaoUser(int& type, vector<User>& listUser, vector<Composer>& listComposer, vector<Publisher>& listPublisher, vector<Admin>& listAdmin);
	void pXemUser(vector<User>& listUser, vector<Composer>& listComposer, vector<Publisher>& listPublisher, vector<Admin>& listAdmin);
	void pInListBill(vector<Bill>&listBill);
	void pTimNXBmax(vector<Bill>listBill, vector<Publisher>listPublisher);
	void pTimSachKhongDuocMua(vector<Bill>&listBill, ListBook& a);
};

