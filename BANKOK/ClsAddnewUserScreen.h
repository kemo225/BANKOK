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
class ClsAddnewUserScreen:protected::ClsScreen
{
private:
	static string _ReedUsername()
	{
		cout << "Please Enter UserName ? ";
		string s = clsInputValidate::ReedString();
		return s;
	}
	static int _Setpermission()
	{
		int permissionofuser = 0;

		char answer = clsInputValidate::ReedAnswerYorN("Do you Want this User Have All Access ? Y / N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser = clsUser::_enpermission::enAll;
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
		answer = clsInputValidate::ReedAnswerYorN("Show Login Register ? Y/N ?  ");
		if (answer == 'y' || answer == 'Y')
		{
			permissionofuser += clsUser::_enpermission::enLoginRegister;
		}
		return permissionofuser;
	}
	static void _ReedUserInfo(clsUser &User)
	{
		cout << "Enter First Name ? ";
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

	}
public:

	static void ShowAddnewuserScreen()
	{
		vector<clsUser>Users_date = clsUser::GetUsersList();

		string tittle = "\tAdd New User Screen";
		_DrawScreenHeader(tittle);
		
		string Username = _ReedUsername();

		while (clsUser::IsUserExist(Username))
		{
			cout << "User Name is Aleady Exist,Enter Another : ";
			cin >> Username;
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(Username);

		_ReedUserInfo(NewUser);

		clsUser::enSaveResults Saveresult;
		 
		Saveresult = NewUser.Save();

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
		case clsUser::svFaildUserExists:
		{
			cout << "User is Already Exist\n";
			break;
		}
		}
	}
};

