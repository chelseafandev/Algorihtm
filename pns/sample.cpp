#include "permutation.h"
#include "combination.h"

void sample_permutation()
{
    std::vector<int> n = {1, 2, 3};
    pns::permutation perm(n, n.size(), 3);
    auto cases = perm.make_permutation();
    std::cout << "[permutation] number of cases : " << cases.size() << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (const auto& list : cases)
    {
        std::cout << "[ ";
        for (const auto& data : list)
        {
            std::cout << data << " ";
        }
        std::cout << "]" << std::endl;
    }
}

void sample_combination()
{
    std::vector<int> n = {1, 2, 3};
    pns::combination comb(n, n.size(), 2);
    auto cases = comb.make_combination();
    std::cout << "[combination] number of cases : " << cases.size() << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (const auto& list : cases)
    {
        std::cout << "[ ";
        for (const auto& data : list)
        {
            std::cout << data << " ";
        }
        std::cout << "]" << std::endl;
    }
}

int main()
{
    sample_permutation();
    std::cout << std::endl;
    
    sample_combination();
    return 0;
}