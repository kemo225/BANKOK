#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsClient.h"
#include "ClsDate.h"
#include "ClsInputValid.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsPerson.h"
#include "ClsShowclientlis.h"
#include "ClsMainmenu.h"
#include "clsUser.h"

using namespace std;
class ClsFindUserScreen :protected::ClsScreen
{
private:
	static string _ReedUsername()
	{
		cout << "Please Enter UserName ? ";
		string s = clsInputValidate::ReedString();
		return s;
	}
	static void _printUser(clsUser u)
	{
		cout << "\nUser Data : \n\n";
		cout << "--------------------------------------------------------\n\n";
		cout << "First Name          : " << u.FirstName << endl;
		cout << "Last Name           : " << u.LastName << endl;
		cout << "Full Name           : " << u.fullName() << endl;
		cout << "UserName            : " << u.UserName << endl;
		cout << "Password            : " << u.Password << endl;
		cout << "Permission          : " << u.Permissions << endl;
		cout << "--------------------------------------------------------\n\n";
	}

public:

	static void ShowFinduserScreen()
	{
		vector<clsUser>Users_date = clsUser::GetUsersList();

		string tittle = "\tFind User Screen";
		_DrawScreenHeader(tittle);

		string Username = _ReedUsername();

		while (!(clsUser::IsUserExist(Username)))
		{
			cout << "User Name is Not Found,Enter Another : ";
			cin >> Username;
		}

		clsUser CurrentUser = clsUser::Find(Username);

		_printUser(CurrentUser);

		cout << setw(8) << "" << "\nThank You\n\n";

	}
};

