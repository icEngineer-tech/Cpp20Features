
#ifndef SIGNEDANDUNSIGNEDINT_H
#define SIGNEDANDUNSIGNEDINT_H
#include <type_traits>

/*
* Signed Int
*/
template<typename T>
concept SignedInt = std::is_same_v<T, signed int>; //or std::is_signed_v<T>

/*
* Unsigned Int 
*/
template<typename T>
concept UnsignedInt = requires
{
	std::is_same_v<T, unsigned int>; //or std::is_unsigned_v<T>
};

#endif
