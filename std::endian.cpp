#include <bit>        // std::endian is in bit library
#include <iostream>

int main()
{
	std::cout << int( std::endian::native );	// std::endian::native equals std::endian::little (0) then scalar types are little-endian
	return 0;
}
