#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>
#include "MyVector.hpp"
#include "vertex.hpp"
#include <iostream>

namespace yy_net
{
	template <typename T>
	class LayerBase
	{
	public:
		virtual MyVector<T> feedforward(const MyVector<T>& prev) = 0;
	private:
	};

	template <typename T, typename Activate>
	class Layer : public LayerBase<T>
	{
	public:
		Layer(unsigned numOutput,
			const std::vector<unsigned>& connectionTable)
		{
			// todo
			prevOut2inputTable_ = connectionTable;
		}
		MyVector<T> feedforward(const MyVector<T>& prev)
		{
			MyVector<T> tmp;
			for (unsigned i = 0; i < prev.size(); i++)
			{
				std::cout << "t : " << i << std::endl;
				tmp.push_back(vertecies_[prevOut2inputTable_[i]].run(prev));
			}
			return tmp;
		}
	private:
		std::vector<Vertex<T, Activate>> vertecies_;
		std::vector<unsigned> prevOut2inputTable_;
	};
}

#endif