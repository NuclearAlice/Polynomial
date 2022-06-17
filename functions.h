/******************************************************
** File            :   functions.cpp
** Date            :   2022/6/14
** This File contains all the function used in our project
******************************************************/

#include <iostream>
#include "Temp.h"
#include "Polynomial.h"
#include <windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <filesystem>
using namespace std;

/*This function shows the errors got for file stuff*/
void cacthFileFunction(int ex)
{
    cerr << "Looks like an error occurred!...\n";
    Sleep(1000);
    switch (ex)
    {
    case 1:
        cerr << "Exeption1:Could not find any save data!\n";
        break;
    case 2:
        cerr << "Exeption1:File corrupted!\n";
        break;
    default:
        break;
    }
}

/*This function shows the errors got for Polynomial*/
void cacthFunction(int ex)
{
    cerr << "Looks like an error occurred!...\n";
    Sleep(1000);
    switch (ex)
    {
    case 1:
        cerr << "Exeption1:Can not sum terms with different power!\n";
        break;
    case 2:
        cerr << "Exeption2:Can not minus terms with different power!\n";
        break;
    case 3:
        cerr << "Exeption3:Can not increase a term with non-zero power!\n";
        break;
    case 4:
        cerr << "Exeption4:Can not decrease a term with non-zero power!\n";
        break;
    case 5:
        cerr << "Exeption5:Entered character 'x' more than one time!\n";
        break;
    case 6:
        cerr << "Exeption6:Can not sum float and Term with non-zero power!\n";
        break;
    case 7:
        cerr << "Exeption7:Can not minus float and Term with non-zero power!\n";
        break;
    case 8:
        cerr << "Exeption8:Divide on zero is not allowed!\n";
        break;
    case 9:
        cerr << "Exeption9:Return types does not matche for *= operation!\n";
        break;
    case 10:
        cerr << "Exeption10:Entering '+' for the first Term is not allowed!\n";
        break;
    case 11:
        cerr << "Exeption11:There is a problem in the file!\n";
        break;
    case 12:
        cerr << "Exeption12:Polynomial can not start with '^'!\n";
        break;
    case 13:
        cerr << "Exeption13:Invalid input character for polynomial!\n";
        break;
    case 14:
        cerr << "Exeption14:Where there is '^' in polynomial then there should be 'x'!\n";
        break;
    case 15:
        cerr << "Exeption15:Do not enter more than one '+' or '-' next to each other!\n";
        break;
    case 16:
        cerr << "Exeption16:Polynomial can not end with '+' or '-'!\n";
        break;
    case 17:
        cerr << "Exeption17:Polynomial can not end with '^'!\n";
        break;
          case 18:
        cerr << "Exeption18:After '^' there should be a number!\n";
        break;
    default:
        break;
    }
}

/*Shows file menu*/
void showFileMenu()
{
    cout << "Main Menu\n";

    cout << "\n    1- New Polynomial"
         << "\n    2- Load from text file"
         << "\n    3- Load from binary file"
         << "\n    4- Quit\n";
}

/*This function is requird when need to get Polynomial from input
it takes a string 
turn it to Polynomial 
and see if this is exactly the Polynomial trying to enter*/
Polynomial getPolyFromInput()
{

    char isItCorrect;
    Polynomial poly;
    cout << "Enter a polynomial :";
    cin.ignore();
    cin >> poly;
    poly.sortPoly();

    cout << "Is This correct[ " << poly << " ] ? (y/n) : ";
    cin >> isItCorrect;
    if (isItCorrect == 'y' || isItCorrect == 'Y')
    {
        return poly;
    }
    else
    {
        cout << "Oh no!\nPerhaps an unexpected error occurred...";
        getch();
        system("cls");
        cout << "Please try another polynomial...\n";
        poly = getPolyFromInput();
    }
    return poly;
}

/*Adds a Polynomial to our Polynomial*/
void addPoly(Polynomial &myPolynomial)
{
    Polynomial addingPoly = getPolyFromInput();
    cout << "[ " << myPolynomial << " ] + [ " << addingPoly << " ] = [ ";
    myPolynomial = myPolynomial + addingPoly;
    cout << myPolynomial << " ]";
}

/*Subtract a Polynomial from our Polynomial*/
void subPoly(Polynomial &myPolynomial)
{
    Polynomial subPoly = getPolyFromInput();
    cout << "[ " << myPolynomial << " ] - [ " << subPoly << " ] = [ ";
    myPolynomial = myPolynomial - subPoly;
    cout << myPolynomial << " ]";
}

/*Multiply a Polynomial to our Polynomial*/
void mulPoly(Polynomial &myPolynomial)
{
    Polynomial mulPoly = getPolyFromInput();
    cout << "[ " << myPolynomial << " ] * [ " << mulPoly << " ] = [ ";
    myPolynomial = myPolynomial * mulPoly;
    cout << myPolynomial << " ]";
}

