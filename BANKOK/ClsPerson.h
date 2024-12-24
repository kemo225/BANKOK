#pragma once
// to m4 kul mra compiler y3ml save l class da am 7d yndh
#include <iostream>

using namespace std;

class Clsperson
{
private:
	string _FirstName = "", _LastName = "", _Email = "", _phone = "";


public:

	Clsperson(string FirstName, string LastName, string Email, string phone)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_phone = phone;
	}
	// construactor one ely implement 3 7sb prameter bt3 Object.

	void SetFirstName(string firstname)
	{
		_FirstName = firstname;
	}
	string GetFirstname()
	{
		return _FirstName;
	}
	_declspec(property(get = GetFirstname, put = SetFirstName))string FirstName;

	void Setlastname(string lastname)
	{
		_LastName = lastname;
	}
	string Getlastname()
	{
		return _LastName;
	}
	_declspec(property(get = Getlastname, put = Setlastname))string LastName;

	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}
	_declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhone(string phone)
	{
		_phone = phone;
	}
	string GetPhone()
	{
		return _phone;
	}
	_declspec(property(get = GetPhone, put = SetPhone))string Phone;


	string fullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SendEmail(string subject, string messeage)
	{
		cout << "The following messeage to Email : " << Email << endl;
		cout << "Subject : " << subject << endl;
		cout << messeage << endl;
	}
	void SendSMS(string SMS)
	{
		cout << "The following messeage to Phone : " << Phone << endl;
		cout << SMS << endl;
	}

	void print()
	{
		cout << "--------------------------------------------------------\n\n";
		cout << "First Name  : " << FirstName << endl;
		cout << "Last Name   : " << LastName << endl;
		cout << "Full Name   : " << fullName() << endl;
		cout << "Phone       : " << Phone << endl << endl;
		cout << "--------------------------------------------------------\n";
	}
};



