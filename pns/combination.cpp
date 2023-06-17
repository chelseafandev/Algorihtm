#include "combination.h"

namespace pns
{
combination::combination(const combination::type_of_n& n, unsigned int size_of_n, unsigned int r) : n_(n), size_of_n_(size_of_n), r_(r)
{

}

combination::~combination()
{

}

combination::type_of_result combination::make_combination()
{
    combination::type_of_result result;
    combination::type_of_n v;
    recursive_call_for_combination(0, v, result);
    return result;
}

void combination::recursive_call_for_combination(unsigned int start, combination::type_of_n& v, combination::type_of_result& result)
{
    if (v.size() == r_)
    {
        result.push_back(v);
        return;
    }

    for (int i = start; i < size_of_n_; ++i)
    {
        v.push_back(n_[i]);
        recursive_call_for_combination(i + 1, v, result);
        v.pop_back();
    }

    return;
}
}