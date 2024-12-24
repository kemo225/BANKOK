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
class ClsUpdateClientScreen :protected::ClsScreen
{
private:
	static void _Reedclient(ClsClient& client)
	{
		cout << "Please enter First Name      : ";
		client.FirstName = clsInputValidate::ReedString();
		cout << "Please enter Last Name       : ";
		client.LastName = clsInputValidate::ReedString();
		cout << "Please enter Email           : ";
		client.Email = clsInputValidate::ReedString();
		cout << "Please enter PinCode         : ";
		client.Pincode = clsInputValidate::ReedString();
		cout << "Please enter Phone           : ";
		client.Phone = clsInputValidate::ReedString();
		cout << "Please enter Account Balance : ";
		client.AccountBalance = stoi(clsInputValidate::ReedString());
	}
public:
	static void ShowUpdateClientscreen()

	{
		if (!AccessPageRight(clsUser::_enpermission::enUpdateclient))
		{
			return;
		}
		string tittle = "\tUpdate Client Screen";
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

			cout << "\n\n Client Update : \n";
			cout << "--------------------------------------\n";

			_Reedclient(Client);

			cout << "--------------------------------------\n";

			ClsClient::ensaveresult SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case ClsClient::ensaveresult::SVsuccess:
			{
				cout << "Succeded Updated .\n\n";
				break;
			}

			case ClsClient::ensaveresult::SVfailed:
			{
				cout << "Failure Updated .\n\n";
				break;
			}
			}
		
		
	}
};

