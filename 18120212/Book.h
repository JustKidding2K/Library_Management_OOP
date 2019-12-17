#ifndef _BOOK_H
#define _BOOK_H

#include "Header.h"

class Book
{
private:
	int mPermission;//12 duoc tac dong boi tat cac cac ben, 0x khong duoc tac dong boi tac gia, x0 khong duoc tac dong boi nxb
	char mName[100];
	char mCode[15];
	char mComposer[70];
	char mPublisher[100];
	int mPrice;
public:
	Book();
	~Book();
	Book(char* name, char* code, int price);

	void pInput();
	void pOuput();

	void pSetName(char*);
	void pSetCode(char*);
	void pSetPrice(int);
	void pSetPermission(int);
	void pSetPublisher(char*);
	void pSetComposer(char*);

	char* pGetName();
	char* pGetCode();
	int pGetPrice();
	int pGetPermission();
	char* pGetPublisher();
	char* pGetComposer();

	Book& operator=(const Book&);
	//bool operator==(Book);

};
#endif 