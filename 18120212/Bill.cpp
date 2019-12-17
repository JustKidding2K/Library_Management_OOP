#include "Bill.h"



Bill::Bill()
{

}


Bill::~Bill()
{
}
void Bill::pThemsach(ListBook& a) {
	Book b;
	vector<int>res;
	int price;
	int id;
	char* temp = new char[15];
	cout << "Nhap vao ma sach : ";
	rewind(stdin);
	cin.getline(temp, 15);
	a.pSearchBook(temp, res, 0);
	if (res.size() == 0) {
		cout << "Khong tim duoc ";
		cin.ignore();
		return;
	}
	b.pSetCode(temp);

	id = res.back();
	res.pop_back();
	cout << "Ten sach la: " << a.pInfoBook(id).pGetName() << endl;
	b.pSetName(a.pInfoBook(id).pGetName());

	cout << "Gia tien la: " << a.pInfoBook(id).pGetPrice() << endl;
	b.pSetPrice(a.pInfoBook(id).pGetPrice());
	//cout << "Nhap vao ten sach : ";
	//cin.getline(temp, 100);
	//b.pSetName(temp);

	mDanhSachSach.push_back(b);
}
void Bill::pXoasach() {
	cout << "Chon STT quyen sach muon xoa: ";
	int stt;
	rewind(stdin);
	cin >> stt;
	if (stt > mDanhSachSach.size()) {
		cout << "Khong ton tai quyen sach nay trong hoa don" << endl;
		return;
	}
	mDanhSachSach.erase(mDanhSachSach.begin() + stt-1);
	cout << "Da xoa" << endl;

}
Bill Bill::pNhapBill(ListBook& a) {
	cout << "Nhap vao so luong sach muon mua: ";
	cin >> mSoluong;

	Book b;
	vector<int>res;
	int price;
	int id;
	char* temp = new char[15];
	if (mSoluong <= 0)return *this;
	for (int i = 0; i < mSoluong; i++) {
		cout << "Quyen thu " << i + 1 << " :" << endl;

		rewind(stdin);

		cout << "Nhap vao ma sach : ";
		cin.getline(temp, 15);
		a.pSearchBook(temp, res, 0);
		if (res.size() == 0) {
			cout << "Khong tim duoc ";
			cin.ignore();
			continue;
		}
		b.pSetCode(temp);

		id = res.back();
		res.pop_back();
		b.pSetPermission(a.pInfoBook(id).pGetPermission());
		cout << "Ten sach: " << a.pInfoBook(id).pGetName() << endl;
		b.pSetName(a.pInfoBook(id).pGetName());

		cout << "Gia tien: " << a.pInfoBook(id).pGetPrice() << endl;
		b.pSetPrice(a.pInfoBook(id).pGetPrice());

		cout << "Tac gia: " << a.pInfoBook(id).pGetComposer() << endl;
		b.pSetComposer(a.pInfoBook(id).pGetComposer());

		cout << "Nha xuat ban: " << a.pInfoBook(id).pGetPublisher() << endl;
		b.pSetPublisher(a.pInfoBook(id).pGetPublisher());
		//cout << "Nhap vao ten sach : ";
		//cin.getline(temp, 100);
		//b.pSetName(temp);

		mDanhSachSach.push_back(b);

	}
	mSoluong = mDanhSachSach.size();
	return *this;
}

int Bill::pTinhTien() {
	mTien = 0;
	for (int i = 0; i < mDanhSachSach.size(); i++) {
		mTien += mDanhSachSach[i].pGetPrice();
	}
	mSoluong = mDanhSachSach.size();
	return mTien;
}

void Bill::inBill() {
	pTinhTien();
	system("cls");
	cout << "-------Hoa-Don--------" << endl;
	for (int i = 0; i < mDanhSachSach.size(); i++) {
		cout << "Quyen thu " << i + 1 << endl;
		cout <<"Ten sach: "<< mDanhSachSach[i].pGetName() << endl;
		cout << "Ma sach: " << mDanhSachSach[i].pGetCode() << endl;
		cout << "Gia tien: " << mDanhSachSach[i].pGetPrice() << endl;
		cout << "Tac gia: " << mDanhSachSach[i].pGetComposer() << endl;
		cout << "NXB: " << mDanhSachSach[i].pGetPublisher() << endl;
		cout << endl;
	}
	cout << "Tong: " << mTien;
}

void Bill::pHieuchinh(ListBook& a) {
	int cmd = 0;
	while (1) {
		system("cls");
		inBill();
		cout << endl;
		cout << "1.Them sach\n";
		cout << "2.Xoa sach\n";
		cout << "Other.Hoan tat\n";
		cin >> cmd;
		if (cmd == 0)break;
		switch (cmd) {
		case 1:
			pThemsach(a);
			break;
		case 2:
			pXoasach();
			break;
		}

	}
}
void Bill:: pAdd(Book& a) {
	mDanhSachSach.push_back(a);
}


