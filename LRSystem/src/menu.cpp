#include "../header/menu.hpp"

Menu::Menu(int size) : menu_size(size) {
	menu.reserve(menu_size);
}

// if size of menu == size of inputs
Menu::Menu(int size, std::vector<std::string> v_menu, bool verify_) : menu_size(size), menu(v_menu), verify(verify_) {	
	if (size < menu.size()) {
		throw std::out_of_range("Too many elements | Inserted size is higher than amount of element inside v_menu parameter");
	}
}

Menu::Menu(const Menu& other) : menu(other.menu), menu_size(other.menu_size) {};

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

int Menu::setInput() {
	std::string temponary;
	std::cout << "#: ";
	std::cin >> temponary;
	if (temponary.length() > 1) {
		return -1;
	}
	
	if (temponary[0] < 48 || temponary[0] > 58) {
		return -1;
	}
	else {
		input = temponary[0] - 48;
		return 1;
	}
}

int Menu::getInput() {
	return input;
}

void Menu::setToVerify() {
	if (verify) {
		std::string temp;
		std::cin >> temp;
		verificatorInputs.push_back(temp);
	}
		
}

int Menu::getMenuLength() {
	return menu.size();
}

int Menu::getMenuElementLength(uint16_t pos) {
	return menu[pos].length(); 
}