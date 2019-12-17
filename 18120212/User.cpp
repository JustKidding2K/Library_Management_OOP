#include "User.h"

User::User() {

}
User::User(char* username, char* password) {
	strcpy(mName, "empty\0");
	strcpy(mUserName, username);
	strcpy(mUserName, username);
}
User::~User() {

}
Bill User::pMuasach(ListBook& a) {
	Bill tempBill;
	tempBill.pNhapBill(a);
	tempBill.pHieuchinh(a);
	tempBill.setUsernameCustomer(mUserName);
	return tempBill;
}
