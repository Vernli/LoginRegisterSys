#include <iostream>
#include <Windows.h>
#include "../header/menu.hpp"
#include "../header/user.hpp"

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
	User* user = new User;
	system("cls");
	Menu* mainMenu = new Menu(3, { "1. Login", "2. Register", "0. Exit" });
	Menu* loginMenu = new Menu(2, { "Login:", "Password:" }, true);
	Menu* regiMenu = new Menu(7, { "Name:", "Last name:", "Age:", "E-mail", "Login:", "Password:", "Repeat password:" }, true);
	bool caseComplete = false;

	do {
		mainMenu->showContent();
		mainMenu->setInput();
		switch (mainMenu->getInput()) {
		case 1:
			system("cls");
			MessageBox(0, L"Login must be at least 5 characters long\nPassword be at least 8 characters long\n", L"Information", MB_OK);

			loginMenu->showContent();
			SetCurorPosition(loginMenu->getMenuElementLength(0), 0);
			loginMenu->setToVerify();	// Login
			SetCurorPosition(loginMenu->getMenuElementLength(1), 1);
			loginMenu->setToVerify();	// Password
			//check Correctness

			caseComplete = true;
			break;
		case 2:
			system("cls");
			regiMenu->showContent();

			SetCurorPosition(regiMenu->getMenuElementLength(0), 0);
			regiMenu->setToVerify();	// Name
			SetCurorPosition(regiMenu->getMenuElementLength(1), 1);
			regiMenu->setToVerify();	// Last name
			SetCurorPosition(regiMenu->getMenuElementLength(2), 2);
			regiMenu->setToVerify();	// Age
			SetCurorPosition(regiMenu->getMenuElementLength(3), 3);
			regiMenu->setToVerify();	// E-mail
			SetCurorPosition(regiMenu->getMenuElementLength(4), 4);
			regiMenu->setToVerify();	// Login
			SetCurorPosition(regiMenu->getMenuElementLength(5), 5);
			regiMenu->setToVerify();	// Password
			SetCurorPosition(regiMenu->getMenuElementLength(6), 6);
			regiMenu->setToVerify();	// Password check
			//check Correctness

			caseComplete = true;
			break;
		case 3:
			
		case 0:
			exit(0);
		default:
			system("cls");
			MessageBox(0, L"Inserted value is incorrect", L"Invalid", MB_OK);
			break;
		}
	} while (!caseComplete);
}