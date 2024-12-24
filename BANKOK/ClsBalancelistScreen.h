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

class ClsBalancelistScreen :protected::ClsScreen
{
private:
	static void _Printoneclient(ClsClient client)
	{
		cout << setw(18) << "" <<"| " << setw(16) << left << client.AccountNumber << "| " << setw(18) << left << client.FirstName << "| " << setw(8) << left << client.AccountBalance << endl;
	}

public:
	static void ShowBalancelist()
	{
		
		vector<ClsClient>Client_date = ClsClient::GetClientlist();

		string tittle = "\tBalance List Screen";
		string subtittle = "\t(" + to_string(Client_date.size()) + ") Client(s) ";
		_DrawScreenHeader(tittle, subtittle);


		cout << setw(8) << "" << "=============================================================================================================\n\n";
		cout << setw(18) << "" << setw(18) << left << "| Account Number "  << setw(20) << left << "| Client Name " <<  setw(10) << left << "| Balance " << endl << endl;
		cout << setw(8) << "" << "=============================================================================================================\n\n";

		for (ClsClient& c : Client_date)
		{
			_Printoneclient(c);
		}
		cout << endl;

		cout << setw(8) << "" << "==============================================================================================================\n";
		cout << "\t\t\t\tTotal Balance =	" << ClsClient::Gettotalbalance(Client_date)<<endl;
		cout << "\t\t\t(" << clsUtil::NumberToText(ClsClient::Gettotalbalance(Client_date)) << ")\n\n";


	}

};


