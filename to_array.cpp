// convert a C_Style array into the new Cpp_Style array (the container of STL)

#include <iostream>
#include <array>

//---------------------------------------------------------- (2)
template<typename T, std::size_t N, std::size_t...S>
consteval std::array<T, N>to_array_impl(T (&a)[N], std::index_sequence<S...>)
{
	return { { a[S]... } };
}

template<typename T, std::size_t N>
consteval std::array<T, N> to_array(T (&a)[N])
{
	return to_array_impl(a, std::make_index_sequence<N>());
}
//-----------------------------------------------------------
int main()
{
// this what the standard gives us  (1)
	int tab[5]{ 14,8,2,0,4 };
	std::array<int, 5> io = std::to_array(tab);
	for (auto i : io)
		std::cout << i << " ";
    
 // look at this beauty of C++ aha
  //same code can go here for (2)
	return 0;
}
