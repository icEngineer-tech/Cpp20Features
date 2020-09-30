#include <iostream>
#include <compare>
#include <numeric>

template <class T, std::enable_if_t<std::is_floating_point_v<T> || std::is_integral_v<T>, bool> = true>
class Point
{
	T x, y;
public:
	Point(T x, T y) { this->x = x; this->y = y; }
	std::strong_ordering operator<=>(const Point& p1)const
	{
		auto aveThis = std::midpoint(x, y); // (1) here I'm using midpoint(which is a feature of C++20 <numeric>) to get the average 
		auto aveExt = std::midpoint(p1.x, p1.y);// (2) of the current object(the idea behinds that is to only compare one param)
		return aveThis <=> aveExt;
		//auto comp1 = this->y <=> p1.y;	// you can use this instead of (1) and (2)
		//auto comp2= x <=> p1.x;
		/*if (res < 0)
			return std::strong_ordering::less;
		else if (res > 0)
			return std::strong_ordering::greater;
		else if (res == 0)
			return std::strong_ordering::equal;*/
	}

	friend std::ostream& operator<<(std::ostream& os, std::strong_ordering s);
};

std::ostream& operator<<(std::ostream& os, std::strong_ordering s)
{
	os << s;
	return os;
}
int main()
{

	Point p(1, 2);		//template deduction
	Point p2(2, 1);
	std::cout << std::boolalpha;
	std::cout << (p <= p2);

	return 0;
}
