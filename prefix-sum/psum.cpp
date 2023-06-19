#include <iostream>
#include <vector>

int make_range_sum(const std::vector<int>& ps, int i, int j)
{
    int j_p_s = ps[j - 1];
    int i_p_s = i == 1 ? 0 : ps[i - 2];
    return j_p_s - i_p_s;
}

int main()
{
    int N = 8;
    int M = 3;
    std::vector<int> cards = {1, 2, 3, 4, 5, 6, 7, 8};
    
    // make prefix sum
    int tmp = 0;
    std::vector<int> prefix_sum;
    for (const auto& card : cards)
    {
        tmp += card;
        std::cout << "[make prefix sum] add `" << tmp << "`" << std::endl;
        prefix_sum.push_back(tmp);
    }

    std::cout << "range(1, 4) : " << make_range_sum(prefix_sum, 1, 4) << std::endl;
    std::cout << "range(1, 5) : " << make_range_sum(prefix_sum, 1, 5) << std::endl;
    std::cout << "range(3, 5) : " << make_range_sum(prefix_sum, 3, 5) << std::endl;

    return 0;
}