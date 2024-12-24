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
#include "ClsLoginScreen.h"

using namespace std;


int main()
{
	while (1) {

		if (!ClsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
}

