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

using namespace std;
class ClsWithdrawScreen :protected::ClsScreen
{
private:
	static bool _IsAvalibleWithdraw(int Deposite_Value, ClsClient CurrentClient)
	{
		if (Deposite_Value % 5 == 0 )
			return 1;
		else
			return 0;

	}

	static void _printClient(ClsClient C)
	{
		cout << "\nClient Details : \n\n";
		cout << "--------------------------------------------------------\n\n";
		cout << "First Name          : " << C.FirstName << endl;
		cout << "Last Name           : " << C.LastName << endl;
		cout << "Full Name           : " << C.fullName() << endl;
		cout << "Email               : " << C.Email << endl;
		cout << "AccountNumber       : " << C.AccountNumber << endl;
		cout << "PinCode             : " << C.Pincode << endl;
		cout << "AccountBalance      : " << C.AccountBalance << endl;
		cout << "--------------------------------------------------------\n\n";
	}

public:
	static void ShowWithdrawScreen()
	{
		string Tittle = "\tWithdraw Screen";
		ClsScreen::_DrawScreenHeader(Tittle);

		cout << "Please Enter Account Number ?  ";
		string AccountNumber = clsInputValidate::ReedString();
		cout << endl << endl;

		while (!ClsClient::IsClientexist(AccountNumber))
		{
			cout << "Error , Account Number is Not Found, Enter another : ";
			AccountNumber = clsInputValidate::ReedString();
		}

		ClsClient CurrentClient = ClsClient::Find(AccountNumber);

		_printClient(CurrentClient);

		cout << "Enter The Withdraw Value ?  ";
		int Withdraw_value = clsInputValidate::ReadIntNumber();
		cout << endl;

		while (!_IsAvalibleWithdraw(Withdraw_value, CurrentClient))
		{
			cout << "!!ERROR,Not Avaliable Do This Transaction!! : Enter Withdraw Value : ";
			cin >> Withdraw_value;
		}

		char answer = clsInputValidate::ReedAnswerYorN("Are You Sure you want Desposite ? Y/N ? ");
		cout << endl;

		if (answer == 'y' || answer == 'Y')
		{
			CurrentClient.Withdraw(Withdraw_value);
			cout << "\nSuccessfuly Processes\n";
			cout << "New Balance is : " << CurrentClient.AccountBalance << endl;
		}
		else {
			cout << "\n the processed Was Cancelled \n";
		}




	}

};

