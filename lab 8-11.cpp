// lab 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Telefon.h"
#include "SerializerSerie.h"
#include "SerializerUser.h"
#include "RepoTemplate.h"
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileHTML.h"
#include "Service.h"
#include "UI.h"
#include "Tests.h"
using namespace std;


int main()
{
    cout << "start... ";
    tests();
    cout << "all tests are OK";
    cout << endl;
    SerializerSerie* s = new SerializerSerie();
    SerializerUser* u = new SerializerUser();
    RepoFileHTML<Serie*>repoh("Tests.html", s);
    RepoFile<User*>repo("Users.txt", ' ', u);
    Service serv(repoh, repo);
    UI ui(serv);
    ui.showMenu();
    return 0;
}

