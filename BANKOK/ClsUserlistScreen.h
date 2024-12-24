#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "ClsDate.h"
#include "ClsUtility.h"
#include "ClsPerson.h"
#include "ClsInputValid.h"
#include "ClsScreen.h"
#include "ClsMainmenu.h"
#include "ClsUser.h"

using namespace std;
class ClsUserlistScreen:protected::ClsScreen
{
private:
	static void _Printuser(clsUser& u)
	{
		cout << setw(8) << "" << "| " << setw(16) << left << u.UserName << "| " << setw(24) << left << u.fullName()<< "| " << setw(13) << left << u.Phone << "| " << setw(11) << left << u.Password << "| " << setw(23) << left << u.Email << "| " << setw(8) << left << u.Permissions<< endl;
	}
public:
	static void ShowUserlistScreen()
	{
		vector<clsUser>User_date = clsUser::GetUsersList();

		string tittle = "\tUser List Screen";
		string subtittle = "\t(" + to_string(User_date.size()) + ")User(S)";
		_DrawScreenHeader(tittle,subtittle);


		cout << setw(8) << "" << "=============================================================================================================\n\n";
		cout << setw(8) << "" << setw(18) << left << "| User Name " << setw(26) << left << "| Full Name " << setw(15) << left << "| Phone " << setw(13) << left << "| Password " << setw(25) << left << "| Email " << setw(10) << left << "| permission " << endl << endl;
		cout << setw(8) << "" << "=============================================================================================================\n\n";
		for (clsUser& u : User_date)
		{
			_Printuser(u);
		}
		cout << setw(8) << "" << "=============================================================================================================\n\n";

	}
};

