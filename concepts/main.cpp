#if defined (_MSVC_LANG) && (_MSVC_LANG)<201704L
#error enable C++20 because this project contains Concepts
#endif
#include "SignedInt.h"
#include <iostream>

template<typename T>
concept Integer = SignedInt<T>;


int main()
{
	std::cout << std::boolalpha;
	std::cout << Integer<unsigned>;
	//std::cout << SignedInt<signed>::value;
	return 0;
}
