#include "../header/checkInput.hpp"

ChInput::ChInput() : alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890"), numbers("01234567890"), email_chars("-_@.") {}

void ChInput::toValidateClear() {
	to_validate.clear();
}

void ChInput::insertToVerify(std::string key) {
	std::string value;
	std::cin.ignore();	// Ignore new line from last cin
	std::getline(std::cin, value);	// Read spaces
	to_validate[key] = value;
}

void ChInput::CheckInput(std::string to_check_key, bool specials, bool space, std::string without, bool is_email, bool only_numb) {
	if (only_numb) {
		if (to_validate[to_check_key].find_first_not_of(numbers) != std::string::npos) {
			throw std::invalid_argument("There should be a number " + to_check_key + "!");
		}
	}

	if (specials) {
		if (to_validate[to_check_key].find_first_not_of(alphabet + without) != std::string::npos) {
			throw std::invalid_argument("There are specials character inside " + to_check_key + "!");
		}
	}

	if (is_email) {
		if ((to_validate[to_check_key].find_first_not_of(alphabet + email_chars) != std::string::npos)) {
				throw std::invalid_argument("There is invalid character inside " + to_check_key + "!");
			}
	}


	if (space) {
		if (to_validate[to_check_key].find(' ') != std::string::npos) {
			throw std::invalid_argument("There is space inside "+ to_check_key + "!");
		}
	}

	if (is_email) {
		
	}
}

std::string ChInput::getToValidate(std::string key) {
	return to_validate[key];
}
