#include <iostream>
#include <string>
#include "max-ol.hpp"
int main()
{
    std::cout << "max(f1,f2,f3): " << ::max(7, 42, 68) << std::endl;     // calls the template for three arguments
    std::cout << "max<double>(f1,f2): " << ::max(7.0, 42.0) << std::endl;     // calls max<double> (by argument deduction)
    std::cout << "max<char>(f1,f2): " << ::max('a', 'b') << std::endl;      // calls max<char> (by argument deduction)
    std::cout << "max(f1,f2): " << ::max(7, 42) << std::endl;         // calls the nontemplate for two ints
    std::cout << "max<>(f1,f2): " << ::max<>(7, 42) << std::endl;       // calls max<int> (by argument deduction)
    std::cout << "max<double>(f1,f2): " << ::max<double>(7, 42) << std::endl; // calls max<double> (no argument deduction)
    std::cout << "max(f1,f2): " << ::max('a', 42.7) << std::endl;     // calls the nontemplate for two ints
	std::cin.get();
}