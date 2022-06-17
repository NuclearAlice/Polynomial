/******************************************************
** File            :   main.cpp
** Date            :   2022/6/14
** This File contains main function
******************************************************/

#include <iostream>
#include "Temp.h"
#include "Polynomial.h"
#include "functions.h"

using namespace std;

int main()
{

    Polynomial myPolynomial;
    system("cls");
    showFileMenu();
    chooseFromFileMenu(myPolynomial);
    return 0;
}