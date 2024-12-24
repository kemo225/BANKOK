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
#include "Global.h"
using namespace std;
class ClsLoginRegisterScreen:protected::ClsScreen
{
private:
	static void _PrintlineinLoginScreen(clsUser::_stLoginRegister s)
	{
		cout << setw(8) << "" << "| " << setw(38) << left << s._DateRegister << "| " << setw(28) << left << s._UserNameRegister << "| " << setw(13) << left << s._PasswordRegister << "| " << setw(8) << left << s._PermissionsRegister <<  endl;
	}
public:
	static void ShowLoginRegisterScreen()
	{
		if (!AccessPageRight(clsUser::_enpermission::enLoginRegister))
		{
			return;
		}
		vector<clsUser::_stLoginRegister>Login_date = clsUser::LoadUsersDataFromRegisterFile();

		string tittle = "\t Login Register Screen",Subtittle="(" + to_string(Login_date.size())+") Recored (S)";
		_DrawScreenHeader(tittle, Subtittle);


		cout << setw(8) << "" << "=============================================================================================================\n\n";
		cout << setw(8) << "" << setw(40) << left << "| Date " << setw(30) << left << "| UserName " << setw(15) << left << "| Password " << setw(10) << left << "| Permission " << endl;
		cout << setw(8) << "" << "=============================================================================================================\n\n";

		for (clsUser::_stLoginRegister& s : Login_date)
		{
			_PrintlineinLoginScreen(s);
		}
		cout << endl;

		cout << setw(8) << "" << "==============================================================================================================\n";

	}
};

