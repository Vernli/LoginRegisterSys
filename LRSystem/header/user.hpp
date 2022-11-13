#pragma once
#include <string>
#include "person.hpp"

class User : Person
{
public:
	User() :balance(0), accNumber(0) {};
	User(std::string login_, std::string password_);
	User(const User& other);
	~User() = default;

	void setName(std::string name_) { name=name_; }
	void setLastName(std::string last_name_) { last_name = last_name_; }
	void setAge(int age_) { age = age_; }
	void setEmail(std::string email_) { email = email_; }
	void setLogin(std::string login_) { login = login_; }
	void setPassword(std::string password_) { password = password_; }

	void ShowInfo();

private:
	std::string email;
	std::string login;
	std::string password;
	double balance;
	int accNumber;
};

