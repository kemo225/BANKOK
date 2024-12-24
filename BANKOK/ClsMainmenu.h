#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "ClsClient.h"
#include "ClsDate.h"
#include "ClsInputValid.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsScreen.h"
#include "ClsShowclientlis.h"
#include "ClsDeleteclientscreen.h"
#include"ClsAddnewclientscreen.h"
#include "ClsUpdateClientScreen.h"
#include "ClsFindClientScreen.h"
#include"ClsTransactionscreen.h"
#include"ClsManageuserScreen.h"
#include"ClsLoginRegisterScreen.h"
#include "ClsCurrencyMainScreen.h"


using namespace std;
class ClsMainmenu :protected::ClsScreen
{

private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eloginRegister = 8,enCurrencyExchange=9,eExit=10
    };

    static int _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";

        int choice = clsInputValidate::ReadIntNumberBetween(1, 10);

        return choice;

    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //cout << "\nClient List Screen Will be here...\n";
        ClsShowclientlis::ShowClientList();

    }

    static void _ShowAddNewClientsScreen()
    {
        ClsAddnewclientscreen::ShowAddnewClientscreen();
    }

    static void _ShowDeleteClientScreen()
    {
        // cout << "\nDelete Client Screen Will be here...\n";
        ClsDeleteclientscreen::ShowDeleteclientscreen();
    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";
        ClsUpdateClientScreen::ShowUpdateClientscreen();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        ClsFindClientScreen::Showfindclientscreen();
    }

    static void _ShowTransactionsMenue()
    {
        ClsTransactionscreen::ShowTransactionscreen();
    }

    static void _ShowManageUsersMenue()
    {
        ClsManageuserScreen::ShowManageuserScreen();
    }

    static void _ShowLoginRegisterScreen()
    {
        ClsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyExcahange()
    {
        ClsCurrencyMainScreen::ShowCurrencyMainScreen();
    }

    static void _ShowEndScreen()
    {
        CurrentUser = clsUser::Find("", "");

    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

      case enMainMenueOptions::eloginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
      case enMainMenueOptions::enCurrencyExchange:
          system("cls");
          _ShowCurrencyExcahange();
          _GoBackToMainMenue();
          break;
      case enMainMenueOptions::eExit:
            system("cls");
            _ShowEndScreen();
            break;

        }

    }

public:


    static void ShowMainMenue()
    {
       system("cls");
       _DrawScreenHeader("\tMain Screen");
        
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10]Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
     
      
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};