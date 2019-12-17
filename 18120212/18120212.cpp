#include "Header.h"
#include "Book.h"
#include "ListBook.h"
#include "Bill.h"
#include "Guest.h"
#include "User.h"
#include "Composer.h"
#include "Publisher.h"
#include "FileProcess.h"
#include "MenuCommandLine.h"
//Account admin de thay dang nhap 
//Username: admin 
//Password: password
void genMenu(MenuCommandLine& Menu1, MenuCommandLine& Menu2) {
	Menu1.choice.push_back("Moi chon yeu cau:");
	Menu1.choice.push_back("Tim sach");
	Menu1.choice.push_back("Dang nhap");
	Menu1.choice.push_back("Thoat");

	Menu2.choice.push_back("Moi chon yeu cau:");
	Menu2.choice.push_back("Tim sach");//1
	Menu2.choice.push_back("Mua sach");//2
	Menu2.choice.push_back("Them sach");//3
	Menu2.choice.push_back("Xoa sach");//4
	Menu2.choice.push_back("Sua sach");//5
	Menu2.choice.push_back("Xem tat ca cac sach thuoc phan quyen cua ban");//6
	Menu2.choice.push_back("Tao them nguoi dung");//7
	Menu2.choice.push_back("Xem danh sach tat ca nguoi dung");//8
	Menu2.choice.push_back("Xem danh sach hoa don");//9
	Menu2.choice.push_back("Xem NXB ban duoc nhieu tien nhat");//10
	Menu2.choice.push_back("Xem cac quyen sach khong ban duoc");//11
	Menu2.choice.push_back("Dang xuat");//0
	
}
int login(int& idUser,vector<User>& listUser, vector<Publisher>& listPublisher, vector<Composer>& listComposer, vector<Admin>& listAdmin) {
	char* tempUsername = new char[20];
	char* tempPassword = new char[20];

	cout << "User: ";
	rewind(stdin);
	cin >> tempUsername;

	cout << "Password: ";
	rewind(stdin);
	cin >> tempPassword;

	for (int i = 0; i < listUser.size(); i++) {
		if (strcmp(listUser[i].getUserName(), tempUsername) == 0)
			if (strcmp(listUser[i].getPassWord(), tempPassword) == 0) { 
				idUser = i;

				return 1; 
			}
	}
	for (int i = 0; i < listComposer.size(); i++) {
		if (strcmp(listComposer[i].getUserName(), tempUsername) == 0)
			if (strcmp(listComposer[i].getPassWord(), tempPassword) == 0) {
				idUser = i;
				return 2;
			}
	}
	for (int i = 0; i < listPublisher.size(); i++) {
		if (strcmp(listPublisher[i].getUserName(), tempUsername) == 0)
			if (strcmp(listPublisher[i].getPassWord(), tempPassword) == 0) {
				idUser = i;
				return 3;
			}
	}

	for (int i = 0; i < listAdmin.size(); i++) {
		if (strcmp(listAdmin[i].getUserName(), tempUsername) == 0)
			if (strcmp(listAdmin[i].getPassWord(), tempPassword) == 0) {
				
				
				idUser =i;
				return 4;
			}
	}
	return 0;
}
int main()
{
	/*
	FILE* pFile;
	pFile = fopen("billFile.txt", "wb");
	int moun = 0;
	fwrite(&moun, sizeof(int), 1, pFile);
	fclose(pFile);
	//*/
	//Doc file sach

	ListBook a;
	pLoadBoook(a);

	//Doc file User Composer Publisher
	vector<User> listUser;
	vector<Composer> listComposer;
	vector<Publisher> listPublisher;
	vector<Admin>listAdmin;
	vector<Bill>listBill;

	Guest* currentGuest;
	Guest* newGuest;
	
	pReadFile(listUser, listPublisher, listComposer, listAdmin,listBill);
	
	//Menu
	MenuCommandLine Menu1;
	MenuCommandLine Menu2;
	genMenu(Menu1, Menu2);
	int cmd;
	int cmd2;
	
	//Guest
	char* tempCode = new char[15];
	int idUser;
	int idLogin;
	int result;
	int type;
	User tempUser;
	Composer tempComposer;
	Publisher tempPublisher;
	Admin tempAdmin;
	ListBook tempList;
	//===============
	
	while (1) {
		cmd = Menu1.getCommand();
		if (cmd == 0)break;
		currentGuest = new Guest;
		switch (cmd)
		{
		case 1:
			cout << "Nhap vao ma quyen sach can tim: ";
			cin >> tempCode;
			result = currentGuest->pTimSachCode(a, tempCode);
			if (result != -1)a.pInfoBook(result).pOuput();
			cout << endl;
			system("pause");
			break;
		case 2:
			
			idLogin = login(idUser, listUser, listPublisher, listComposer, listAdmin) ;
			if (idLogin == 0) {
				cout << "Username hoac Password khong dung, moi ban thu lai sau!" << endl;
				system("pause");
				break;
			}
			else {
				cout << "Dang nhap thanh cong!" << endl;
				system("pause");
			}
			switch(idLogin)
			{
			case 1:
				tempUser.setName(listUser[idUser].getName());
				tempUser.setUsername(listUser[idUser].getUserName());
				tempUser.setPassword(listUser[idUser].getPassWord());
				currentGuest = &tempUser;
				break;
			case 2:
				tempComposer.setName(listComposer[idUser].getName());
				tempComposer.setUsername(listComposer[idUser].getUserName());
				tempComposer.setPassword(listComposer[idUser].getPassWord());
				currentGuest = &tempComposer;
				break;
			case 3:
				tempPublisher.setName(listPublisher[idUser].getName());
				tempPublisher.setUsername(listPublisher[idUser].getUserName());
				tempPublisher.setPassword(listPublisher[idUser].getPassWord());
				currentGuest = &tempPublisher;
				break;
			case 4:
				tempAdmin.setName(listAdmin[idUser].getName());
				tempAdmin.setUsername(listAdmin[idUser].getUserName());
				tempAdmin.setPassword(listAdmin[idUser].getPassWord());
				currentGuest = &tempAdmin;
				break;
			default:
				break;
			}
			while (1)
			{
				
				{
					cmd2 = Menu2.getCommand();
					if (cmd2 == 0) break;
					switch (cmd2)
					{
					case 1:
						system("cls");
						cout << "Nhap vao ma quyen sach can tim: ";
						cin >> tempCode;
						result=currentGuest->pTimSachCode(a, tempCode);
						if (result != -1)a.pInfoBook(result).pOuput();
						cout << endl;
						system("pause");
						break;
					case 2:
						system("cls");
						listBill.push_back(currentGuest->pMuasach(a));
						system("pause");
						break;
					case 3:
						system("cls");
						currentGuest->pThemsach(a);
						system("pause");
						break;
					case 4:
						system("cls");
						cout << "Nhap vao ma quyen sach muon xoa: ";
						rewind(stdin);
						cin >> tempCode;
						currentGuest->pXoasach(a, tempCode);
						system("pause");
						break;

					case 5:
						system("cls");
						cout << "Nhap vao ma quyen sach muon sua: ";
						rewind(stdin);
						cin >> tempCode;
						currentGuest->pSuasach(a,tempCode);
						system("pause");
						break;
					case 6:
						system("cls");
						cout << "Cac quyen sach thuoc tham quyen cua ban la: " << endl;
						tempList = currentGuest->getList(a);
						for (int i = 0; i < tempList.pGetMountBook(); i++) {
							cout << i + 1 << endl;
							tempList.pInfoBook(i).pOuput();
							cout << endl;
						}
						system("pause");
						break;
					case 7:
						system("cls");
						if (idLogin != 4) {
							cout << "Ban khong co quyen thuc hien tac vu nay!" << endl;
							system("pause");
							break;
						}
						type = 0;
						tempAdmin.pTaoUser(type, listUser, listComposer, listPublisher, listAdmin);
						if (type != 0)cout << "Tao nguoi dung moi thanh cong!" << endl;
						system("pause");
						break;
					case 8:
						system("cls");
						if (idLogin != 4) {
							cout << "Ban khong co quyen thuc hien tac vu nay!" << endl;
							system("pause");
							break;
						}
						tempAdmin.pXemUser(listUser, listComposer, listPublisher, listAdmin);
						system("pause");
						break;
					case 9:
						currentGuest->pInListBill(listBill);
						system("pause");
						break;
					case 10:
						system("cls");
						if (idLogin != 4) {
							cout << "Ban khong co quyen thuc hien tac vu nay!" << endl;
							system("pause");
							break;
						}
						tempAdmin.pTimNXBmax(listBill, listPublisher);
						system("pause");
						break;
					case 11:
						system("cls");
						/*if (idLogin != 4) {
							cout << "Ban khong co quyen thuc hien tac vu nay!" << endl;
							system("pause");
							break;
						}*/
						currentGuest->pTimSachKhongDuocMua(listBill, a);
						system("pause");
						break;
					default:
						break;
						break;
					}
				}
			}
			break;
		default:
			break;
		}
 		
		
	}
	pWriteFile(listUser, listPublisher, listComposer, listAdmin,listBill);
	pUpdateBook(a);
	
	
	/*while (1) {
		if (inMenu((a))) { 
			//Update Book.txt
			pUpdateBook(a);
			//Update User File 
			pWriteFile(listUser, listPublisher, listComposer, listAdmin);
			//================

		}
	};*/
}
