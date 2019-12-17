#include "Composer.h"
Composer::Composer() {

}

Composer::~Composer() {

}


ListBook Composer::getList(ListBook& a) {
	ListBook tempList;
	for (int i = 0; i < a.pGetMountBook(); i++) {
		if (strcmp(a.pInfoBook(i).pGetComposer(), this->getName()) == 0)
			if (a.pInfoBook(i).pGetPermission() / 10 == 1)
				tempList.pAddBook(a.pInfoBook(i));

	}
	return tempList;
}
//12, 0x tac gia khong duoc,x0 nxb khong duoc
void Composer:: pXoasach(ListBook& a, char* key) {
	int id = pTimSachCode(a, key);
	if (id == -1 || a.pInfoBook(id).pGetPermission()/10==0) {
		cout << "Khong tim duoc sach!" << endl;

	}
	else if (strcmp(mName, a.pInfoBook(id).pGetComposer()) != 0)
	{
		cout << "Quyen sach nay khong thuoc tham quyen cua ban!" << endl;
	}
	else {
		a.pInfoBook(id).pSetPermission(a.pInfoBook(id).pGetPermission() % 10);
		cout << "Da xoa sach thanh cong!" << endl;
	}
	system("pause");
	return;
}

void Composer::pSuasach(ListBook& a,const char* key) {
	int id = pTimSachCode(a, key);
	if (id == -1 || a.pInfoBook(id).pGetPermission() / 10 == 0) {
		cout << "Khong tim duoc sach!" << endl;

	}
	else if (strcmp(mName, a.pInfoBook(id).pGetComposer()) != 0)
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