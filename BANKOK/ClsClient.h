#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "ClsDate.h"
#include "clsUser.h"
#include "ClsUtility.h"
#include "ClsPerson.h"
#include "ClsInputValid.h"
#include "clsString.h"
#include "Global.h"

using namespace std;


class ClsClient :public::Clsperson
{
private:

	string _PinCode, _AccountNumber;
	float _AccountBalance; bool _Markthatdelted = false;


	enum enMode { EmptyMode = 0, UpdateMode = 1, AddedMode = 2 };
	enMode _Mode;
	

	static ClsClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return ClsClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
		// instead of a3ml obj w amlah 
	}

	static ClsClient _GetEmptyClientObject()
	{
		return ClsClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConverClientObjectToLine(ClsClient Client, string Seperator = "#//#")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.Pincode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}


	static  vector <ClsClient>_LoadClientsDataFromFile(string FileName = "Client.txt")
	{

		vector <ClsClient>Client_date;

		fstream MyFile;
		MyFile.open("Client.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				ClsClient Client = _ConvertLinetoClientObject(Line);

				Client_date.push_back(Client);
			}

			MyFile.close();

		}

		return Client_date;

	}



	void _Update()
	{
		vector <ClsClient>Client_date = _LoadClientsDataFromFile();

		for (ClsClient& c : Client_date)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c = *this;
				break;
			}
		}

		_SavedatetoFile(Client_date);

		// lw na 3mlt method w kant static lazm lazm lw hcall any thing gwa class ykon static or through class
	}

	static void _SavedatetoFile(vector <ClsClient>Client_date)
	{
		fstream file;
		file.open("Client.txt", ios::out);
		if (file.is_open())
		{
			for (ClsClient& c : Client_date)
			{
				file << _ConverClientObjectToLine(c) << endl;
			}
		}
	}

	static void _SavedatetoFileAfterchanged(vector <ClsClient>Client_date)
	{
		fstream file;
		file.open("Client.txt", ios::out);
		if (file.is_open())
		{
			for (ClsClient& c : Client_date)
			{
				if (c.Markthatdelted == false)
				{
					file << _ConverClientObjectToLine(c) << endl;
				}
			}
			file.close();
		}
	}

	static void _ADDLinetoFile(string line)
	{
		fstream file;
		file.open("Client.txt", ios::out | ios::app); // IMPORTANT
		if (file.is_open())
		{
			file << line << endl;
			file.close();
		}
	}

	void _AddNewClient()
	{
		_ADDLinetoFile(_ConverClientObjectToLine(*this));
	}

	void _Printoneclient(ClsClient client)
	{
		cout << "| " << setw(16) << left << client.AccountNumber << "| " << setw(16) << left << client.Phone << "| " << setw(18) << left << client.fullName() << "| " << setw(11) << left << client.Pincode << "| " << setw(28) << left << client.Email << "| " << setw(8) << left << client.AccountBalance << endl;
	}

	double _Gettotalbalance()
	{
		vector<ClsClient>Client_date = _LoadClientsDataFromFile();
		double sum = 0;
		for (ClsClient& c : Client_date)
		{
			sum += c.AccountBalance;
		}
		return sum;
	}

    void _ADDLinetoFileTransferlog(string line)
	{
		fstream file;
		file.open("Transferlog.txt", ios::out | ios::app); // IMPORTANT
		if (file.is_open())
		{
			file << line << endl;
			file.close();
		}
	}
	



