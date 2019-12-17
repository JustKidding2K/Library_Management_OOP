#ifndef GUEST_H
#define GUEST_H

#include "ListBook.h"
#include "Bill.h"

class Guest
{
public:
	Guest();
	~Guest();
	int pTimSachCode(ListBook& a,const char* key);
	virtual ListBook getList(ListBook& a);
	virtual void pThemsach(ListBook& a);
	virtual void pXoasach(ListBook& a, const char* key);
	virtual void pSuasach(ListBook& a, const char* key);
	//virtual Guest* pTaoUser(int& type);
	virtual Bill pMuasach(ListBook& a);
	virtual void pInListBill(vector<Bill>&listBill);
	virtual void pTimSachKhongDuocMua(vector<Bill>&listBill, ListBook& a);



	//tim sach
	//
protected:

private:
};

#endif // GUEST_H
