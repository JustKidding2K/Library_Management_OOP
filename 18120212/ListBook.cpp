#include "ListBook.h"


ListBook::ListBook() {

}

ListBook::~ListBook() {

}



bool ListBook::pAddBook(Book a) {

	//mCountBook++;
	mListBook.push_back(a);
	return 1;
}
// trả về vector res bool
void ListBook::pSearchBook(const char* key, vector<int>& res, bool mode) {
	if (mode == 0) {
		for (int i = 0; i < mListBook.size(); i++)
			if (strcmp(mListBook[i].pGetCode(), key) == 0)
			{
				res.push_back(i);
				break;
			}
		return;
	}

	for (int i = 0; i < mListBook.size(); i++)
		if (strcmp(mListBook[i].pGetCode(), key) == 0)
			res.push_back(i);
}


void ListBook::pInputBook() {
	//	system("cls");
	rewind(stdin);
	int n;
	cout << "Nhap vao so luong sach muon them: ";
	cin >> n;

	char* name = new char[100];
	char* code = new char[15];
	char* composer = new char[100];
	char* publisher = new char[100];
	int price;

	Book b;
	for (int i = 0; i < n; i++) {
		cout << "Quyen thu " << i+1 << endl;
		cin.ignore();
		cout << "Nhap vao ten sach: ";
		cin.getline(name, 100);

		cout << "Nhap vao ma sach: ";
		cin.getline(code, 15);

		cout << "Nhap vao ten Tac gia: ";
		cin.getline(composer, 70);
		
		cout << "Nhap vao ten Nha xuat ban: ";
		cin.getline(publisher, 100);

		cout << "Nhap vao gia sach: ";
		cin >> price;

		b.pSetCode(code);
		b.pSetName(name);
		b.pSetPrice(price);
		b.pSetComposer(composer);
		b.pSetPublisher(publisher);
		b.pSetPermission(12);
		pAddBook(b);
	}
}
bool ListBook::pRemoveBook(char* key) {
	vector<int>res;
	pSearchBook(key, res, 0);
	if (res.size() == 0)return 0;
	mListBook.erase(mListBook.begin() + res[0]);
	return 1;
}

bool ListBook::pEditBook(char* key, int price) {
	vector<int>res;
	pSearchBook(key, res, 0);
	if (res.size() == 0)return 0;
	mListBook[res[0]].pSetPrice(price);
	return 1;

}


int ListBook::pGetMountBook() {
	return mListBook.size();

}

Book& ListBook::pInfoBook(int id) {
	return mListBook[id];
}
