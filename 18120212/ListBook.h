#ifndef _LISTBOOK_H
#define _LISTBOOK_H

#include "Book.h"
class Book;
class ListBook
{
private:
	int mCountBook;
	vector <Book> mListBook;
public:
	//static int mCountList;
	ListBook();

	~ListBook();

	void pSearchBook(const char*, vector<int>& res, bool mode);
	bool pAddBook(Book);
	Book& pInfoBook(int);
	void pInputBook();
	bool pRemoveBook(char*);
	bool pEditBook(char*, int);
	int pGetMountBook();



};
#endif
