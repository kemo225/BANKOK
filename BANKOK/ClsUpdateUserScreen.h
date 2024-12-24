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
class ClsUpdateUserScreen :protected::ClsScreen
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
		cout << "Permission            : " << u.Permissions << endl;
		cout << "--------------------------------------------------------\n\n";
	}
	static int _Setpermission()
	{
		int permissionofuser = 0;

		char answer = clsInputValidate::ReedAnswerYorN("Do you Want this User Have All Access ? Y / N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser= clsUser::_enpermission::enAll;
			return permissionofuser;
		}
	
		 answer = clsInputValidate::ReedAnswerYorN("Show Client List ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enShowclientlist;
		}
		answer = clsInputValidate::ReedAnswerYorN("Add New Client ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enAddnewClient;
		}
		answer = clsInputValidate::ReedAnswerYorN("Delete Client  ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enDeleteclient;
		}
		answer = clsInputValidate::ReedAnswerYorN("Update Client  ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enUpdateclient;
		}
		answer = clsInputValidate::ReedAnswerYorN("Find Client  ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enFindclient;
		}
		answer = clsInputValidate::ReedAnswerYorN("Transacion ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::entransaction;
		}
		answer = clsInputValidate::ReedAnswerYorN("Manage User ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enManageuser;
		}
		answer = clsInputValidate::ReedAnswerYorN("LoginRegister ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enLoginRegister;
		}
		return permissionofuser;
	}
	static void _UpdateUserInfo(clsUser& User)
	{
		cout << "\n\nEnter First Name ? ";
		User.FirstName = clsInputValidate::ReedString();
		cout << "Enter Last Name ? ";
		User.LastName = clsInputValidate::ReedString();
		cout << "Enter Phone ? ";
		User.Phone = clsInputValidate::ReedString();
		cout << "Enter Email ? ";
		User.Email = clsInputValidate::ReedString();
		cout << "Enter Password ? ";
		User.Password = clsInputValidate::ReedString();

		User.Permissions = _Setpermission();

		cout << "\n\n";
	}

public:

	static void ShowUpdateUserScreen()
	{
		vector<clsUser>Users_date = clsUser::GetUsersList();

		string tittle = "\tUpdate User Screen";
		_DrawScreenHeader(tittle);

		string Username = _ReedUsername();

		while (!(clsUser::IsUserExist(Username)))
		{
			cout << "User Name is Not Found,Enter Another : ";
			cin >> Username;
		}

		clsUser CurrentUser = clsUser::Find(Username);

		_printUser(CurrentUser);
		 
		char answer = clsInputValidate::ReedAnswerYorN("Are you Sure You Want Update this User ? Y/N ?  ");

	    if(answer=='y'||answer=='Y')
	{
	
		_UpdateUserInfo(CurrentUser);

		clsUser::enSaveResults Saveresult;

		Saveresult = CurrentUser.Save();

		switch (Saveresult)
		{
		case clsUser::svFaildEmptyObject:
		{
			cout << "Error,The Operation was canceled\n";
			break;
		}
		case clsUser::svSucceeded:
		{
			cout << "The Operation Succededd\n";
			break;
		}

		}
	}

    	cout << setw(8) << "" << "\nThank You\n";

	}
};

