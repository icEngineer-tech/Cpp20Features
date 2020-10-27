
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
concept UnsignedInt = std::is_same_v<T, unsigned int>;// && sizeof(T) == sizeof(unsigned int); //or std::is_unsigned_v<T>

#endif