/*Finds Derivative of our Polynomial and put it in our Polynomial*/
void derPoly(Polynomial &myPolynomial)
{
    cout << "[ " << myPolynomial << " ] => [ ";
    myPolynomial = ~myPolynomial;
    cout << myPolynomial << " ]";
}

/*Shows degree of our Polynomial*/
void degPoly(Polynomial &myPolynomial)
{
    cout << "Polynomial : " << myPolynomial << endl;
    cout << "Degree : " << myPolynomial.degPoly();
}

/*Find the result if Ploynomial for a number as x*/
void findValuePoly(Polynomial &myPolynomial)
{
    float numVal;
    cout << "Enter a number : ";
    cin >> numVal;
    cout << "Polynomial : " << myPolynomial << endl;
    cout << "Value : " << numVal << endl;
    cout << "Result : " << myPolynomial(numVal);
}

/*This is used to print in compare function*/
void printTrueOrFalse(bool val)
{
    if (val == true)
    {
        cout << "True\n";
    }
    else
    {
        cout << "False\n";
    }
}

/*Compare 2 Polynomial*/
void comparePoly(Polynomial &myPolynomial)
{
    bool trueOrFalse;
    Polynomial comPoly = getPolyFromInput();
    myPolynomial.sortPoly();
    comPoly.sortPoly();
    cout << "\nCurrent_Polynomial = " << myPolynomial << endl;
    cout << "Other_Polynomial = " << comPoly << endl;
    cout << "\nComparing Current_Polynomial with Other_Polynomial\n"
         << endl;
    cout << "Current_Polynomial > Other_Polynomial:";
    trueOrFalse = (myPolynomial > comPoly);
    printTrueOrFalse(trueOrFalse);
    cout << "Current_Polynomial >= Other_Polynomial:";
    trueOrFalse = (myPolynomial >= comPoly);
    printTrueOrFalse(trueOrFalse);
    cout << "Current_Polynomial < Other_Polynomial:";
    trueOrFalse = (myPolynomial < comPoly);
    printTrueOrFalse(trueOrFalse);
    cout << "Current_Polynomial <= Other_Polynomial:";
    trueOrFalse = (myPolynomial <= comPoly);
    printTrueOrFalse(trueOrFalse);
    cout << "Current_Polynomial == Other_Polynomial:";
    trueOrFalse = (myPolynomial == comPoly);
    printTrueOrFalse(trueOrFalse);
}

/*For saving in txt file*/
void saveToText(Polynomial &myPolynomial)
{
    string fileName;
    cout << "Enter file name : ";
    cin >> fileName;
    ofstream fout(fileName, ios::trunc);
    if (fout)
    {
        cout << "Saving..." << endl;
        //    fout << "t\n";
        fout << myPolynomial << endl;
        fout.close();
        Sleep(1000);
        cout << "saved to file!";
    }
    else
    {
        throw 11;
    }
}

/*Turns Polynomial to string cause its easier to witer and read for binary file*/
string to_string(Polynomial p)
{
    ostringstream ss;
    ss << p;
    return ss.str();
}
/*Saves to binary file
first turn it to string then put it into file*/
void saveToBin(Polynomial &myPolynomial)
{
    string myPolynomialString = to_string(myPolynomial);
    getch();
    string fileName;
    cout << "Enter file name : ";
    cin >> fileName;
    ofstream fout(fileName, ios::binary | ios::trunc);
    if (fout)
    {
        cout << "Saving..." << endl;
        int size1 = (myPolynomialString.size());
        myPolynomial.s = size1;
        fout.write((char *)&size1, sizeof(int));
        fout.write(myPolynomialString.c_str(), size1);
        fout.close();
        Sleep(1000);
        cout << "saved to file!";
    }
    else
    {
        throw 11;
    }
}

