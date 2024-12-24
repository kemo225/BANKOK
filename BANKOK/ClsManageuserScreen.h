#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "ClsDate.h"
#include "ClsUtility.h"
#include "ClsPerson.h"
#include "ClsInputValid.h"
#include "ClsScreen.h"
#include "ClsMainmenu.h"
#include "ClsUserlistScreen.h"
#include "ClsAddnewUserScreen.h"
#include "ClsDeleteuserScreen.h"
#include "ClsUpdateUserScreen.h"
#include "ClsFindUserScreen.h"
#include "clsUser.h"
using namespace std;
class ClsManageuserScreen:protected::ClsScreen
{
private: 
    enum _enmangeuseroptionts {
        enuserlist=1,enAddnewuser=2,endeleteuaer=3,enupdateuser=4,enfinduser=5,enmainmenueuser=6
    };
    static void _ShowuserlistScreen()
    {
        ClsUserlistScreen::ShowUserlistScreen();
    }
    static void _ShowUpdateuserScreen()
    {
        ClsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowAddnewUserScreen()
    {
        ClsAddnewUserScreen::ShowAddnewuserScreen();
    }
    static void _ShowDeleteuserScreen()
    {
        ClsDeleteuserScreen::ShowDeleteUserScreen();

    }
    static void _ShowFinduserScreen()
    {
        ClsFindUserScreen::ShowFinduserScreen();

    }

    static void _ShowMainmenuScreen()
    {
        //ll
    }

    static void _bacttomageuserscreen()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to manage user...\n";
        cin.ignore();
        system("pause>0");
        system("Cls");
        ShowManageuserScreen();
    }

    static void _performmanageuseroption(_enmangeuseroptionts choice)
    {
        switch (choice)
        {
        case ClsManageuserScreen::enuserlist:
        {
            system("Cls");
            _ShowuserlistScreen();
            _bacttomageuserscreen();
            break;
        }
        case ClsManageuserScreen::enAddnewuser:
        {
            system("Cls");
            _ShowAddnewUserScreen();
            _bacttomageuserscreen();
            break;
        }
        case ClsManageuserScreen::endeleteuaer:
        {
            system("Cls");
            _ShowDeleteuserScreen();
            _bacttomageuserscreen();
            break;
        }
        case ClsManageuserScreen::enupdateuser:
        {
            system("Cls");
          _ShowUpdateuserScreen();
            _bacttomageuserscreen();
            break;
        }
        case ClsManageuserScreen::enfinduser:
        {
            system("Cls");
            _ShowFinduserScreen();
            _bacttomageuserscreen();
            break;
        }
        case ClsManageuserScreen::enmainmenueuser:
        {
            break;
        }
      
        }
        
    }

    static int _ReedchoiceNumber()
    {
        cout << setw(37) << left << "" << "Please Choice between 1 to 6 ?  ";
        int choice = clsInputValidate::ReadIntNumberBetween(1, 6);
        return choice;
    }

public:
	static void ShowManageuserScreen()
	{
        if (!AccessPageRight(clsUser::_enpermission::enManageuser))
        {
            return;
        }
		string tittle = "\tManage User Screen";
		_DrawScreenHeader(tittle);
      
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\t Manage user Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] User List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Delete User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User.\n";
            cout << setw(37) << left << "" << "\t[5] Find user.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            _performmanageuseroption((_enmangeuseroptionts)_ReedchoiceNumber());
      
	}
};

