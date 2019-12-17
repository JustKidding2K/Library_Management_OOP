#ifndef _USER_H
#define _USER_H

#include "Header.h"
#include "Guest.h"

class User :public Guest
{
protected:
	char mName[50];
	char mUserName[20];
	char mPassWord[20];
public:
		User();
		User(char*, char*);
		~User();
		 inline void setName(const char* name) { strcpy(mName,name); };
		 inline void setUsername(const char* username) { strcpy(mUserName, username); };
		 inline void setPassword(const char* pass) { strcpy(mPassWord, pass); };

		 inline char* getName() { return mName; };
		 inline char* getUserName() { return mUserName; };
		 inline char* getPassWord() { return mPassWord; };

		virtual Bill pMuasach(ListBook& a);
		
	
	
	
};
#endif
