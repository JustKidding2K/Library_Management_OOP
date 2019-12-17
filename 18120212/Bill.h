#ifndef _BILL_H
#define _BILL_H
#include"Header.h"

#include "Book.h"
#include "ListBook.h"

//class ListBook;
//class Book;

class Bill
{
private:
	vector<Book> mDanhSachSach;
	char usernameCustomer[20];
	int mSoluong;
	int mTien;
public:
	Bill();
	~Bill();
	Bill pNhapBill(ListBook&);
	int pTinhTien();
	void inBill();
	void pHieuchinh(ListBook& a);
	void pThemsach(ListBook&);
	void pXoasach();
	void pAdd(Book&);
	inline int pSoluong() { return mSoluong; }
	inline Book pGetBook(int i) { return mDanhSachSach[i]; }
	inline void setUsernameCustomer(char* username) { strcpy(usernameCustomer, username); }
	inline char* getUsernameCustomer() { return usernameCustomer; }
	void pClear() {
		mSoluong = 0;
		mTien = 0;
		mDanhSachSach.clear();
	};
};

#endif
