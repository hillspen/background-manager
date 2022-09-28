// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

#include "atlbase.h"
#include "atlstr.h"
#include "comutil.h"
using namespace std;

int changeBackground(const wchar_t* imagePath);

int main() {
    //const wchar_t* path = L"C:\\users\\talia\\onedrive\\bureau\\mountBourgeau.jpg";
    //must convert variable string to wide char*
    CStringW str = "C:\\users\\talia\\onedrive\\bureau\\Neuschwanstein-Castle.jpg";
    const wchar_t* path = str.GetString();

    std::cout << changeBackground(path);
    return 0;
}

int changeBackground(const wchar_t* imagePath) {
    //change background using windows api
    int success = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)imagePath, SPIF_UPDATEINIFILE);
    return success;
}
