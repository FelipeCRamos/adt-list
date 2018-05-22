#include <iostream>
#include "list.hpp"

#define deb_s true

int main( int argc, char **argv ){
	std::cout << ">> Driver code started sucessfully!" << std::endl;

	std::cout << ">> Attempting to create a list()..." << std::endl;
	sc::list<int> test;
	for( int i = 0; i < 5; i++ ){
		test.push_back(i);
	}
	for (auto &i : test){
		std::cout << i << std::endl;
	}
	return 0;
}
