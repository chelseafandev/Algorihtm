#include "permutation.h"

namespace pns
{
permutation::permutation(const permutation::type_of_n& n, unsigned int size_of_n, unsigned int r) : n_(n), size_of_n_(size_of_n), r_(r)
{

}

permutation::~permutation()
{

}

permutation::type_of_result permutation::make_permutation()
{
    permutation::type_of_result result;
    recursive_call_for_permutation(0, result);
    return result;
}

void permutation::recursive_call_for_permutation(unsigned int depth, permutation::type_of_result& result)
{
    if (r_ == depth)
    {
        result.push_back(n_);
        return;
    }

    for (int i = depth; i < size_of_n_; ++i)
    {
        std::swap(n_[i], n_[depth]);
        recursive_call_for_permutation(depth + 1, result);
        std::swap(n_[i], n_[depth]);
    }

    return;
}
}