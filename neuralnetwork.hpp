#ifndef NEURAL_NETWORK_HPP
#define NEURAL_NETWORK_HPP

#include <memory>
#include <utility>
#include "layer.hpp"

namespace yy_net
{

template <typename T>
class NeuralNetwork
{
public:
	NeuralNetwork()
	{}
	template <typename U>
	void add(U&& layer)
	{
		layers_.push_back(
			std::make_shared<typename std::remove_reference<U>::type>(
				std::forward<U>(layer)));
	}
	MyVector<T> forwardPropagate(const MyVector<T>& in)
	{
		MyVector<T> tmp = in;
		for (auto& layer: layers_)
		{
			tmp = layer->feedforward(tmp);
		}
		return tmp;
	}
private:
	std::vector<std::shared_ptr<LayerBase<T>>> layers_;
};
}

#endif