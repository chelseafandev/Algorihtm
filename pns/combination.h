#include <iostream>
#include <vector>

namespace pns
{
class combination
{
    using type_of_n = std::vector<int>;
    using type_of_result = std::vector<std::vector<int>>;

public:
    combination(const type_of_n& n, unsigned int size_of_n, unsigned int r);
    ~combination();

    type_of_result make_combination();

private:
    void recursive_call_for_combination(unsigned int start, type_of_n& v, type_of_result& result);

    type_of_n n_;
    unsigned int size_of_n_;
    unsigned int r_;
};
}