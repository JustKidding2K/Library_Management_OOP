#include "Admin.h"
void Admin:: pThemsach(ListBook& a) {
	a.pInputBook();
}

ListBook Admin::getList(ListBook& a) {
	ListBook tempList;
	for (int i = 0; i < a.pGetMountBook(); i++) {
				tempList.pAddBook(a.pInfoBook(i));
	}
	return tempList;
}
void Admin::pXoasach(ListBook& a, char* key) {
	int id = pTimSachCode(a, key);
	if (id == -1 ) {
		cout << "Khong tim duoc sach!" << endl;
	}
	else {
		a.pRemoveBook(key);
		cout << "Da xoa sach thanh cong!" << endl;
	}
	return;
}

void Admin::pSuasach(ListBook& a,const char* key) {
	int id = pTimSachCode(a, key);
	if (id == -1 ) {
		cout << "Khong tim duoc sach!" << endl;

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

void Admin::pTaoUser(int& type, vector<User>& listUser, vector<Composer>& listComposer, vector<Publisher>& listPublisher, vector<Admin>& listAdmin) {
	MenuCommandLine MenuTaoUser;
	
	MenuTaoUser.choice.push_back("Ban muon tao nguoi dung loai nao: ");
	MenuTaoUser.choice.push_back("User");
	MenuTaoUser.choice.push_back("Tac gia");
	MenuTaoUser.choice.push_back("Nha xuat ban");
	MenuTaoUser.choice.push_back("Admin");
	MenuTaoUser.choice.push_back("Thoat");
	int cmd = MenuTaoUser.getCommand();
	if (cmd == 0)return;
	User tempUser;
	Composer tempComposer;
	Publisher tempPublisher;
	Admin tempAdmin;
	char* tempName = new char[50];
	char* tempUsername = new char[20];
	char* tempPassword = new char[20];
	cout << "Nhap vao Ho va Ten nguoi dung: ";
	rewind(stdin);
	cin.getline(tempName,50);

	cout << "Nhap vao Ten dang nhap: ";
	rewind(stdin);
	cin.getline(tempUsername, 20);

	cout << "Nhap vao Mat khau: ";
	rewind(stdin);
	cin.getline(tempPassword, 20);

	switch (cmd)
	{
	case 1:
		tempUser.setName(tempName);
		tempUser.setUsername(tempUsername);
		tempUser.setPassword(tempPassword);
		type = 1;
		listUser.push_back(tempUser);
		break;
	case 2:
		tempComposer.setName(tempName);
		tempComposer.setUsername(tempUsername);
		tempComposer.setPassword(tempPassword);
		type = 2;
		listComposer.push_back(tempComposer);
		break;
	case 3:
		tempPublisher.setName(tempName);
		tempPublisher.setUsername(tempUsername);
		tempPublisher.setPassword(tempPassword);
		type = 3;
		listPublisher.push_back(tempPublisher);
		break;
	case 4:
		tempAdmin.setName(tempName);
		tempAdmin.setUsername(tempUsername);
		tempAdmin.setPassword(tempPassword);
		type = 4;
		listAdmin.push_back(tempAdmin);
		break;
	default:
		break;
	}

}

void Admin:: pXemUser(vector<User>& listUser, vector<Composer>& listComposer, vector<Publisher>& listPublisher, vector<Admin>& listAdmin) {
	cout << "Danh sach nguoi dung trong thu vien:" << endl;
	
	cout << endl;
	cout << "Danh sach User: " << endl;
	cout << "So luong: " << listUser.size() << endl;
	
	for (int i = 0; i < listUser.size(); i++) {
		cout << endl;
		cout << "User thu " << i + 1 << " :" << endl;
		cout <<"Ho va Ten: "<< listUser[i].getName()<< endl;
		cout <<"Username: "<< listUser[i].getUserName()<< endl;
		//cout <<"Password: "<< listUser[i].getPassWord()<< endl;
		cout <<"Password: *********"<< endl;
	}

	cout << endl;
	cout << "Danh sach Tac gia: " << endl;
	cout << "So luong: " << listComposer.size() << endl;
	
	for (int i = 0; i < listComposer.size(); i++) {
		cout << endl;
		cout << "Tac gia thu " << i + 1 << " :" << endl;
		cout << "Ho va Ten: " << listComposer[i].getName() << endl;
		cout << "Username: " << listComposer[i].getUserName() << endl;
		//cout << "Password: " << listComposer[i].getPassWord() << endl;
		cout << "Password: *********" << endl;
	}

	cout << endl;
	cout << "Danh sach Nha xuat ban: " << endl;
	cout << "So luong: " << listPublisher.size() << endl;
	
	for (int i = 0; i < listPublisher.size(); i++) {
		cout << endl;
		cout << "Tac gia thu " << i + 1 << " :" << endl;
		cout << "Ho va Ten: " << listPublisher[i].getName() << endl;
		cout << "Username: " << listPublisher[i].getUserName() << endl;
		//cout << "Password: " << listPublisher[i].getPassWord() << endl;
		cout << "Password: *********" <<  endl;
	}
	
	cout << endl;
	cout << "Danh sach Admin: " << endl;
	cout << "So luong: " << listAdmin.size() << endl;
	
	for (int i = 0; i < listAdmin.size(); i++) {
		cout << endl;
		cout << "Admin thu " << i + 1 << " :" << endl;
		cout << "Ho va Ten: " << listAdmin[i].getName() << endl;
		cout << "Username: " << listAdmin[i].getUserName() << endl;
		//cout << "Password: " << listAdmin[i].getPassWord() << endl;
		cout << "Password: *********" << endl;
	}
	
}

void Admin::pInListBill(vector<Bill>&listBill) {
	cout << "Danh sach Hoa don trong cua hang: " << endl;
	
	for (int i = 0; i < listBill.size(); i++) {
		cout << endl;
		cout << "Hoa don thu " << i + 1 << " :" << endl;
		cout << "Khach hang: " << listBill[i].getUsernameCustomer() << endl;
		for (int j = 0; j < listBill[i].pSoluong(); j++) {
			cout << j + 1 << ". ";
			cout << "Ten sach: " << listBill[i].pGetBook(j).pGetName() << "   Gia tien: " << listBill[i].pGetBook(j).pGetPrice();
			cout << endl;
		}
	}
}

void Admin::pTimNXBmax(vector<Bill>listBill, vector<Publisher>listPublisher) {
	vector<int>result;
	result.resize(listPublisher.size());
	if (result.size() == 0)return;
	for (int i = 0; i < result.size(); i++) result[i] = 0;
	for (int i = 0; i < listBill.size(); i++) {
		for (int j = 0; j < listBill[i].pSoluong(); j++) {
			for (int k = 0; k < listPublisher.size(); k++) {
				if (strcmp(listBill[i].pGetBook(j).pGetPublisher(), listPublisher[k].getName()) == 0)
					result[k] = result[k] + listBill[i].pGetBook(j).pGetPrice();
			}
		}
	}
	
	int max = result[0];
	int id = 0;
	for(int i=0;i<result.size();i++)
		if (max < result[i]) {
			max = result[i];
			id = i;
		}
	cout << "Cac NXB ban duoc nhieu nhat la: " << endl;
	for (int i = 0; i < result.size(); i++)
		if (max == result[i]) {
			cout <<  endl;
			cout << listPublisher[i].getUserName() << endl;
		}
	cout << "Tong so tien ban duoc la: " << max << endl;

}

void Admin::pTimSachKhongDuocMua(vector<Bill>&listBill, ListBook& a) {
	vector<int>result;
	result.resize(a.pGetMountBook());
	if (result.size() == 0)return;
	for (int i = 0; i < result.size(); i++) result[i] = 0;
	for (int i = 0; i < listBill.size(); i++) {
		for (int j = 0; j < listBill[i].pSoluong(); j++) {
			for (int k = 0; k < a.pGetMountBook(); k++) {
				if (strcmp(listBill[i].pGetBook(j).pGetCode(),a.pInfoBook(k).pGetCode() ) == 0)
					result[k] ++;
			}
		}
	}

	cout << "Nhung quyen sach khong duoc mua la: " << endl;
	for (int i = 0; i < a.pGetMountBook(); i++) 
	if(result[i]==0){
		cout << endl;
		a.pInfoBook(i).pOuput();
	}
}