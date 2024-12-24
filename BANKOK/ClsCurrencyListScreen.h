#pragma once
#include <iostream>
#include"ClsScreen.h"
#include "ClsCurrency.h"
using namespace std;
class ClsCurrencyListScreen:protected::ClsScreen
{
private:
	static void _printlineinListScreen(ClsCurrency C)
	{
		cout << setw(8) << "" << "| " << setw(33) << left << C.Country << "| " << setw(6) << left << C.Code << "| " << setw(28) << left <<C.Currency << "| " << setw(8) << left << C.Rate << endl;
	}
public:
	static void showCurrencylistScreen()
	{
		string tittle = "\t Currency List Screen";
		_DrawScreenHeader(tittle);
		vector< ClsCurrency>Currency_date = ClsCurrency::Getdatefromfile();


		cout << setw(8) << "" << "=============================================================================================================\n\n";
		cout << setw(8) << "" << setw(35) << left << "| Country " << setw(8) << left << "| Code " << setw(30) << left << "| Name"<< setw(10) << left << "Rate(1$)" << endl;
		cout << setw(8) << "" << "=============================================================================================================\n\n";

		
		for (ClsCurrency& C : Currency_date)
		{
			_printlineinListScreen(C);
	}

		cout << setw(8) << "" << "==============================================================================================================\n";

	}
};

