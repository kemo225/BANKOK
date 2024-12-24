#pragma once
#include <iostream>
#include <fstream>
#include "ClsClient.h"
#include "ClsScreen.h"
	
using namespace std;

class ClsLoginTra :protected::ClsScreen
{
private:
	static void _printlineinTransferlog(ClsClient::_stTranferScreen st)
	{
		cout << setw(8) << "" << "| " << setw(18) << left << st._Date << "| " << setw(13) << left << st._AccountNumberfrom << "| " << setw(13) << left << st._AccountNumberto << setw(13) << left << st._Amount << "| " << setw(13) << left << st._Balancefrom << "| " << setw(13) << left << st._Balanceto << "| " << setw(13) << left << st._Username << endl;
	}
public:
	static void ShowTransferLogScreen()
	{
		vector<ClsClient::_stTranferScreen>Transer_date = ClsClient::_LoadClientsDataFromFileTranferlog();

		string tittle = "\tTransfer Screen", Subtittle = "(" + to_string(Transer_date.size()) + ") Recored(S) ";
		_DrawScreenHeader(tittle, Subtittle);

		cout << setw(8) << "" << "=============================================================================================================\n\n";
		cout << setw(8) << "" << setw(20) << left << "| Date " << setw(15) << left << "| A.From " << setw(15) << left << "| A.To " << setw(15) << left << "| Amount " << setw(15) << left << "| B.From " << setw(15) << left << "| B.To " << setw(15) << left << "| UserName " << endl << endl;
		cout << setw(8) << "" << "=============================================================================================================\n\n";

		for (ClsClient::_stTranferScreen st : Transer_date)
		{
			_printlineinTransferlog(st);
		}
		cout << endl;
		cout << setw(8) << "" << "==============================================================================================================\n";
	}
};




