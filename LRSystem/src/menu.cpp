#include "../header/menu.hpp"

Menu::Menu(int size) : menu_size(size) {
	menu.reserve(menu_size);
}

// if size of menu == size of inputs
Menu::Menu(int size, std::vector<std::string> v_menu) : menu_size(size), menu(v_menu){	
	if (size < menu.size()) {
		throw std::out_of_range("Too many elements | Inserted size is higher than amount of element inside v_menu parameter");
	}
}

Menu::Menu(const Menu& other) : menu(other.menu), menu_size(other.menu_size) {};

Menu &Menu::operator=(const Menu& menu) {
	Menu temp(menu);
	std::swap(*this, temp);
	return *this;
}
void Menu::addElement(std::string element) {
	menu.push_back(element);

	if (menu.size() > menu_size) {
		throw std::out_of_range("Too many elements");
	}
}

void Menu::showContent() {
	for (auto& el : menu) {
		std::cout << el << std::endl;
	}
}

int Menu::setInput() { // Take input from user and check if its number
	std::string temponary;
	std::cout << "#: ";
	std::cin >> temponary;
	if (temponary.length() > 1) {	// Don't expect 2 decimal number
		return -1;
	}
	
	if (temponary[0] < 48 || temponary[0] > 58) {	// Check the number is not in ASCII number range
		return -1;
	}
	else {
		input = temponary[0] - 48;	// -48 give a INT number
		return 1;
	}
}

int Menu::getInput() {
	return input;
}


int Menu::getMenuLength() {
	return menu.size();
}

int Menu::getMenuElementLength(uint16_t pos) {
	return menu[pos].length(); 
}