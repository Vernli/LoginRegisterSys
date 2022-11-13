#pragma once
#include <iostream>
#include <vector>
#include <string>

class Menu {
public:
	Menu(int size);
	Menu(int size, std::vector<std::string> v_menu, bool verify=false);
	Menu(Menu const& other);
	~Menu() = default;

	std::vector<std::string> verificatorInputs;

	void addElement(std::string element);
	void showContent();
	int setInput();
	int getInput();
	void setToVerify();

	int getMenuLength();
	int getMenuElementLength(uint16_t pos);

private:
	std::vector<std::string> menu;

	int menu_size;
	int input;
	
	bool verify = false;
};


