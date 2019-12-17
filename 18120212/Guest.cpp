#include "Guest.h"

Guest::Guest()
{
	//ctor
}

Guest::~Guest()
{
	//dtor
}

/*void Guest::pTimSach(ListBook& a) {
	cout << "Nhap vao ma quyen sach ban muon tim: ";

	char* tempCode = new char;
	cin >> tempCode;

	vector<int> res;
	a.pSearchBook(tempCode, res, 0);
	if (res.size() == 0) cout << "Khong tim duoc quyen sach ban can";
	else {
		Book tempBook;
		tempBook = a.pInfoBook(res[0]);
		tempBook.pOuput();
	}
	cout << endl;
	system("pause");

}*/
int Guest::pTimSachCode(ListBook& a,const char* key) {
	vector<int> tempRes;
	a.pSearchBook(key, tempRes, 0);
	if (tempRes.size() == 0) {
		cout << "Khong tim duoc quyen sach ban can!" << endl;
		return -1;
	}
	return tempRes[0];
}

ListBook Guest::getList(ListBook& a) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
	ListBook tempList;//size=0
	return tempList;

}

void Guest :: pThemsach(ListBook& a) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
}
void Guest::pXoasach(ListBook& a, const char*key) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
}

void Guest::pSuasach(ListBook& a,const char* key) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
}

Bill Guest::pMuasach(ListBook& a) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
	Bill emptyBill     ;
	return emptyBill;
}

void Guest:: pInListBill(vector<Bill>&listBill) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
}

void Guest::pTimSachKhongDuocMua(vector<Bill>&listBill, ListBook& a) {
	cout << "Ban khong co quyen thuc hien lenh nay, moi Dang Nhap!" << endl;
}