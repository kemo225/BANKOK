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

class ClsFindClientScreen :protected::ClsScreen
{

public:
	static void Showfindclientscreen()
	{
		if (!AccessPageRight(clsUser::_enpermission::enFindclient))
		{
			return;
		}
		string tittle = "\tFind Client Screen";
		_DrawScreenHeader(tittle);
		
			cout << "Please Enter Account Number ?  ";
			string AccountNumber = clsInputValidate::ReedString();
			cout << endl;

			while (!ClsClient::IsClientexist(AccountNumber))
			{
				cout << "Error , Account Number is Not Found, Enter another : ";
				AccountNumber = clsInputValidate::ReedString();
			}

			ClsClient Client = ClsClient::Find(AccountNumber);
			Client.print();

		
		

	}

};

