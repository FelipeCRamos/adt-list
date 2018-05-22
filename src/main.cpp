#include <iostream>
#include "list.hpp"
#include <initializer_list>
#define deb_s true

int main( int argc, char **argv ){
	std::cout << ">> Driver code started sucessfully!" << std::endl;
	std::cout << ">> Attempting to create a list()..." << std::endl;

	sc::list<int> test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	sc::list<int> test33 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	

	sc::list<int> test2 = { 1, 8, 3, 4, 5, 6, 0, 8, 1, 10 };



	std::cout << "Print teste" << std::endl;
	for( auto &i : test ){
		std::cout << i << " ";
	}
	std::cout << std::endl;

	// operations here
	test.pop_front();
	test.assign(99);

	std::cout << "Segundo Print teste" << std::endl;
	for( auto &i : test ){
		std::cout << i << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
