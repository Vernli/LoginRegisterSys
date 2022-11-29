#pragma once
#include <map>
#include <string>
#include <iostream>
#include <stdexcept>

class ChInput {
public:
	ChInput();
	void insertToVerify(std::string key);
	void toValidateClear();
	std::string getToValidate(std::string key);
	void CheckInput(std::string to_check, bool specials = true, bool space = false, std::string without = "", bool is_email = false, bool only_numb = false);
private:
	const std::string alphabet;
	const std::string numbers;
	const std::string email_chars;
	std::map<std::string, std::string> to_validate;
};