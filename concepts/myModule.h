#include "SignedAndUnsignedInt.h"
#include <stdexcept>

template<typename T>
concept is_integer = SignedInt<T> || UnsignedInt<T>;

enum class Odd{Odd,Even};
template <typename T>
bool isOdd(T x) 
{
	if constexpr (is_integer<T>) 
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
