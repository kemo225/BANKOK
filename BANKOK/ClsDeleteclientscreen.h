#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ClsClient.h"
#include "ClsInputValid.h"
#include "ClsScreen.h"
#include "clsUser.h"

using namespace std;
class ClsDeleteclientscreen :protected::ClsScreen
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

public:
	static void ShowDeleteclientscreen()

	{
		if (!AccessPageRight(clsUser::_enpermission::enDeleteclient))
		{
			return;
		}
		string tittle = "\tDelete Client Screen";
		_DrawScreenHeader(tittle);
	
			cout << "Please Enter Account Number ?  ";
			string AccountNumber = clsInputValidate::ReedString();
			cout << endl;

			while (!ClsClient::IsClientexist(AccountNumber))
			{
				cout << "Error , Account Number is Not Found, Enter another : ";
				AccountNumber = clsInputValidate::ReedString();
			}

			ClsClient clientdelete = ClsClient::Find(AccountNumber);
			clientdelete.print();

			char answer = clsInputValidate::ReedAnswerYorN("Are You Sure to Delete This Client? Y/N ?  ");

			if (answer == 'y' || answer == 'Y')
			{
				if (clientdelete._Delete())
				{
					cout << "Successful,Client is deleted.\n";
				}
				else {
					cout << "Error Failure,Client isNot deleted.\n";
				}
			}
		}
		

	
};

