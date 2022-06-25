#include <iostream>
#include <iterator>

template < typename T1>
void sort(T1 it_first, T1 it_last)	// this sorts the elements of the array in ascending order
{

	it_last--;
	while (it_first != it_last)
	{
		int i = 0;
		while (it_last != it_first)
		{
			if (*it_first > *it_last)
			{
				std::iter_swap(it_first, it_last);
			}
			it_last--;
			i++;
		}
		std::advance(it_last, i);
		it_first++;
	}
}

template < typename T>
void Print(T my_contener)
	{
		for (auto it_first = my_contener.begin(); it_first != my_contener.end(); ++it_first)
			std::cout << ' ' << *it_first;
		std::cout << std::endl;
	}