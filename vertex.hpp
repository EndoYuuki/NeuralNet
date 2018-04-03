#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "MyVector.hpp"

namespace yy_net
{

template <typename T, class Activate>
class Vertex
{
public:
    T run(const MyVector<T>& in)
    {
        return Activate::f(
                    yy_net::inner_product(
                        weight_.begin(), weight_.end(),
                        in.begin(),
                        bias_)
                );
    }
private:
    MyVector<T> weight_;
    T bias_;
};

class EqActivate
{
public:
    template <typename T>
    static T f(const T in)
    {
        return in;
    }
};
}

#endif