#if defined (_MSVC_LANG) && (_MSVC_LANG)<201704L
#error enable C++20 because this project contains Concepts
#endif
#include "SignedAndUnsignedInt.h"
#include <iostream>

template<typename T>
concept is_integer = SignedInt<T> || UnsignedInt<T>;


int main()
{
	std::cout << std::boolalpha;
	std::cout << is_integer<unsigned>;
	//std::cout << SignedInt<signed>::value;
	return 0;
}
