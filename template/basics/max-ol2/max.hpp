
#include <iostream>
// maximum of two values of any type
template <typename T>
inline T const& max (T const& a, T const& b)
{
    return  a < b  ?  b : a;
}

// maximum of two pointers
template <typename T>
inline T* const& max (T* const& a, T* const& b)
{
	//std::cout << "b:" << b << std::endl;
	//std::cout << "a:" << a << std::endl;
	//std::cout << "*b:" << *b << std::endl;
	//std::cout << "*a:" << *a << std::endl;

    return  *a < *b  ?  b : a;
}

// maximum of two C-strings
inline char const* const& max (char const* const& a,
                               char const* const& b)
{ 
    return  std::strcmp(a,b) < 0  ?  b : a;
}