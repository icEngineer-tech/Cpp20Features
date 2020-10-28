#ifndef MYMODULE_H
#define MYMODULE_H

#include "SignedAndUnsignedInt.h"
#include <stdexcept>

template<typename T>
concept is_integer = SignedInt<T> || UnsignedInt<T>;

enum class Odd{Odd,Even};
template <typename T>
bool isOdd(T x);
/*
* get oddity
*/
template <typename T>
Odd getOddity(T x);

#endif
