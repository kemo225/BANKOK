#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsCurrency.h"
using namespace std;

class ClsUpdateRateScreen:protected::ClsScreen
{
private:

	static void _PrintCurrency(ClsCurrency C)
	{
		cout << "Currency Card : \n";
		cout << "________________________________________\n\n";
		cout << "Name     : " << C.Currency << endl;
		cout << "Code     : " << C.Code << endl;
		cout << "Country  : " << C.Country << endl;
		cout << "Rate(1$) : " << C.Rate << endl;
		cout << "________________________________________\n";

	}
public:

	static void showUpadteRateScreen()
	{
		string tittle = "\tUpdate Rate Screen";
		_DrawScreenHeader(tittle);

		cout << "Enter CurrencyCode : ";
		string CurrencyCode = clsInputValidate::ReedString();
		cout << endl;

		ClsCurrency Currency = ClsCurrency::FindByCode(CurrencyCode);

		if (!Currency.Isempty())
		{
			_PrintCurrency(Currency);
			char answer = clsInputValidate::ReedAnswerYorN("\nAre you Sure do This Perform ? Y/N ? ");
			if (answer == 'y' || answer == 'Y')
			{
				cout << "\n\nUpdating Rate : \n";
				cout << "________________________________________\n\n";
				cout << "Update Rate  :  ";
				float Newrate = clsInputValidate::ReadFltNumber();
				Currency.UpdateRate(Newrate);
				cout << "________________________________________\n\n";
				cout << "Currency Rate Update Successfuly  :) \n\n";
				_PrintCurrency(Currency);
			}
		}
		else
		{
			cout << "\nCurrency IsNot Exist :( \n";
		}

	}
};

