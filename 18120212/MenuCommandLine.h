#pragma once
#include "Header.h"
class MenuCommandLine
{
public:
	
	vector<string>choice;

	inline MenuCommandLine() {};
	int getCommand() {
		
		system("cls");
		cout << choice[0] << endl;
		for (int i = 1; i < choice.size()-1; i++) {
			cout << i << "." << choice[i] << endl;
		}
		cout << "0." <<choice[choice.size()-1]<< endl;

		int cmd;
		cin >> cmd;


		if (cmd >= 1 && cmd <= choice.size())return cmd;
		return 0;
	}

};



