#include "../header/person.hpp"

void Person::ShowInfo() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Age: " << age << std::endl;
}
