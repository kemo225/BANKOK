#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "ClsClient.h"
#include "ClsDate.h"
#include "ClsInputValid.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsPerson.h"
#include "ClsScreen.h"
#include "clsUser.h"


using namespace std;

class ClsShowclientlis :protected::ClsScreen
{
private:
	static void _Printoneclient(ClsClient client)
	{
		cout << setw(8) << "" << "| " << setw(16) << left << client.AccountNumber << "| " << setw(13) << left << client.Phone << "| " << setw(18) << left << client.fullName() << "| " << setw(11) << left << client.Pincode << "| " << setw(25) << left << client.Email << "| " << setw(8) << left << client.AccountBalance << endl;
	}

public:
	static void ShowClientList()
	{
		if (!AccessPageRight(clsUser::_enpermission::enShowclientlist))
		{
			return;
		}
		vector<ClsClient>Client_date = ClsClient::GetClientlist();

		string tittle = "\tClient List Screen";
		string subtittle = "\t(" + to_string(Client_date.size()) + ") Client(s) ";
		_DrawScreenHeader(tittle, subtittle);

			cout << setw(8) << "" << "=============================================================================================================\n\n";
			cout << setw(8) << "" << setw(18) << left << "| Account Number " << setw(15) << left << "| Phone " << setw(20) << left << "| Client Name " << setw(13) << left << "| PinCode " << setw(27) << left << "| Email " << setw(10) << left << "| Balance " << endl << endl;
			cout << setw(8) << "" << "=============================================================================================================\n\n";

			for (ClsClient& c : Client_date)
			{
				_Printoneclient(c);
			}
			cout << endl;

			cout << setw(8) << "" << "==============================================================================================================\n";

		
	}

};

