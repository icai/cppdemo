#include <iostream>
#include <cstring>
#include <string>
#include "max.hpp";

int main ()
{
    int a=7;
    int b=42;
    ::max(a,b);      // max() for two values of type int

    std::string s="hey";
    std::string t="you";
	std::cout << "max(s1,s2): " << ::max(s,t) << std::endl;      // max() for two values of type std::string

    int* p1 = &b;
    int* p2 = &a;
	std::cout << "max(s1,s2):" << ::max(p1,p2) << std::endl;    // max() for two pointers
	std::cout << "*max(s1,s2):" << *::max(p1,p2) << std::endl; // get value
    char const* s1 = "David";
    char const* s2 = "Nico";
	std::cout << "max(s1,s2):" << ::max(s1,s2) << std::endl;    // max() for two C-strings
	
	std::cin.get();
}