/*This is operation menu for our Polynomial
all error will be catch in here*/
void showPolynomialMenu(Polynomial &myPolynomial)
{
    try
    {
        myPolynomial.sortPoly();
        int choice;
        cout << "\nPolynomial Menu\n";
        cout << "\nCurrent Polynomial = " << myPolynomial << endl;

        cout << "\n1- Add"
                "\n2- Subtract"
             << "\n3- Multiply"
             << "\n4- Derivative"
             << "\n5- Find Degree"
             << "\n6- Find Value for specific x"
             << "\n7- Compare"
             << "\n8- Save to a text file"
             << "\n9- Save to a binary file"
             << "\n10-      Back to Main Menu" << endl;
        cout << "\nYour choice:";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system("cls");
            cout << "---------ADD---------\n";
            addPoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 2:
            system("cls");
            cout << "-------SUBTRACT-------\n";
            subPoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 3:
            system("cls");
            cout << "-------MULTIPLY-------\n";
            mulPoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 4:
            system("cls");
            cout << "-------DERIVATIVE-------\n";
            derPoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 5:
            system("cls");
            cout << "-------DEGREE-------\n";
            degPoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 6:
            system("cls");
            cout << "------FIND VALUE------\n";
            findValuePoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 7:
            system("cls");
            cout << "------COMPARE------\n";
            comparePoly(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 8:
            system("cls");
            cout << "----SAVE TO TXT----\n";
            saveToText(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 9:
            system("cls");
            cout << "----SAVE TO BIN----\n";
            saveToBin(myPolynomial);
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        case 10:
            system("cls");
            break;
        default:
            cout << "Invalid input! try again...";
            getch();
            system("cls");
            showPolynomialMenu(myPolynomial);
            break;
        }
    }
    catch (int ex)
    {
        cacthFunction(ex);
        showPolynomialMenu(myPolynomial);
    }
}
 
/*This will takes us to operation menu for Polynomial*/
void newFile(Polynomial &myPolynomial)
{
    showPolynomialMenu(myPolynomial);
}

/*This function gets a file name for txt files
trying to open it
if open,
takes the Polynomial from it*/
void loadFromTextFile(Polynomial &myPolynomial)
{
    char correct;
    string fileName;
    Polynomial tmp;
    cout << "Enter file name : ";
    cin >> fileName;

    ifstream fin(fileName, ios::in);
    if (fin)
    {
        fin >> tmp;
        fin.close();
    }
    else
    {
        throw 1;
    }
    cout << "Is This correct[ " << tmp << " ] ? (y/n) : ";
    cin >> correct;
    if (correct == 'y' || correct == 'Y')
    {

        myPolynomial = tmp;
        showPolynomialMenu(myPolynomial);
    }
    else
    {
        throw 2;
    }
}

/*This function gets a file name for binary
trying to open it
if open,
takes a string from it
turn it ti Polynomial
save it to current Polynomial*/
void loadFromBinaryFile(Polynomial &myPolynomial)
{
    char correct;
    string fileName;
    string myPolynomialString;

    cout << "Enter file name : ";
    cin >> fileName;
    int size1;
    char *buf;

    ifstream fin(fileName, ios::binary | ios::in);
    if (fin)
    {
        fin.read(reinterpret_cast<char *>(&size1), sizeof(int));
        buf = new char[size1];
        fin.read(buf, size1);
        myPolynomialString = "";
        myPolynomialString.append(buf, size1);
    }
    else if (!fin.good())
    {
        cout << "Error occurred at reading time!" << endl;
    }
    else
    {
        throw 1;
    }
    cout << "Is This correct[ " << myPolynomialString << " ] ? (y/n) : ";
    cin >> correct;
    if (correct == 'y' || correct == 'Y')
    {

        myPolynomial = divideStringIntoPolynomial(myPolynomialString);
        showPolynomialMenu(myPolynomial);
    }
    else
    {
        throw 2;
    }
}
/*This is file menu 
all error of reading or writing of file is catched here*/
void chooseFromFileMenu(Polynomial &thePolynomial)
{
    try
    {
        int chooseFromMenu;
        char want_to_exit;
        cout << "\nYour choice:";
        cin >> chooseFromMenu;
        switch (chooseFromMenu)
        {
        case 1:
            system("cls");
            newFile(thePolynomial);
            showFileMenu();
            chooseFromFileMenu(thePolynomial);
            break;
        case 2:
            system("cls");
            loadFromTextFile(thePolynomial);
            showFileMenu();
            chooseFromFileMenu(thePolynomial);
            break;
        case 3:
            system("cls");
            loadFromBinaryFile(thePolynomial);
            showFileMenu();
            chooseFromFileMenu(thePolynomial);
            break;
        case 4:
            system("cls");
            cout << "All unsaved data will be lost" << endl;
            cout << "Are you sure you want to exit ? (y/n) ";
            cin >> want_to_exit;
            if (want_to_exit == 'y' || want_to_exit == 'Y')
            {
                cout << "Have a great day!";
                getch();
            }
            else
            {
                cout << "Ok!...";
                getch();
                system("cls");
                showFileMenu();
                chooseFromFileMenu(thePolynomial);
            }
            break;
        default:
            cout << "Invalid input! try again...";
            getch();
            system("cls");
            showFileMenu();
            chooseFromFileMenu(thePolynomial);
            break;
        }
    }
    catch (int ex)
    {
        cacthFileFunction(ex);
        getch();
        system("cls");
        showFileMenu();
        chooseFromFileMenu(thePolynomial);
    }
}