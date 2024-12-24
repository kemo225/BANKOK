#pragma once
#include <iostream>
#include "ClsScreen.h"
#include "ClsInputValid.h"
#include "ClsCurrencyListScreen.h"
#include "ClsFindCurrencyScreen.h"
#include "ClsUpdateRateScreen.h"
#include "ClsCalaculatorCurrencyScreen.h"
using namespace std;
class ClsCurrencyMainScreen:protected::ClsScreen
{
private: 
    
    enum _enCurrencyOption {
        enListcurrency=1,enFindCurrenvy=2,enUpdaterate=3,enCurrenctcalculate=4,enMainmenu=5
    };

    static int _reedchoice()
    {
        cout << setw(37) << left << "" << "Please enter what do you want to do ? [1 to 5] ?  ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 5);
        return choice;

    }
    static void _ShowlistCurrency()
    {
        ClsCurrencyListScreen::showCurrencylistScreen();
    }
    static void _ShowfindCurrency()
    {
        ClsFindCurrencyScreen::showFindCurrencyScreen();
    }
    static void _ShowUpdateRate()
    {
        ClsUpdateRateScreen::showUpadteRateScreen();
    }
    static void _ShowCurrencyCalculator()
    {
        ClsCalaculatorCurrencyScreen::showCalaculatorCurrencyScreen();
    }
    static void _BacttoCurrencyMenu()
    {
            cout << setw(8) <<left<<""<< "\n\nPress any key to back Currency Menue ...\n\n";
            system("pause>0");
            ShowCurrencyMainScreen();
    }

    static void _performOption(_enCurrencyOption choice)
        {
        switch (choice)
        {
        case ClsCurrencyMainScreen::enListcurrency:
        {
            system("Cls");
            _ShowlistCurrency();
            _BacttoCurrencyMenu();
            break;
        }
        case ClsCurrencyMainScreen::enFindCurrenvy:
        {
            system("Cls");
            _ShowfindCurrency();
            _BacttoCurrencyMenu();
            break;
        }
        case ClsCurrencyMainScreen::enUpdaterate:
        {
            system("Cls");
            _ShowUpdateRate();
            _BacttoCurrencyMenu();
            break;
        }
        case ClsCurrencyMainScreen::enCurrenctcalculate:
          {
            system("Cls");
            _ShowCurrencyCalculator();
            _BacttoCurrencyMenu();
                break;
           }
        case ClsCurrencyMainScreen::enMainmenu:
            {
                break;
            }
       
        }
        }
public:
	static void ShowCurrencyMainScreen()
	{
        system("Cls");

		string tittle = "\tCurrency Exchange Main Screen";
		_DrawScreenHeader(tittle);

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performOption((_enCurrencyOption)_reedchoice());
  
	}
};

