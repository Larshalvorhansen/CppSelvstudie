// Lecture 5, Example 3 - Bart Iver van Blokland

#include "std_lib_facilities.h"

enum class CoffeeType {
	DARK, CAPPUCCINO, ESPRESSO
};

void prepareDarkCoffee() {
	std::cout << "**Coffee dripping intensifies**" << std::endl;
}

void prepareCappuccino() {
	// Don't judge.
	prepareDarkCoffee();
	std::cout << "Milk splashes" << std::endl;
}

void prepareEspresso() {
	std::cout << "Lots of steamy noises" << std::endl;
}

void prepareCoffee(CoffeeType coffeeType) {
	if(coffeeType == CoffeeType::DARK) {
		prepareDarkCoffee();
	} else if(coffeeType == CoffeeType::CAPPUCCINO) {
		prepareCappuccino();
	} else if(coffeeType == CoffeeType::ESPRESSO) {
		prepareEspresso();
	}
}

int main() {
	prepareCoffee(CoffeeType::DARK);
	return 0;
}