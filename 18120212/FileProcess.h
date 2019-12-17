#include "Header.h"
#include "User.h"
#include "Publisher.h"
#include "Composer.h"
#include "Admin.h"

void pReadFile(vector<User>& listUser, vector<Publisher>& listPublisher, vector<Composer>& listComposer, vector<Admin>& listAdmin,vector<Bill>&listBill) {
	FILE* pFile;
	int tempAmount;
	//Bill
	
	pFile = fopen("billFile.txt", "rb");

	fread(&tempAmount, sizeof(int), 1, pFile);
	int tempSoluong;
	char tempUsername[20];
	Book tempBook;
	Bill tempBill;
	for (int i = 0; i < tempAmount; i++) {
		tempBill.pClear();
		fread(&tempSoluong, sizeof(int),1, pFile);
		fread(&tempUsername, sizeof(tempUsername), 1, pFile);
		tempBill.setUsernameCustomer(tempUsername);
		for (int j = 0; j < tempSoluong; j++) {
			fread(&tempBook, sizeof(Book), 1, pFile);
			tempBill.pAdd(tempBook);
		}
		tempBill.pTinhTien();
		listBill.push_back(tempBill);
	}
	fclose(pFile);
	
	//User

	pFile = fopen("userFile.txt", "rb");

	fread(&tempAmount, sizeof(int), 1, pFile);
	listUser.resize(tempAmount);

	for (int i = 0; i < tempAmount; i++)
		fread(&listUser[i], sizeof(User), 1, pFile);
	
	fclose(pFile);

	//Publisher
	pFile = fopen("publisherFile.txt", "rb");

	fread(&tempAmount, sizeof(int), 1, pFile);
	listPublisher.resize(tempAmount);

	for (int i = 0; i < tempAmount; i++)
		fread(&listPublisher[i], sizeof(Publisher), 1, pFile);

	fclose(pFile);
	//Composer
	
	pFile = fopen("composerFile.txt", "rb");

	fread(&tempAmount, sizeof(int), 1, pFile);
	listComposer.resize(tempAmount);

	for (int i = 0; i < tempAmount; i++)
		fread(&listComposer[i], sizeof(Composer), 1, pFile);

	fclose(pFile);
	
	//Admin
	pFile = fopen("adminFile.txt", "rb");

	fread(&tempAmount, sizeof(int), 1, pFile);
	listAdmin.resize(tempAmount);

	for (int i = 0; i < tempAmount; i++)
		fread(&listAdmin[i], sizeof(Admin), 1, pFile);

	fclose(pFile);

}
void pWriteFile(vector<User>& listUser, vector<Publisher>& listPublisher, vector<Composer>& listComposer, vector<Admin>& listAdmin,  vector<Bill>&listBill) {
	FILE* pFile;
	int tempAmount;
	//Bill
	tempAmount = listBill.size();
	pFile = fopen("billFile.txt", "wb");

	fwrite(&tempAmount, sizeof(int), 1, pFile);
	int tempSoluong;
	Book tempBook;
	char tempUsername[20];
	for (int i = 0; i < tempAmount; i++)
	if(listBill[i].pSoluong()>0){
		
		tempSoluong = listBill[i].pSoluong();
		fwrite(&tempSoluong, sizeof(int), 1, pFile);

		strcpy(tempUsername, listBill[i].getUsernameCustomer());
		fwrite(&tempUsername, sizeof(tempUsername), 1, pFile);

		for (int j = 0; j < tempSoluong; j++) {
			tempBook.pSetPermission(listBill[i].pGetBook(j).pGetPermission());
			tempBook.pSetName(listBill[i].pGetBook(j).pGetName());
			tempBook.pSetCode(listBill[i].pGetBook(j).pGetCode());
			tempBook.pSetComposer(listBill[i].pGetBook(j).pGetComposer());
			tempBook.pSetPublisher(listBill[i].pGetBook(j).pGetPublisher());
			tempBook.pSetPrice(listBill[i].pGetBook(j).pGetPrice());
			fwrite(&tempBook, sizeof(Book), 1, pFile);
		}
	}
	fclose(pFile);
	//User
	tempAmount = listUser.size();
	pFile = fopen("userFile.txt", "wb");

	fwrite(&tempAmount, sizeof(int), 1, pFile);

	for (int i = 0; i < tempAmount; i++)
		fwrite(&listUser[i], sizeof(User), 1, pFile);

	fclose(pFile);
	//Publisher
	tempAmount = listPublisher.size();
	pFile = fopen("publisherFile.txt", "wb");

	fwrite(&tempAmount, sizeof(int), 1, pFile);

	for (int i = 0; i < tempAmount; i++)
		fwrite(&listPublisher[i], sizeof(Publisher), 1, pFile);

	fclose(pFile);
	//Composer
	tempAmount = listComposer.size();
	pFile = fopen("composerFile.txt", "wb");

	fwrite(&tempAmount, sizeof(int), 1, pFile);

	for (int i = 0; i < tempAmount; i++)
		fwrite(&listComposer[i], sizeof(Composer), 1, pFile);

	fclose(pFile);
	//Admin
	tempAmount = listAdmin.size();
	pFile = fopen("adminFile.txt", "wb");

	fwrite(&tempAmount, sizeof(int), 1, pFile);

	for (int i = 0; i < tempAmount; i++)
		fwrite(&listAdmin[i], sizeof(Admin), 1, pFile);

	fclose(pFile);


}

void pLoadBoook(ListBook& a) {
	FILE* pBookFile = fopen("Book.txt", "rb+");
	int mSoLuongSach;
	fread(&mSoLuongSach, sizeof(int), 1, pBookFile);

	Book tempBook;

	for (int i = 0; i < mSoLuongSach; i++) {
		fread(&tempBook, sizeof(Book), 1, pBookFile);
		a.pAddBook(tempBook);
	}
	fclose(pBookFile);
}
void pUpdateBook(ListBook& a) {
	int mSoLuongSach;
	
	FILE* pBookFile = fopen("Book.txt", "wb+");
	mSoLuongSach = a.pGetMountBook();
	fwrite(&mSoLuongSach, sizeof(int), 1, pBookFile);
	for (int i = 0; i < a.pGetMountBook(); i++)
		fwrite(&a.pInfoBook(i), sizeof(Book), 1, pBookFile);

	fclose(pBookFile);
}