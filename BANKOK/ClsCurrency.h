#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "ClsString.h"
#include "ClsUtility.h"
using namespace std;
class ClsCurrency
{
private:
	string _Country, _Code, _Currency;
	float _Rate;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddedMode = 2 };
	enMode _Mode;

	static ClsCurrency _ConverlinetoObject(string line,string sperator= "#//#")
	{
		vector<string>Vvector = clsString::Split(line,sperator);

		return ClsCurrency(enMode::UpdateMode, Vvector[0], Vvector[1], Vvector[2],stof(Vvector[3]));
	}
	static string _ConverObjecttoline(ClsCurrency objCurrency, string sperator = "#//#")
	{
		string line = "";
		line += objCurrency.Country+sperator;
		line += objCurrency.Code + sperator;
		line += objCurrency.Currency + sperator;
		line += to_string(objCurrency.Rate) ;
		return line;
		
	}
	static vector< ClsCurrency>_LoaddatefromFile()
	{
		vector< ClsCurrency>Currency_date;
		fstream file;
		file.open("CurrenctFile.txt", ios::in);
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				Currency_date.push_back(_ConverlinetoObject(line));
			}
			 
		}
		return Currency_date;

	}
	void _SavedatetoFile(vector< ClsCurrency>Currency_date)
	{
		fstream file;
		file.open("CurrenctFile.txt",ios::out);
		if (file.is_open())
		{
			for (ClsCurrency c : Currency_date)
			{
				file << _ConverObjecttoline(c) << endl;
			}
			file.close();
		}

	}
	void _Update()
	{
		vector< ClsCurrency>Currency_date = _LoaddatefromFile();
		for (ClsCurrency& C : Currency_date)
		{
			if (C.Country == this->Country)
			{
				C = *this;
			}
		}
		_SavedatetoFile(Currency_date);
	}

public:
	ClsCurrency(enMode mode,string Country, string Code, string Currency, float Rate)
	{
		_Country = Country;
		_Code = Code;
		_Currency = Currency;
		_Rate = Rate;
		_Mode = mode;
	}
	
	void SetCountry(string country)
	{
		_Country = country;
	}
	string GetCountry()
	{
		return _Country;
	}
	_declspec(property(put = SetCountry, get = GetCountry))string Country;

	void SetCode(string Code)
	{
		_Code = Code;
	}
	string GetCode()
	{
		return _Code;
	}
	_declspec(property(put = SetCode, get = GetCode))string Code;

	void SetCurrency(string Currency)
	{
		_Currency = Currency;
	}
	string GetCurrency()
	{
		return _Currency;
	}
	_declspec(property(put = SetCurrency, get = GetCurrency))string Currency;

	void SetRate(float Rate)
	{
		_Rate = Rate;
	}
	float GetRate()
	{
		return _Rate;
	}
	_declspec(property(put = SetRate, get = GetRate))float Rate;

	static ClsCurrency Getemptyobject()
	{
		return ClsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static vector< ClsCurrency>Getdatefromfile()
	{
		return _LoaddatefromFile();
	}
	static ClsCurrency FindByCountry(string Country)
	{
		vector< ClsCurrency>Currency_date = Getdatefromfile();
		for (ClsCurrency& c : Currency_date)
		{
			
			if (clsUtil::ConvertWordtoLowerCase(c.Country) == clsUtil::ConvertWordtoLowerCase(Country))
			{
				
				return c;
			}
		}
		return Getemptyobject();
	}
	static ClsCurrency FindByCode(string Code)
	{
		vector< ClsCurrency>Currency_date = Getdatefromfile();
		for (ClsCurrency& c : Currency_date)
		{
			if (clsUtil::ConvertWordtoLowerCase(c.Code) == clsUtil::ConvertWordtoLowerCase(Code))
			{
				return c;
			}
		}
		return Getemptyobject();
	}

	bool Isempty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	static bool IsCurrencyexist(string Country)
	{
		ClsCurrency Currency = FindByCountry(Country);
		return (!Currency.Isempty());
	}
	static bool IsCurrencyexistbycode(string code)
	{
		ClsCurrency Currency = FindByCode(code);
		return (!Currency.Isempty());
	}

	void UpdateRate(float Newrate)
	{
		_Rate = Newrate;
		_Update();
	}

	float ConvetToUSD(float amount)
	{
		return amount / Rate;
	}
	
};

