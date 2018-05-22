#include <iostream>
#include "list.hpp"
#include <initializer_list>
#define deb_s true

int main( int argc, char **argv ){
	std::cout << ">> Driver code started sucessfully!" << std::endl;
	std::cout << ">> Attempting to create a list()..." << std::endl;
	int Vet[] = { 1, 2, 3 ,4, 8, 8, 8, 8, 8 };

	std::initializer_list<int> mylist;
	mylist = { 10, 20, 30 };

	sc::list<int> test( std::begin(Vet), std::end(Vet) );
	sc::list<int> test3( mylist );
	test3 = {3, 2, 5, 10, 22};
	for (auto &i : test3){
		std::cout << i << std::endl;
	}
	return 0;
}
