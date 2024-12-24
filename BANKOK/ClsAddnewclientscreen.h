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
class ClsAddnewclientscreen :protected::ClsScreen
{
private:
	static void _printClient(ClsClient c)
	{
		cout << "\nClient Details : \n\n";
		cout << "--------------------------------------------------------\n\n";
		cout << "First Name          : " << c.FirstName << endl;
		cout << "Last Name           : " << c.LastName << endl;
		cout << "Full Name           : " << c.fullName() << endl;
		cout << "Email               : " << c.Email << endl;
		cout << "AccountNumber       : " << c.AccountNumber << endl;
		cout << "PinCode             : " << c.Pincode << endl;
		cout << "AccountBalance      : " << c.AccountBalance << endl;
		cout << "--------------------------------------------------------\n";
	}
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
	static void ShowAddnewClientscreen()
	{
		if (!AccessPageRight(clsUser::_enpermission::enAddnewClient))
		{
			return;
		}
		string tittle = "\tAdd New Client";
		_DrawScreenHeader(tittle);


			cout << "Please Enter Account Number ?  ";
			string AccountNumber = clsInputValidate::ReedString();
			cout << endl;//

			while (ClsClient::IsClientexist(AccountNumber))
			{
				cout << "Error , Account Number is Already Exist , Enter another : ";
				AccountNumber = clsInputValidate::ReedString();
			}

		ClsClient Client = ClsClient::GetAddNewClient(AccountNumber);

		cout << "\n\n Client Adding : \n";
		cout << "--------------------------------------\n";

		_Reedclient(Client);

		cout << "--------------------------------------\n";

		ClsClient::ensaveresult SaveResult;

		SaveResult = Client.Save();
		switch (SaveResult)
		{
		case ClsClient::ensaveresult::SVsuccess:
		{
			cout << "\nAdded Client Succeded\n\n";
			break;
		}
		case ClsClient::ensaveresult::SVfailed:
		{
			cout << "\nAdded Client Failure\n\n";
			break;
		}
		}

	
	}

};

