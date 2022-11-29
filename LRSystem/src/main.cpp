#include <iostream>
#include <Windows.h>
#include "../header/menu.hpp"
#include "../header/user.hpp"
#include "../header/checkInput.hpp"
#include "../header/database.hpp"

using namespace std;

void SpecialMessage(std::string msg) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
	cout << msg << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	cout << endl;
}

void SetCurorPosition(int row, int col) {
	COORD Cord;
	Cord.X = row+1;
	Cord.Y = col;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cord);
}

int main() {
	DataBase db;
	db.OpenDataBase("LoginRegisterSystem.db");
	db.CreateTable("AccInformation", "(ID INT NOT NULL PRIMARY KEY, login varchar(50), password varchar(128))");
	db.CreateTable("UserInforamtion", "(ID INT NOT NULL PRIMARY KEY, name varchar(50), last_name varchar(200), age INT, email varchar(255), login varchar(50), password varchar(128))"); // where
	
	system("cls");
	Menu* mainMenu = new Menu(3, { "1. Login", "2. Register", "0. Exit" });
	Menu* loginMenu = new Menu(2, { "Login:", "Password:" });
	Menu* regiMenu = new Menu(7, { "Name:", "Last name:", "Age:", "E-mail", "Login:", "Password:", "Repeat your password:" });

	User* user = new User;

	ChInput* checker = new ChInput;
	bool caseResolved = false;

	do {
		mainMenu->showContent();
		mainMenu->setInput();
		switch (mainMenu->getInput()) {
		case 1:
			system("cls");
			MessageBox(0, L"Login must be at least 5 characters long\nPassword be at least 8 characters long\n", L"Information", MB_OK);

			loginMenu->showContent();
			SetCurorPosition(loginMenu->getMenuElementLength(0), 0);
			checker->insertToVerify("Login");
			SetCurorPosition(loginMenu->getMenuElementLength(1), 1);
			checker->insertToVerify("Password");
			//check Correctness
			try {
				checker->CheckInput("Login", true, true);
				checker->CheckInput("Password", false, true);
			}
			catch (const exception &e) {
				cerr << e.what() << endl;
			}
			// default - check in db
			caseResolved = true;
			break;

		case 2:
			system("cls");
			regiMenu->showContent();

			SetCurorPosition(regiMenu->getMenuElementLength(0), 0);
			checker->insertToVerify("Name");

			SetCurorPosition(regiMenu->getMenuElementLength(1), 1);
			checker->insertToVerify("Last Name");

			SetCurorPosition(regiMenu->getMenuElementLength(2), 2);
			checker->insertToVerify("Age");

			SetCurorPosition(regiMenu->getMenuElementLength(3), 3);
			checker->insertToVerify("E-mail");


			SetCurorPosition(regiMenu->getMenuElementLength(4), 4);
			checker->insertToVerify("Login");

			SetCurorPosition(regiMenu->getMenuElementLength(5), 5);
			checker->insertToVerify("Password");

			SetCurorPosition(regiMenu->getMenuElementLength(6), 6);
			checker->insertToVerify("RepPassword");

			try {
				if (checker->getToValidate("Password") != checker->getToValidate("RepPassword")) {
					throw logic_error("Password doesn't match repeat password");
				}

				checker->CheckInput("Name", true, true); // ok
				checker->CheckInput("Last Name", true, false, "-'"); // ok can be space
				checker->CheckInput("Age", false, false, "", false, true);	// is dec
				checker->CheckInput("E-mail", false, false, "", true); // speciall allow _-@.
				checker->CheckInput("Login", true, true);	// ok
				checker->CheckInput("Password", true, true); // ok
			}
			catch (const exception &e){
				cerr << e.what() << endl;
			}
			//Insert to db
			string values = checker->getToValidate("Name") + ", " + checker->getToValidate("Last Name") + ", " + checker->getToValidate("Age") + ", " + checker->getToValidate("E-mail") + ", " + checker->getToValidate("Login") + ", " + checker->getToValidate("Password");
			db.InsertToDataBase("UserInformation", values);
			caseResolved = true;
			break;
		case 3:
			
		case 0:
			exit(0);
		default:
			system("cls");
			MessageBox(0, L"Inserted value is incorrect", L"Invalid", MB_OK);
			break;
		}
	} while (!caseResolved);
}