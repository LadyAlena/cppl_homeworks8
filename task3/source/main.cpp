#include <iostream>
#include "unique_ptr/unique_ptr.hpp"

int main(int argc, char** argv) {

	pointer::unique_ptr<int> up(new int(5));

	std::cout << *up << std::endl;

	auto ptr = up.release();

	std::cout << *ptr << std::endl;

	return 0;
}