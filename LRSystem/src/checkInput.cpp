#include "../header/checkInput.hpp"

ChInput::ChInput() : alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890") {}

void ChInput::insertToVerify(std::string key) {
	std::string value;
	std::cin >> value;
	to_validate[key] = value;
}

void ChInput::CheckInput(std::string to_check_key, bool specials, bool additional, bool is_email) {
	if (specials) {
		if (to_validate[to_check_key].find_first_not_of(alphabet) != std::string::npos) {
			std::cerr << "There are specials character inside string !";
			return;
		}
	}
}
