// Registry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

#define PRODUCTION_SERVER    0
#define DEVELOPMENT_SERVER   1


bool CheckServerType()
{
    HKEY l_hKey;

    if(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Office\\Word\\AddIns\\WorX.AddInConnect", 0, KEY_READ, &l_hKey))
    {
        DWORD l_dwType, l_dwSize;
        DWORD l_ActivationEnvironment;

        if( ERROR_SUCCESS == RegQueryValueEx(l_hKey, L"ActivationEnvironment", 0 , (LPDWORD)&l_dwType, (LPBYTE)&l_ActivationEnvironment, &l_dwSize))
        {
            if(PRODUCTION_SERVER == l_ActivationEnvironment)
            {
                return PRODUCTION_SERVER;
            }
        }
        RegCloseKey(l_hKey);
    }
    else if(ERROR_SUCCESS == RegOpenKeyEx(HKEY_LOCAL_MACHINE, L"SOFTWARE\\WOW6432Node\\Microsoft\\Office\\Word\\AddIns\\WorX.AddInConnect", 0, KEY_READ, &l_hKey))
    {
        DWORD l_dwType, l_dwSize;
        DWORD l_ActivationEnvironment;

        if( ERROR_SUCCESS == RegQueryValueEx(l_hKey, L"ActivationEnvironment", 0 , (LPDWORD)&l_dwType, (LPBYTE)&l_ActivationEnvironment, &l_dwSize))
        {
            if(PRODUCTION_SERVER == l_ActivationEnvironment)
            {
                return PRODUCTION_SERVER;
            }
        }
        RegCloseKey(l_hKey);
    }
    else
    {
        std::cout<<"fffhfh"<<std::endl;
    }

    return DEVELOPMENT_SERVER;
}
int _tmain(int argc, _TCHAR* argv[])
{
    int  l_bServerType = CheckServerType();
    std::cout<<l_bServerType <<std::endl;
	return 0;
}

