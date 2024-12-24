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
#include "ClsScreen.h"
#include "ClsMainmenu.h"
#include "ClsDepositeScreen.h"
#include "ClsWithdrawScreen.h"
#include "ClsBalancelistScreen.h"
#include "clsUser.h"
#include "Global.h"
class ClsTransferScreen:protected::ClsScreen
{
private:
	static void printClint(ClsClient client)
	{
		cout << "Client Card : \n\n";
		cout << "___________________________________________\n\n";
		cout << "Full Name : " << client.fullName() << endl;
		cout << "Acc. Num  : " << client.AccountNumber << endl;
		cout << "Balance   : " << client.AccountBalance ; 
		cout << "\n___________________________________________\n\n";

	}
	static ClsClient _Getclient()
	{
		bool LoginFaild = false;
		string AccountNumber;
		ClsClient Client = ClsClient::Find("");
		do {
			if (LoginFaild == true)
			{
				cout << setw(8) << left << "" << "!!Error,Account Number IsNot Found!!\n";
			}
			cout << "Please Enter Account Number That Transfer from :  ";
			AccountNumber = clsInputValidate::ReedString();

			Client = ClsClient::Find(AccountNumber);

			LoginFaild = Client.IsClientexist(AccountNumber);

		} while (!LoginFaild);
		return Client;
	}
public:
	static void ShowTransferScreen()
	{
		string tittle = "\t Transfer Screen";
		_DrawScreenHeader(tittle);
			
		ClsClient ClientFrom = _Getclient();
		printClint(ClientFrom);

		cout << endl;

		ClsClient Clientto = _Getclient();
		printClint(Clientto);

		char Answer = clsInputValidate::ReedAnswerYorN("Are You Sure you want do this Transaction ? Y/N ? ");
		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "Enter Transfer Amount : ";
			int Amount = clsInputValidate::ReadIntNumber();
			
			if (ClientFrom.Transfer(Amount, Clientto,CurrentUser.UserName))
			{
				cout << "Transfer Done Successfuly\n\n";
				printClint(ClientFrom);
				printClint(Clientto);
			}
			else
			{
				cout << "This Process was Canceled \n";
			}
		}
		


	}
};

