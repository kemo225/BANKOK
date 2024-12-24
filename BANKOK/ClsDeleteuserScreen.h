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
class ClsDeleteuserScreen :protected::ClsScreen
{
private:
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
	static string _ReedUsername()
	{
		cout << "Please Enter UserName ? ";
		string s = clsInputValidate::ReedString();
		return s;
	}
	
public:

	static void ShowDeleteUserScreen()
	{
		vector<clsUser>Users_date = clsUser::GetUsersList();

		string tittle = "\tDelete User Screen";
		_DrawScreenHeader(tittle);

		string Username = _ReedUsername();

		while (!(clsUser::IsUserExist(Username)))
		{
			cout << "UserName is Not Found,Enter Another : ";
			cin >> Username;
		}

		clsUser CurrentUser = clsUser::Find(Username);

		_printUser(CurrentUser);

		char answer = clsInputValidate::ReedAnswerYorN("Are you Sure perform this Operation ? Y/N ? \n");

		if(answer=='y'||answer=='Y')
		{
		if (CurrentUser.Delete())
		{
			cout << "\nThe Operation Deleted is Succededd\n";
			return;
		}
		else
		{
			cout << "\nError,The Operation was canceled\n";
			return;
		}
		}

		cout << setw(8) << "" << "\nThank You\n";
	}
};

