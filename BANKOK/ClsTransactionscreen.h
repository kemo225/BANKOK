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
#include "ClsShowclientlis.h"
#include "ClsScreen.h"
#include "ClsMainmenu.h"
#include "ClsDepositeScreen.h"
#include "ClsWithdrawScreen.h"
#include "ClsBalancelistScreen.h"
#include "ClsTransferScreen.h"
#include "clsUser.h"
#include "ClsLoginTra.h"
using namespace std;
class ClsTransactionscreen :protected::ClsScreen
{
private:
    enum _enTransaction { enWithdarw = 2, enDeposite = 1, entotalbalance = 3,enTransfer=4,  enTransferLog = 5,enMainMenu =6  };

    static int _ReedChoice()
    {
        cout << setw(37) << left << "" << "Choose What Do You Want to do ? [1 to 6] ?  ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
        return choice;
    }

    static void _ShowWithdrawScreen()
    {
        ClsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTransferScreen()
    {
        ClsTransferScreen::ShowTransferScreen();
    }
    static void _ShowDepositeScreen()
    {
        ClsDepositeScreen::ShowDepositeScreen();
    }
    static void _ShowTransferLog()
    {
        ClsLoginTra::ShowTransferLogScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        ClsBalancelistScreen::ShowBalancelist();
    }
    static void _BacktotransactionScreen()

    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Screen...\n";

        system("pause>0");
        ShowTransactionscreen();
    }

    static void _BacktoMainmenuScreen()
    {
    //    ClsMainmenu::ShowMainMenue();
    }

    static void _performchoiceinTransactionscreen(_enTransaction choice)
    {
        switch (choice)
        {
        case ClsTransactionscreen::enDeposite:
        {
            system("Cls");
            _ShowDepositeScreen();
            _BacktotransactionScreen();
            break;
        }
        case ClsTransactionscreen::enWithdarw:
        {
            system("Cls");
            _ShowWithdrawScreen();
            _BacktotransactionScreen();
            break;
        }
        case ClsTransactionscreen::entotalbalance:
        {
            system("Cls");
            _ShowTotalBalanceScreen();
            _BacktotransactionScreen();
            break;
        }
        case ClsTransactionscreen::enTransfer:
        {
            system("Cls");
            _ShowTransferScreen();
            _BacktotransactionScreen();
            break;
        }
        case ClsTransactionscreen::enTransferLog:
        {
            system("Cls");
            _ShowTransferLog();
            _BacktotransactionScreen();
            break;
        }
        case ClsTransactionscreen::enMainMenu:
        {
            break;
        }
        }
    }

public:
    static void ShowTransactionscreen()
    {
        if (!AccessPageRight(clsUser::_enpermission::entransaction))
        {
            return;
        }
        system("Cls");
        _DrawScreenHeader("\t  Transaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransaction Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _performchoiceinTransactionscreen((_enTransaction)_ReedChoice());

        
      
    }

};

