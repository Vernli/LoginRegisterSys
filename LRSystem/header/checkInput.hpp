#pragma once
#include <map>
#include <string>
#include <iostream>

class ChInput {
public:
	ChInput();
	void insertToVerify(std::string key);
	void CheckInput(std::string to_check, bool specials = true, bool additional = false, bool is_email = false);
private:
	const std::string alphabet;
	std::map<std::string, std::string> to_validate;
};