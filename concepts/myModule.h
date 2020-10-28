#ifndef MYMODULE_H
#define MYMODULE_H

#include "SignedAndUnsignedInt.h"
#include <stdexcept>

template<typename T>
concept is_integer = SignedInt<T> || UnsignedInt<T>;

enum class Odd{Odd,Even};
template <typename T>
bool isOdd(T x)
{
	if constexpr (is_integer<T>) [[likely]] 	/*constexpr is primordial here otherwise, you will get an error: C2296 % illegal, left operand hat type T
					                 for instance, if T is double then % doesn't work for this type. constexpr make that if is computed at compile 
					                 time. is_integer<> is a concept then it's computed at compile time*/
	{
		if (x % 2)
			return true;
		return false;
	}
	throw std::exception();
}
/*
* get oddity
*/
template <typename T>
Odd getOddity(T x)
{
	try { if (isOdd(x)) return Odd::Odd; return Odd::Even; }
	catch (const std::exception& e) { std::cout << e.what(); }
}

#endif
