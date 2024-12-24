#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsCurrency.h"
class ClsCalaculatorCurrencyScreen:protected::ClsScreen
{
private:
	static void _PrintCurrencyfrom(ClsCurrency C)
	{

		cout << "Convert Currency From : \n";
		cout << "________________________________________\n\n";
		cout << "Name     : " << C.Currency << endl;
		cout << "Code     : " << C.Code << endl;
		cout << "Country  : " << C.Country << endl;
		cout << "Rate(1$) : " << C.Rate << endl;
		cout << "________________________________________\n\n";

	}
	static void _PrintCurrencyto(ClsCurrency C)
	{
		cout << "To : \n";
		cout << "________________________________________\n\n";
		cout << "Name     : " << C.Currency << endl;
		cout << "Code     : " << C.Code << endl;
		cout << "Country  : " << C.Country << endl;
		cout << "Rate(1$) : " << C.Rate << endl;
		cout << "________________________________________\n\n";

	}
	static ClsCurrency _GetCurrency(string messeage)
	{
		cout << messeage << endl;
		string Code = clsInputValidate::ReedString();
		ClsCurrency Currency = ClsCurrency::FindByCode(Code);
		while (!ClsCurrency::IsCurrencyexistbycode(Code))
		{
			cout << "Error CurrencyCode IsNot Found,Enter another : ";
			cin >> Code;
		}
		return Currency;
	}
	static void _printResult(float Amount, ClsCurrency Currency1, ClsCurrency Currency2)
	{

		if (Currency2.Rate == 0)
		{
			_PrintCurrencyfrom(Currency1);
			cout << "\nTo " << Currency2.Code << " : \n";
			cout << Amount << " " << Currency1.Code << " = " << Amount / Currency1.Rate << Currency2.Code << endl;
			return;
		}

		_PrintCurrencyfrom(Currency1);

		cout << Amount << " " << Currency1.Code << " = " << Amount / Currency1.Rate << " USD\n\n";
		cout << "Converting From USD To \n";

		_PrintCurrencyto(Currency2);


		cout << Amount << " " << Currency1.Code << " = " << (Amount / Currency1.Rate) * Currency2.Rate << " " << Currency2.Code << endl << endl;
		
	}
public:

	static void showCalaculatorCurrencyScreen()
	{
		bool repition;
		
		do{
		system("Cls");
		repition = false;

		string tittle = "   Calaculator Currency Screen";
		_DrawScreenHeader(tittle);

		ClsCurrency Currency1 = _GetCurrency("Please Enter CurrencyCode1 : ");
		ClsCurrency Currency2 = _GetCurrency("Please Enter CurrencyCode2 : ");

		cout << "Enter Amount to Exchange : ";
		int Amount = clsInputValidate::ReadIntNumber();
		cout << endl;

		_printResult(Amount, Currency1, Currency2);

		char answer = clsInputValidate::ReedAnswerYorN("Are you want perforn another calculation ? Y/N ? ");
		if (answer == 'y' || answer == 'Y')
		repition = true;

		} while (repition);
	}

	
};

