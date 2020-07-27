#include <iostream>
#include <array>
#include <span>
#include <algorithm>

template<typename T, size_t N>
constexpr auto contains(std::span<T, N> data, int a)
{
	auto res = std::find(data.begin(), data.end(), a);
	return res;
}

int main()
{
	std::array<int,5>v{ 1,9,30,4,5 };
	std::span<int,5> my_span{ v };
	my_span[2] = 7;
	for (auto i : v)
		std::cout << i << " ";
	auto res = contains(my_span, 7);
	if (res != my_span.end())
		std::cout << "The value is in the conatainer! and the value is: " << *res;
	else
		std::cout << "Doesn't exist";

	return 0;
}
