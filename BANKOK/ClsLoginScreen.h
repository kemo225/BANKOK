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
#include "clsUser.h"
#include "ClsMainmenu.h"
#include "ClsUserlistScreen.h"
#include "ClsAddnewUserScreen.h"
#include "ClsDeleteuserScreen.h"
#include "ClsUpdateUserScreen.h"
#include "ClsFindUserScreen.h"


using namespace std;
class ClsLoginScreen :protected::ClsScreen
{
private:
	static string _ReedUser()
	{
		cout << "Enter UserName ? ";
		string username = clsInputValidate::ReedString();
		return username;
	}
	static string _Reedpass()
	{
		cout << "Enter Password ? ";
		string Password = clsInputValidate::ReedString();
		return Password;
	}
public:

	static bool ShowLoginScreen()
	{
		string tittle = "\t   Login Screen";
		_DrawScreenHeader(tittle);
		short Loginfaildd = 0, Trials = 3;
		bool loginfaild = false;
		do 
		{
			if (loginfaild)
			{
				Loginfaildd++;
				Trials--;
				cout << "Invalid Password/UserName!\n"
					<< "You Have " << Trials<< " Trials to Login\n\n";
				if (Loginfaildd == 3)
				{
					cout << "You Are Lock After 3 Trials Faild\n";
					return 0;
				}
			}
			string Username = _ReedUser();
			string password = _Reedpass();
			cout << "\n";
			CurrentUser = clsUser::Find(Username, password);
			
			loginfaild = CurrentUser.IsEmpty();

		} while (loginfaild);

		CurrentUser.AdddatetoLoginRegister();

		ClsMainmenu::ShowMainMenue();
		return 1;

	}
};
