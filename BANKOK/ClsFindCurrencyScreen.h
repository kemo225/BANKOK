#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsInputValid.h"
#include "ClsCurrency.h"
using namespace std;

class ClsFindCurrencyScreen:protected::ClsScreen
{
private :
	

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

	// 8LT TL2I 7AGA MTKRRA F CODEEEEE

	static void	_ShowResult(ClsCurrency C)
	{
		if (!C.Isempty())
		{
			cout << "\nCurrency Found :) \n\n";
			_PrintCurrency(C);
			return;
		}
		else
		{
			cout << "\nCurrency isNot Exist :( \n";
			return;
		}
	}

	public:

		static void showFindCurrencyScreen()
		{
			string tittle = "\t Find Currency Screen";
			_DrawScreenHeader(tittle);

			cout << "Find By : [1] Code , [2] Country ?  ";
			short choice = clsInputValidate::ReadIntNumberBetween(1, 2);
		
			ClsCurrency Currency = ClsCurrency::FindByCountry("");

			if (choice==1)
			{
				string Code;
				cout << "Enter CurrencyCode :  ";
				Code = clsInputValidate::ReedString();
				Currency = ClsCurrency::FindByCode(Code);
				_ShowResult(Currency);
			}
			else
			{
				string Country;
				cout << "Enter CurrencyCountry :  ";
				Country = clsInputValidate::ReedString();
				ClsCurrency Currency = ClsCurrency::FindByCountry(Country);
				_ShowResult(Currency);
			}

		}
		


};

