#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <vector>

namespace yy_net
{
	template <class Iterator1, class Iterator2, class T>
	T inner_product(Iterator1 first1, Iterator1 last1,
					Iterator2 first2, T init)
	{ 
		while (first1 != last1)
		{
			init = init + (*first1++ * *first2++);
		}
		return init;
	}

	template <typename T>
	class MyVector : private std::vector<T>
	{
	public:
		using std::vector<T>::vector;
		using std::vector<T>::begin;
		using std::vector<T>::end;
		using std::vector<T>::push_back;
		using std::vector<T>::size;

	private:
	};
}

#endif