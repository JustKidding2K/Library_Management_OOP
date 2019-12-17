#include "Publisher.h"

Publisher::Publisher() {

}

Publisher::~Publisher() {

}

ListBook Publisher::getPublisherList(ListBook& a) {
	ListBook tempList;
	for (int i = 0; i < a.pGetMountBook(); i++) {
		if (strcmp(a.pInfoBook(i).pGetPublisher(), this->getName()) == 0)
			if (a.pInfoBook(i).pGetPermission() % 10 == 2)
			tempList.pAddBook(a.pInfoBook(i));

	}
	return tempList;
}

ListBook Publisher:: getList(ListBook& a) {
	ListBook tempList;
	for (int i = 0; i < a.pGetMountBook(); i++) {
		if (strcmp(a.pInfoBook(i).pGetPublisher(), this->getName()) == 0)
			if (a.pInfoBook(i).pGetPermission() % 10 == 2)
				tempList.pAddBook(a.pInfoBook(i));

	}
	return tempList;
}


void Publisher::pXoasach(ListBook& a, char* key) {
	int id = pTimSachCode(a, key);
	if (id == -1 || a.pInfoBook(id).pGetPermission() % 10 == 0) {
		cout << "Khong tim duoc sach!" << endl;
	}
	else if (strcmp(mName, a.pInfoBook(id).pGetPublisher()) != 0)
	{
		cout << "Ban khong co quyen xoa quyen sach nay!" << endl;
	}
	else {
		a.pInfoBook(id).pSetPermission(a.pInfoBook(id).pGetPermission()-a.pInfoBook(id).pGetPermission() % 10);
		cout << "Da xoa sach thanh cong!" << endl;
	}
	system("pause");
	return;
}

void Publisher::pSuasach(ListBook& a,const char* key) {
	int id = pTimSachCode(a, key);
	if (id == -1 || a.pInfoBook(id).pGetPermission() % 10 == 0) {
		cout << "Khong tim duoc sach!" << endl;

	}
	else if (strcmp(mName, a.pInfoBook(id).pGetPublisher()) != 0)
	{
		cout << "Quyen sach nay khong thuoc tham quyen cua ban!" << endl;
	}
	else {
		cout << "Thong tin cu cua sach la: " << endl;
		int holdPermission = a.pInfoBook(id).pGetPermission();
		a.pInfoBook(id).pOuput();
		cout << endl;
		cout << "Moi nhap vao thong tin moi cua sach: " << endl;
		a.pInfoBook(id).pInput();
		a.pInfoBook(id).pSetPermission(holdPermission);
		cout << "Da sua sach thanh cong!" << endl;
	}
	return;
}

void Publisher::pTimSachKhongDuocMua(vector<Bill>&listBill, ListBook& a) {
	vector<int>result;
	result.resize(a.pGetMountBook());
	if (result.size() == 0)return;
	for (int i = 0; i < result.size(); i++) result[i] = 0;
	for (int i = 0; i < listBill.size(); i++) {
		for (int j = 0; j < listBill[i].pSoluong(); j++) {
			for (int k = 0; k < a.pGetMountBook(); k++) {
				if (strcmp(listBill[i].pGetBook(j).pGetCode(), a.pInfoBook(k).pGetCode()) == 0)
					result[k] ++;
				if(strcmp(listBill[i].pGetBook(j).pGetPublisher(), mName) != 0)
					result[k] ++;
			}
		}
	}

	cout << "Nhung quyen sach khong duoc mua la: " << endl;
	for (int i = 0; i < a.pGetMountBook(); i++)
		if (result[i] == 0) {
			cout << endl;
			a.pInfoBook(i).pOuput();
		}
}
