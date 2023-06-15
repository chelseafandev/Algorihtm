#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int days = 0;
    int sequence = 0;
    std::cin >> days;
    std::cin >> sequence;

    // 구간 합은 입력 값을 받을 때부터 미리 구해둔다!
    std::vector<int> prefix_sums;
    int tmp_sum = 0;
    for (int i = 0; i < days; ++i)
    {
        int tmp = 0;
        std::cin >> tmp;
        tmp_sum += tmp;
        prefix_sums.push_back(tmp_sum);
    }

    int result = prefix_sums[sequence - 1];
    for (int i = 1; i < days - sequence + 1; ++i)
    {
        result = std::max(result, prefix_sums[i + sequence - 1] - prefix_sums[i - 1]);
    }

    std::cout << result << std::endl;

    return 0;
}