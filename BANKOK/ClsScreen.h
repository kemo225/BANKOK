#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "ClsDate.h"
#include "ClsInputValid.h"
#include "ClsString.h"
#include "ClsUtility.h"
#include "ClsPerson.h"
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;

class ClsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate : " << clsDate::DateToString(clsDate()) << endl<<endl;

    }
    static bool AccessPageRight(clsUser::_enpermission permission)
    {
        if (CurrentUser.IscanAccess(permission))
        {
            return true;
        }
        else
        {
            _DrawScreenHeader("\t Access Denied Screen");
            cout << setw(8) << "" << "Error,You Cannot Access This Page\n";
            return false;
        }
    }

};


