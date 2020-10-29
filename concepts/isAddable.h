#ifndef ISADDABLE_H
#define ISADDABLE_H
#include <type_traits>


template<typename T>
concept regular = std::is_arithmetic_v<T> || is_alphabetic<T>;
template <class From, class To>
concept convertible_to =
std::is_convertible_v<From, To> &&
requires(std::add_rvalue_reference_t<From>(&f)()) {
	static_cast<To>(f());
};
template<typename T>
concept is_alphabetic = std::is_same_v<T, std::string>;
template<typename T>
concept is_same = std::is_same_v<T,T>;
template<typename T >
concept isAddable =  regular<T> && requires (T x, T y)
{
	{x + y}->is_same<>;
	{x + y}->convertible_to<T>;
};
/*
Example
//outside main()
  template<isAddable T>
  T add(T a, T b)
  {
    return a+b;
  }
  //inside main()
  std::cout << add(std::string("Hi"), std::string(" there"));
  */
#endif
