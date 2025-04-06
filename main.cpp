#include <iostream>
#include "bank-system/bank-system-ui-main-menu/clsMainScreen.h"
#include "bank-system/bank-system-login-and-permissions/clsLoginScreen.h"
using namespace std;

int main()
{
    while (clsLoginScreen::showLoginScreen());
    return 0;
}