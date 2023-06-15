#include <iostream>
#include <vector>
#include <algorithm>
#include "pns/combination.h"

int main()
{
    std::vector<int> nanjaengs;

    for (int i = 0; i < 9; ++i)
    {
        int height = 0;
        std::cin >> height;
        nanjaengs.push_back(height);
    }

    pns::combination ps(nanjaengs, nanjaengs.size(), 7);
    auto cases = ps.make_combination();
    
    std::vector<int> target_index;
    std::cout << "number of cases : " << cases.size() << std::endl;
    std::cout << "--------------------" << std::endl;
    for (const auto& list : cases)
    {
        unsigned int sum = 0;
        for (const auto& data : list)
        {
            sum += data;
        }

        if (sum == 100)
        {
            target_index = list;
            break;
        }

        sum = 0;
    }

    std::vector<int> result;
    for (const auto& data : target_index)
    {
        result.push_back(data);
    }

    std::sort(result.begin(), result.end());
    std::cout << "[ ";
    for (const auto& data : result)
    {
        std::cout << data << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}