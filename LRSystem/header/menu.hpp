#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Menu {
public:
	Menu(int size);
	Menu(int size, std::vector<std::string> v_menu);
	Menu(Menu const& other);
	Menu& operator=(const Menu& menu);
	~Menu()=default;

	void addElement(std::string element);
	void showContent();
	int setInput();
	int getInput();

	int getMenuLength();
	int getMenuElementLength(uint16_t pos);

private:
	std::vector<std::string> menu;
	int menu_size;
	int input;
};