public:

	ClsClient(enMode mode, string Firstname, string Lastname, string Email, string Phone, string AccountNumber, string Pincode, float AccountBalance) :
		Clsperson(Firstname, Lastname, Email, Phone)
	{
		_PinCode = Pincode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_Mode = mode;
	}
	static struct _stTranferScreen {
		string _Date, _AccountNumberfrom, _AccountNumberto, _Username;
		int _Amount, _Balancefrom, _Balanceto;
	};
	static _stTranferScreen ConvertlineTransfertostruct(string line)
	{
		_stTranferScreen Transferstruct;
		vector<string>Vvector = clsString::Split(line, "#//#");
		Transferstruct._Date = Vvector[0];
		Transferstruct._AccountNumberfrom = Vvector[1];
		Transferstruct._AccountNumberto = Vvector[2];
		Transferstruct._Amount = stoi(Vvector[3]);
		Transferstruct._Balancefrom = stoi(Vvector[4]);
		Transferstruct._Balanceto = stoi(Vvector[5]);
		Transferstruct._Username = Vvector[6];
		return Transferstruct;
	}

	void SetPincode(string Pincode)
	{
		_PinCode = Pincode;
	}
	string GetPincode()
	{
		return _PinCode;
	}
	_declspec(property(get = GetPincode, put = SetPincode))string Pincode;

	void SetAccountNumber(string AccountNumber)
	{
		_AccountNumber = AccountNumber;
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	_declspec(property(get = GetAccountNumber, put = SetAccountNumber))string AccountNumber;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	_declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	void SetMarkthatdelted(bool Markthatdelted)
	{
		_Markthatdelted = Markthatdelted;
	}
	bool GetMarkthatdelted()
	{
		return _Markthatdelted;
	}
	_declspec(property(get = GetMarkthatdelted, put = SetMarkthatdelted))bool Markthatdelted;

	static ClsClient GetAddNewClient(string AccountNumber)
	{
		return ClsClient(enMode::AddedMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	void print()
	{
		cout << "\nClient Details : \n\n";
		cout << "--------------------------------------------------------\n\n";
		cout << "First Name          : " << FirstName << endl;
		cout << "Last Name           : " << LastName << endl;
		cout << "Full Name           : " << fullName() << endl;
		cout << "Email               : " << Email << endl;
		cout << "AccountNumber       : " << AccountNumber << endl;
		cout << "PinCode             : " << Pincode << endl;
		cout << "AccountBalance      : " << AccountBalance << endl;
		cout << "--------------------------------------------------------\n";
	}

	static ClsClient Find(string AccountNumber)
	{
		vector<ClsClient>Client_date = _LoadClientsDataFromFile();
		for (ClsClient& c : Client_date)
		{
			if (c.AccountNumber == AccountNumber)
			{
				return c;
			}
		}
		return _GetEmptyClientObject();
	}
	static ClsClient Find(string AccountNumber, string Pincode)
	{
		vector<ClsClient>Client_date = _LoadClientsDataFromFile();
		for (ClsClient& c : Client_date)
		{
			if (c.AccountNumber == AccountNumber && c.Pincode == Pincode)
			{
				return c;
			}
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientexist(string AccountNumber)
	{
		ClsClient client = ClsClient::Find(AccountNumber);
		return (!client.IsEmpty());
	}

	static enum ensaveresult { SVsuccess = 1, SVfailed = 0 };

	ensaveresult Save()
	{

		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return ensaveresult::SVfailed;
			break;
		}
		case enMode::UpdateMode:
		{
			_Update();
			return ensaveresult::SVsuccess;
			break;
		}
		case enMode::AddedMode:
		{
			if (IsClientexist(_AccountNumber))
			{
				_Mode = enMode::UpdateMode;
				return ensaveresult::SVfailed;
			}
			else
			{
				_AddNewClient();
				_Mode = enMode::UpdateMode;
				return ensaveresult::SVsuccess;
			}
		}
		}
	}

	bool Transfer(int Amount, ClsClient &ClientTo,string Username)
	{
		if (Amount > AccountBalance || Amount % 5 != 0)
		{
			return false;
		}
		Deposite(Amount);
		ClientTo.Withdraw(Amount);
		AddDateTransfertoFile(Amount, ClientTo,Username);
		return true;
	}

	void Reedclient(ClsClient& client)
	{
		cout << "Please enter First Name      : ";
		client.FirstName = clsInputValidate::ReedString();
		cout << "Please enter Last Name       : ";
		client.LastName = clsInputValidate::ReedString();
		cout << "Please enter Email           : ";
		client.Email = clsInputValidate::ReedString();
		cout << "Please enter PinCode         : ";
		client.Pincode = clsInputValidate::ReedString();
		cout << "Please enter Phone           : ";
		client.Phone = clsInputValidate::ReedString();
		cout << "Please enter Account Balance : ";
		client.AccountBalance = stoi(clsInputValidate::ReedString());
	}

	bool _Delete()
	{
		vector<ClsClient>Client_date = _LoadClientsDataFromFile();

		for (ClsClient& c : Client_date)
		{
			if (c.AccountNumber == AccountNumber)
			{
				c.Markthatdelted = true;
				break;
			}
		}

		_SavedatetoFileAfterchanged(Client_date);

		*this = _GetEmptyClientObject();

		return 1;
	}
	static  vector <_stTranferScreen>_LoadClientsDataFromFileTranferlog()
	{

		vector <_stTranferScreen>Transfer_date;

		fstream MyFile;
		MyFile.open("Transferlog.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				Transfer_date.push_back(ConvertlineTransfertostruct(Line));
			}

			MyFile.close();

		}

		return Transfer_date;

	}

	static vector<ClsClient> GetClientlist()
	{
		return	_LoadClientsDataFromFile();
	}

	static void SaveDateToFile(vector<ClsClient>client_date)
	{
		_SavedatetoFile(client_date);
	}

	void Deposite(int amount)
	{
		AccountBalance -= amount;
		Save();
	}
	void Withdraw(int amount)
	{
		AccountBalance += amount;
		Save();
	}
	static double Gettotalbalance(vector<ClsClient>Client_date)
	{
		double sum = 0;
		for (ClsClient& c : Client_date)
		{
			sum += c.AccountBalance;
		}
		return sum;
	}

	void AddDateTransfertoFile(int Amount, ClsClient clientto,string Username)
	{
		string line = clsDate::DateToString(clsDate()) + "#//#" + AccountNumber + "#//#" + clientto.AccountNumber + "#//#" + to_string(Amount) + "#//#" + to_string(AccountBalance) + "#//#" + to_string(clientto.AccountBalance) + "#//#" + Username;
		_ADDLinetoFileTransferlog(line);
	}
	

};






