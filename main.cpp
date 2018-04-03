#include "vertex.hpp"
#include "neuralnetwork.hpp"
#include "layer.hpp"
#include "MyVector.hpp"

int main(int argc, char* argv[])
{
	yy_net::NeuralNetwork<float> n;
	std::vector<unsigned> connectionTable({0, 1});
	n.add(yy_net::Layer<float, yy_net::EqActivate>(1, connectionTable));
	yy_net::MyVector<float> vec({1, 2, 3});
	n.forwardPropagate(vec);
	return 0;
}