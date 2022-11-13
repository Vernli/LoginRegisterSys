#include "../header/user.hpp"

User::User(std::string uLogin, std::string uPassword) : login(uLogin), password(uPassword) {};
User::User(User const& other) : login(other.login), password(other.password) {};

void User::ShowInfo() {
	std::cout << "Account Number: " << accNumber << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "E-mail: " << email << std::endl;
	std::cout << "Login: " << login << std::endl;
	std::cout << "Password: " << password << std::endl;
	std::cout << "Balance: " << balance << std::endl;
}